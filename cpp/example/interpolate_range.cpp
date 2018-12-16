#include "referencefunctions.h"
#include "interpolation.h"
#include "reader10.h"
#include <cmath>
#include <iostream>
#include <random>
#include <vtkCellData.h>
#include <vtkCellArray.h>
#include <vtkDoubleArray.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkVersion.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkXMLRectilinearGridWriter.h>
#include <vtkSmartPointer.h>
#include <vtkRectilinearGrid.h>
#include <omp.h>
#include <fstream>

int main(int argc, char** argv)
{
  if (argc < 8) {
    std::cout << "Incomplete args list" << std::endl <<"usage: interplorate_range x_start y_start x_end y_end x_dim y_dim zdata_filename" << std::endl; 
    return -1;
  }
  
  double x1 = atof(argv[1]); 
  double y1 = atof(argv[2]);
  double x2 = atof(argv[3]);
  double y2 = atof(argv[4]);
  int xCount = atoi(argv[5]);
  int yCount = atoi(argv[6]);
  const char* zdata = argv[7];
 
  double dx = ((x2 - x1) / xCount) ; 
  double dy = ((y2 - y1) / yCount) ; 
  std::vector<double> z_values;
  std::ifstream freader(zdata);
  if(freader.fail()) {
    std::cout<<"failed reading z_values file"<<std::endl;
  }
  double val;
  while(freader>>val){ 
    z_values.push_back(val);
  }

  size_t zCount = z_values.size();

  size_t total  = xCount * yCount * zCount;
  std::cout << "Resolution: " << xCount << " x "  << yCount << " x " << zCount << std::endl;
  std::cout << "DoF: " << total << std::endl;
  std::cout << "X0: " << x1 << " y0: " << y1 << " dx: " <<  dx << " dy: " << dy << std::endl;
  
  double _min[3] = {1000000.0, 1000000.0, 1000000.0};
  double _max[3] = {0.0      , 0.0      , 0.0      }; 
  
  vtkSmartPointer<vtkDoubleArray> xArray =
    vtkSmartPointer<vtkDoubleArray>::New();

  vtkSmartPointer<vtkDoubleArray> yArray =
    vtkSmartPointer<vtkDoubleArray>::New();

  vtkSmartPointer<vtkDoubleArray> zArray =
    vtkSmartPointer<vtkDoubleArray>::New();

  bool visualize = true;

  double xx = x1;
  for (int i = 0; i < xCount; i++) {
    xArray->InsertNextValue(xx);
    xx+=dx;
  }
  
  double yy = y1;
  for (int i = 0; i < yCount; i++) {
    yArray->InsertNextValue(yy);
    yy+=dy;
  }

  for (int i = 0; i < zCount; i++) {
    zArray->InsertNextValue(z_values[i]);
  }
 vtkSmartPointer<vtkRectilinearGrid> grid =
    vtkSmartPointer<vtkRectilinearGrid>::New();
  grid->SetDimensions(xCount, yCount, zCount);
  grid->SetXCoordinates(xArray);
  grid->SetYCoordinates(yArray);
  grid->SetZCoordinates(zArray);
  
  vtkSmartPointer<vtkDoubleArray> normalsArray =
      vtkSmartPointer<vtkDoubleArray>::New();
  normalsArray->SetNumberOfComponents(3); //3d normals (ie x,y,z)
  normalsArray->SetNumberOfTuples(grid->GetNumberOfPoints());
  
  vtkSmartPointer<vtkDoubleArray> scalarsArray =
      vtkSmartPointer<vtkDoubleArray>::New();
  scalarsArray->SetNumberOfComponents(1); //3d normals (ie x,y,z)
  scalarsArray->SetNumberOfTuples(grid->GetNumberOfPoints());

for(int i = 0; i < 10; ++i) {
#pragma omp parallel for 
    for(vtkIdType id = 0; id < grid->GetNumberOfPoints(); id++) {
      double pcurr[3];
      grid->GetPoint(id, pcurr);
      Point p(pcurr[0],pcurr[1], pcurr[2]);
      double norm[3] = {sfu[i](p).fun,sfv[i](p).fun, sfw[i](p).fun};
      double c[1] = {sfcharac[i](p).fun};
      normalsArray->SetTuple(id, norm) ;
      scalarsArray->SetTuple(id, c);
    }
    grid->GetPointData()->SetNormals(normalsArray);
    //add the normals to the cells in the grid
    grid->GetPointData()->SetScalars(scalarsArray);
  
  
    // Write the file
    vtkSmartPointer<vtkXMLRectilinearGridWriter> writer =
      vtkSmartPointer<vtkXMLRectilinearGridWriter>::New();
    std::string filename = "snapshot_" + std::to_string(i+1)+"_" + std::to_string(xCount)+"_"+std::to_string(yCount)+"_"+std::to_string(zCount)+".vtr";
    writer->SetFileName(filename.c_str());
  #if VTK_MAJOR_VERSION <= 5
    writer->SetInput(grid);
  #else
    writer->SetInputData(grid);
  #endif
  
    // Optional - set the mode. The default is binary.
  //  writer->SetDataModeToBinary();
  //  writer->SetDataModeToAscii();
  
    writer->Write();
    std::cout << "Done writing to file: " <<filename << std::endl;
}
  return 0;
}

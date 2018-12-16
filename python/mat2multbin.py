"""
Converting matlab velocity files to raw binary files.
"""
import numpy as np
from scipy.io import matlab
import sys
length = len(sys.argv)
if(length == 1):
  length = 1
else: 
  length = int(sys.argv[1])

for filenum in range(1,length+1):
  matfile = matlab.loadmat('snapshot'+str(filenum)+'.mat')
  dx = matfile['DeltaX']
  dy = matfile['DeltaY']
  zc = matfile['ZC']

  u = matfile['UCenter']
  v = matfile['VCenter']
  w = matfile['WCenter']

  charac = np.where(np.isnan(u), -1.0, 1.0)
  
  print(dx, dy)
  print(zc.T)
  i = 487
  j = 67
  k = 19
  print(u[i, j, k], v[i, j, k], w[i, j, k])
  print(u.shape)
  
  u.tofile('../tmp/u'+str(filenum)+'.bin')
  v.tofile('../tmp/v'+str(filenum)+'.bin')
  w.tofile('../tmp/w'+str(filenum)+'.bin')
  zc.tofile('../tmp/z'+str(filenum)+'.bin')
  charac.tofile('../tmp/charac'+str(filenum)+'.bin')


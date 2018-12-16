include_directories(./include)

set(oceaninterp_src
    src/scalarfield.cpp
    src/interpolation.cpp
    src/referencefunctions.cpp)

add_library(oceaninterpolation SHARED ${oceaninterp_src})
target_link_libraries(oceaninterpolation yaml-cpp)

add_executable(interpolate example/interpolate.cpp)
target_link_libraries(interpolate oceaninterpolation yaml-cpp)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(interpolate_range example/interpolate_range.cpp)
target_link_libraries(interpolate_range oceaninterpolation yaml-cpp ${VTK_LIBRARIES})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()



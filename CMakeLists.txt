cmake_minimum_required(VERSION 3.0)
project(oceaninterpolation)

option(BUILD_TESTING "Build tests" OFF)
if(BUILD_TESTING)
  enable_testing()

  add_subdirectory("/Users/giraldl/softwares/googletest"
      "${CMAKE_CURRENT_BINARY_DIR}/gtest_build")
  include_directories(${GTEST_INCLUDE_DIRS})
endif()

set(CMAKE_CXX_FLAGS "-fopenmp -O3 -std=c++11 -pthread")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# find_package(Eigen3 REQUIRED)
# include_directories("${EIGEN3_INCLUDE_DIR}")
include_directories("/home/albarass/RedSeaInterpolation/eigen3")



# set(homebrew_prefix /Users/giraldl/local)
# include_directories("${homebrew_prefix}/include")
# link_directories("${homebrew_prefix}/lib")

add_subdirectory(cpp)
add_subdirectory(wrapper)
add_subdirectory(wrapper10)
file(COPY yaml_files DESTINATION cpp)


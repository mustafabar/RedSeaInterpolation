include_directories("${CMAKE_SOURCE_DIR}/cpp/include")
add_library(wrapper10 SHARED wrapper.cpp wrappercclibql.c)
target_link_libraries(wrapper10 oceaninterpolation yaml-cpp)

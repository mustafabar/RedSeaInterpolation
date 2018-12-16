include_directories("${CMAKE_SOURCE_DIR}/cpp/include")
add_library(wrapper SHARED wrapper.cpp wrappercclibql.c)
target_link_libraries(wrapper oceaninterpolation yaml-cpp)

add_executable(test_scalarfield test_scalarfield.cpp)
target_link_libraries(test_scalarfield
    oceaninterpolation yaml-cpp gtest gtest_main)
add_test(NAME test_scalarfield COMMAND test_scalarfield
    ${CMAKE_CURRENT_LIST_DIR}/test_scalarfield_u.yaml
    ${CMAKE_CURRENT_LIST_DIR}/test_scalarfield_v.yaml
    ${CMAKE_CURRENT_LIST_DIR}/test_scalarfield_w.yaml
    ${CMAKE_SOURCE_DIR}/tmp/u.bin
    ${CMAKE_SOURCE_DIR}/tmp/v.bin
    ${CMAKE_SOURCE_DIR}/tmp/w.bin
    ${CMAKE_SOURCE_DIR}/tmp/z.bin)

add_executable(test_interpolation test_interpolation.cpp)
target_link_libraries(test_interpolation
    oceaninterpolation yaml-cpp gtest gtest_main)
add_test(NAME test_interpolation COMMAND test_interpolation)

add_executable(test_referencefunctions test_referencefunctions.cpp)
target_link_libraries(test_referencefunctions
    oceaninterpolation yaml-cpp gtest gtest_main)
add_test(NAME test_referencefunctions COMMAND test_referencefunctions)

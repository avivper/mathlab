add_executable(
        test_mathlab
        include/matlab_test/algebra_test/complex_test/test_complex_getters.h
        mathlab/algebra/complex/test_complex.cpp
        include/matlab_test/algebra_test/complex_test/test_complex_self_pm_operators.h
        include/matlab_test/algebra_test/complex_test/test_complex_to_string.h
        mathlab/algebra/complex/test_complex/test_to_complex_to_string.cpp
        include/matlab_test/algebra_test/complex_test/test_complex_self_mult.h
        mathlab/algebra/complex/test_complex/test_complex_self_mult.cpp
)

target_link_libraries(test_mathlab
        PRIVATE
        mathlab_lib
)

target_include_directories(test_mathlab
        PUBLIC
        ${PROJECT_SOURCE_DIR}/tests/include
)


add_test(NAME test_mathlab COMMAND test_mathlab)
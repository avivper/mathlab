#include <matlab_test/algebra_test/complex_test/test_complex.h>

/// ### Main test ### ///

// test complex abs
void testing_complex_abs() {
    test_complex_abs::print_test_abs();
    for (unsigned int i = 0; i < COMPLEX_ABS_TESTS; i++) {
        try {
            test_complex_abs::test_complex_abs_arr[i](i);
        } catch (const std::logic_error &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

// test complex getters
void testing_complex_getters() {
    test_complex_getters::print_test_getters();
    for (unsigned int i = 0; i < COMPLEX_GETTERS_TESTS; i++) {
        try {
            test_complex_getters::test_complex_getters_arr[i](i);
        } catch (const std::logic_error &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

// test complex +=,-= complex operators
void testing_complex_pm_operators() {
    test_pm_complex_operators::print_test_pm();
    for (unsigned int i = 0; i < COMPLEX_SELF_PM_OPERATORS_TESTS; i++) {
        try {
            test_pm_complex_operators::test_complex_self_pm_operators_arr[i](i);
        } catch (const std::logic_error &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

// test *= with complex operator
void testing_complex_self_mult_operator() {
    test_self_mult_complex_operator::print_test_self_mult();
    for (unsigned int i = 0; i < COMPLEX_SELF_MULT_TESTS; i++) {
        try {
            test_self_mult_complex_operator::test_self_mult_operator_arr[i](i);
        } catch (const std::logic_error &e) {
            std::cout << e.what() << std::endl;
        }
    }
}


// test complex to string
void testing_complex_to_string() {
    test_complex_to_string::print_test_to_string();
    for(unsigned int i = 0; i < COMPLEX_ABS_TESTS; i++) {
        try {
            test_complex_to_string::complex_to_string_arr[i](i);
        } catch (const std::logic_error &e) { // todo: check if valid and correct
            std::cout << e.what() << std::endl;
        }
    }
}
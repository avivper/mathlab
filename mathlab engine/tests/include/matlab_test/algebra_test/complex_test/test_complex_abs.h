#ifndef TEST_COMPLEX_ABS_H
#define TEST_COMPLEX_ABS_H

#define COMPLEX_ABS_TESTS 4

namespace test_complex_abs {
    void print_test_abs();

    void test_real_case(unsigned int test_i); // only real case
    void test_double_case(unsigned int test_i); // testing basic double numeric case
    void test_minus_case(unsigned int test_i); // some of the part is minus
    void test_imag_case(unsigned int test_i); // testing only imag part

    inline void (*test_complex_abs_arr[COMPLEX_ABS_TESTS])(unsigned int) = {
        test_real_case,
        test_double_case,
        test_minus_case,
        test_imag_case
    };
}


#endif //TEST_COMPLEX_ABS_H

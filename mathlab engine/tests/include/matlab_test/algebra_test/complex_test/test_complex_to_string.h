#ifndef TEST_COMPLEX_STRING_H
#define TEST_COMPLEX_STRING_H

#define COMPLEX_TO_STRING_TESTS 7

namespace test_complex_to_string {
    void print_test_to_string();

    // real
    void to_string_real_plus_test(unsigned int test_i); // a
    void to_string_real_minus_test(unsigned int test_i); // -a

    // imag
    void to_string_imag_plus_test(unsigned int test_i); // bi
    void to_string_imag_minus_test(unsigned int test_i); // -bi

    // complex
    void to_string_real_and_imag_plus_test(unsigned int test_i); // a + bi
    void to_string_real_and_imag_minus_test(unsigned int test_i); // a - bi
    void to_string_zero_test(unsigned int test_i); // 0

    inline void (*complex_to_string_arr[COMPLEX_TO_STRING_TESTS])(unsigned int) = {
        to_string_real_plus_test,
        to_string_real_minus_test,
        to_string_imag_minus_test,
        to_string_imag_minus_test,
        to_string_real_and_imag_plus_test,
        to_string_real_and_imag_minus_test,
        to_string_zero_test
    };
}

#endif //TEST_COMPLEX_STRING_H

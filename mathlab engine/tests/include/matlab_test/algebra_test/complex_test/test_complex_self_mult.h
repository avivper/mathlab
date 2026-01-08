#ifndef TEST_COMPLEX_SELF_MULT_H
#define TEST_COMPLEX_SELF_MULT_H

#define COMPLEX_SELF_MULT_TESTS 6

namespace test_self_mult_complex_operator {
    void print_test_self_mult();

    // z * z
    void test_squared(unsigned int test_i);

    // i * i = -1
    void i_squared(unsigned int test_i);

    // z * 1
    void test_mul_with_zero(unsigned int test_i);

    // z * 0
    void test_mul_with_one(unsigned int test_i);

    // (a + bi) * a
    void test_mul_with_real(unsigned int test_i);

    // (a + bi) * di
    void test_mul_with_imag(unsigned int test_i);

    // z *= w
    void test_mul_with_complex(unsigned int test_i);

    inline void (*test_self_mult_operator_arr[COMPLEX_SELF_MULT_TESTS])(unsigned int) = {
        test_squared,
        test_mul_with_zero,
        test_mul_with_one,
        test_mul_with_real,
        test_mul_with_imag,
        test_mul_with_complex
    };
}

#endif //TEST_COMPLEX_SELF_MULT_H

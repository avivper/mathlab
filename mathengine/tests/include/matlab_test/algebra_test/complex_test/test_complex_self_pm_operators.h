#ifndef TEST_COMPLEX_SELF_PM_OPERATORS_H
#define TEST_COMPLEX_SELF_PM_OPERATORS_H

#define COMPLEX_SELF_PM_OPERATORS_TESTS 6

namespace test_pm_complex_operators {
    void print_test_pm();

    // +=
    void test_plus_equals_basic(unsigned int test_i);
    void test_plus_equals_chaining(unsigned int test_i);
    void test_plus_equals_self(unsigned int test_i);

    // -=
    void test_minus_equals_chaining(unsigned int test_i);
    void test_minus_equals_self(unsigned int test_i);
    void test_minus_equals_basic(unsigned int test_i);

    inline void (*test_complex_self_pm_operators_arr[COMPLEX_SELF_PM_OPERATORS_TESTS])(unsigned int) = {
        test_plus_equals_basic,
        test_plus_equals_chaining,
        test_plus_equals_self,
        test_minus_equals_chaining,
        test_minus_equals_self,
        test_minus_equals_basic
    };
}



#endif //TEST_COMPLEX_SELF_PM_OPERATORS_H

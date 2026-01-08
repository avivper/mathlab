#ifndef TEST_COMPLEX_GETTERS_H
#define TEST_COMPLEX_GETTERS_H

#define COMPLEX_GETTERS_TESTS 1

namespace test_complex_getters {
    void print_test_getters();
    void test_complex_getters(unsigned int test_i);

    inline void(*test_complex_getters_arr[COMPLEX_GETTERS_TESTS])(unsigned int) = {
        test_complex_getters
    };
}

#endif //TEST_COMPLEX_GETTERS_H

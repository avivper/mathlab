#ifndef UTIL_H
#define UTIL_H

#include <mathengine/algebra/complex.h>

// Global
namespace util {
    void start_test(unsigned int test_i);
    void test_finished(unsigned int test_i);
}

// Complex
namespace complex_util {
    void print_complex(unsigned int test_i, const Complex& z);
    void test_abs(unsigned int test_i, const Complex& z, double abs);
    void print_complex_parts(unsigned int test_i, double r, double i);
}

#endif //UTIL_H

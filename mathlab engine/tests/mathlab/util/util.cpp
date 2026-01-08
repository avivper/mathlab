#include <matlab_test/util.h>

// Global
void begin_test_complex(const unsigned int test_i) {
    std::cout << "Test " << test_i  << "begin" << std::endl;
    std::cout << std::endl;
}

void test_finished(const unsigned int test_i) {
    std::cout << "Test " << test_i  << "finished" << std::endl;
    std::cout << std::endl;
}

// Complex
void print_test_complex(const unsigned int test_i, const Complex& z) {
    std::cout << z << std::endl;
    std::cout << std::endl;
    util::test_finished(test_i);
}

void test_abs(const unsigned int test_i,const Complex& z, const double abs) {
    std::cout << z << std::endl;
    std::cout << std::endl;
    std::cout << "abs: " << abs << std::endl;
    std::cout << std::endl;
    util::test_finished(test_i);
}

void print_complex_parts(const unsigned int test_i, const double r, const double i) {
    std::cout << "real: " << r << std::endl;
    std::cout << "imag: " << i << std::endl;
    test_finished(test_i);
}
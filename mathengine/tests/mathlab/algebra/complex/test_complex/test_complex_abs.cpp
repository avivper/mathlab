#include <matlab_test/algebra_test/complex_test/test_complex_abs.h>
#include <matlab_test/util.h>

void test_complex_abs::print_test_abs() {
    std::cout << "### Testing abs's complex ###" << std::endl;
    std::cout << std::endl;
}

void test_complex_abs::test_real_case(const unsigned int test_i) {
    util::start_test(test_i);
    std::cout << "Testing real case" << std::endl;
    std::cout << std::endl;
    const Complex z(2.0, 0.0);
    const double abs = z.abs();
    if (abs != 2) {
        throw std::logic_error("Test failed on line 16");
    }
    complex_util::test_abs(test_i, z, abs);
}

void test_complex_abs::test_imag_case(const unsigned int test_i) {
    util::start_test(test_i);
    std::cout << "Testing abs imag case" << std::endl;
    std::cout << std::endl;
    const Complex z(0.0, 2.0);
    const double abs = z.abs();
    if (abs != 2) {
        throw std::logic_error("Test failed on line 28");
    }
    complex_util::test_abs(test_i, z, abs);
}

void test_complex_abs::test_double_case(const unsigned int test_i) {
    util::start_test(test_i);
    std::cout << "Testing abs double case" << std::endl;
    std::cout << std::endl;
    const Complex z(2.5, 7.20);
    const double abs = z.abs();
    const double actual_abs = std::sqrt(2.5 * 2.5 + 7.20 * 7.20);
    if (abs != actual_abs) {
        throw std::logic_error("Test failed on line 41");
    }
    complex_util::test_abs(test_i, z, abs);
}

void test_complex_abs::test_minus_case(const unsigned int test_i) {
    util::start_test(test_i);
    std::cout << "Testing abs minus case" << std::endl;
    std::cout << std::endl;
    const Complex z(4, -3);
    const double abs = z.abs();
    if (abs != 5) {
        throw std::logic_error("Test failed on line 53");
    }
    complex_util::test_abs(test_i, z, abs);
}
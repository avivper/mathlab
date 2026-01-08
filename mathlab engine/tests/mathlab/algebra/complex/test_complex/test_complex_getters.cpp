#include <matlab_test/algebra_test/complex_test/test_complex_getters.h>
#include <matlab_test/util.h>

void test_complex_getters::print_test_getters() {
    std::cout << "### Testing getters's complex ###" << std::endl;
    std::cout << std::endl;
}

void test_complex_getters::test_complex_getters(const unsigned int test_i) {
    util::start_test(test_i);
    const Complex z(1.0, 2.0);
    const double real = z.get_real();
    const double imag = z.get_imag();
    complex_util::print_complex_parts(test_i, real, imag);
}
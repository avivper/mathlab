#include <matlab_test/util.h>
#include <matlab_test/algebra_test/complex_test/test_complex_self_mult.h>

void test_self_mult_complex_operator::print_test_self_mult() {
    std::cout << "### Testing *= operator's complex ###" << std::endl;
    std::cout << std::endl;
}

// todo:
void test_self_mult_complex_operator::test_squared(const unsigned int test_i) {
    util::start_test(test_i);
}

void test_self_mult_complex_operator::test_mul_with_zero(const unsigned int test_i) {
    util::start_test(test_i);
    Complex a(3.5, 16.13);
    const Complex zero(0, 0);
    a *= zero;
    if (!a.is_zero()) {
        throw std::logic_error("Test Failed on line 20");
    }
    complex_util::print_complex(test_i, a);
}

void test_self_mult_complex_operator::test_mul_with_one(const unsigned int test_i) {
    util::start_test(test_i);
    Complex a(3.5, 16.13);
    const Complex one(1, 1);
    a *= one;
    if (a.get_real() != 3.5 || a.get_imag() != 16.13) {
        throw std::logic_error("Test Failed on line 32");
    }
    complex_util::print_complex(test_i, a);
}

// todo:
void test_self_mult_complex_operator::test_mul_with_real(const unsigned int test_i) {
    util::start_test(test_i);
}

// todo:
void test_self_mult_complex_operator::test_mul_with_imag(const unsigned int test_i) {
    util::start_test(test_i);
}

// todo:
void test_self_mult_complex_operator::test_mul_with_complex(const unsigned int test_i) {
    util::start_test(test_i);
}

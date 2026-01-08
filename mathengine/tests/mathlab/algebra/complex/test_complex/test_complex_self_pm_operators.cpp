#include <matlab_test/algebra_test/complex_test/test_complex_self_pm_operators.h>
#include <matlab_test/util.h>


void test_pm_complex_operators::print_test_pm() {
    std::cout << "### Testing self +,- operators's complex ###" << std::endl;
    std::cout << std::endl;
}

// +=
void test_pm_complex_operators::test_plus_equals_basic(const unsigned int test_i) {
    util::start_test(test_i);
    Complex a(1.0, 2.0);
    const Complex b(3.0, -5.0);
    a += b;
    if (a.get_real() != 4) {
        throw std::logic_error("Test Fails: line 11");
    }
    if (a.get_imag() != -3) {
        throw std::logic_error("Test Fails: line 14");
    }
    complex_util::print_complex(test_i, a);
}

void test_pm_complex_operators::test_plus_equals_chaining(const unsigned int test_i) {
    util::start_test(test_i);
    Complex a(1.0, 1.0);
    Complex b(2.0, 3.0);
    const Complex c(4.0, -1.0);
    // b += c happens first, then a += b
    a += (b += c);
    if (b.get_real() != 6.0) {
        throw std::logic_error("Test Fails: line 27");
    }
    if (b.get_imag() != 2.0) {
        throw std::logic_error("Test Fails: line 30");
    }
    std::cout << "b: " << b << std::endl;
    std::cout << std::endl;
    if (a.get_real() != 7.0) {
        throw std::logic_error("Test Fails: line 36");
    }
    if (a.get_imag() != 3.0) {
        throw std::logic_error("Test Fails: line 39");
    }
    std::cout << "a: " << std::endl;
    complex_util::print_complex(test_i, a);
}

void test_pm_complex_operators::test_plus_equals_self(const unsigned int test_i) {
    util::start_test(test_i);
    Complex a(2.5, -1.5);
    a += a;
    if (a.get_real() != 5.0) {
        throw std::logic_error("Test Fails: line 50");
    }
    if (a.get_imag() != -3.0) {
        throw std::logic_error("Test Fails: line 53");
    }
    std::cout << "a: " << std::endl;
    complex_util::print_complex(test_i, a);
}

// -=
void test_pm_complex_operators::test_minus_equals_basic(const unsigned int test_i) {
    util::start_test(test_i);
    Complex a(1.0, 2.0);
    const Complex b(3.0, -5.0);
    a -= b;
    if (a.get_real() != -2) {
        throw std::logic_error("Test Fails: line 66");
    }
    if (a.get_imag() != 7) {
        throw std::logic_error("Test Fails: line 69");
    }
    complex_util::print_complex(test_i, a);
}

void test_pm_complex_operators::test_minus_equals_chaining(const unsigned int test_i) {
    util::start_test(test_i);

    Complex a(10.0, 10.0);
    Complex b(3.0, 4.0);
    const Complex c(1.0, -2.0);

    a -= (b -= c);
    if (b.get_real() != 2.0) {
        throw std::logic_error("Test Fails: line 83");
    }
    if (b.get_imag() != 6.0) {
        throw std::logic_error("Test Fails: line 86");
    }
    std::cout << "b: " <<  b << std::endl;
    std::cout << std::endl;
    if (a.get_real() != 8.0) {
        throw std::logic_error("Test Fails: line 92");
    }
    if (a.get_imag() != 4.0) {
        throw std::logic_error("Test Fails: line 95");
    }
    complex_util::print_complex(test_i, a);
}

void test_pm_complex_operators::test_minus_equals_self(const unsigned int test_i) {
    util::start_test(test_i);
    Complex a(2.5, -1.5);
    a -= a;
    if (a.get_real() != 0.0 || a.get_imag() != 0.0) {
        std::cout << "Test Fails: line 127" << std::endl;
    }
    complex_util::print_complex(test_i, a);
}

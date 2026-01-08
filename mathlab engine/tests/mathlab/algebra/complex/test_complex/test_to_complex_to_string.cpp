#include <matlab_test/algebra_test/complex_test/test_complex_to_string.h>
#include <matlab_test/util.h>

void test_complex_to_string::print_test_to_string() {
    std::cout << "### Testing to_string's complex ###" << std::endl;
    std::cout << std::endl;
}

// real

void test_complex_to_string::to_string_real_plus_test(const unsigned int test_i) {
    util::start_test(test_i);
    std::cout << "Testing real plus case" << std::endl;
    std::cout << std::endl;
    const Complex r(5.3, 0);
    const std::string real = r.to_string();
    if (real != "5.3") {
        std::cout << "The Number is: " << real << std::endl;
        throw std::logic_error("Test failed on line 14");
    }
    std::cout << "The Number is: " << real << std::endl;
    std::cout << std::endl;
    util::test_finished(test_i);
}

void test_complex_to_string::to_string_real_minus_test(const unsigned int test_i) {
    util::start_test(test_i);
    std::cout << "Testing real minus case" << std::endl;
    std::cout << std::endl;
    const Complex r(-5.3, 0);
    const std::string real = r.to_string();
    if (real != "-5.3") {
        std::cout << "The Number is: " << real << std::endl;
        throw std::logic_error("Test failed on line 31");
    }
    std::cout << "The Number is: " << real << std::endl;
    std::cout << std::endl;
    util::test_finished(test_i);
}


// imag

void test_complex_to_string::to_string_imag_plus_test(const unsigned int test_i) {
    util::start_test(test_i);
    std::cout << "Testing imaginary plus case" << std::endl;
    std::cout << std::endl;
    const Complex r(0, 3.14);
    const std::string imag = r.to_string();
    if (imag != "3.14") {
        std::cout << "The Number is: " << imag << std::endl;
        throw std::logic_error("Test failed on line 45");
    }
    std::cout << "The Number is: " << imag << std::endl;
    std::cout << std::endl;
    util::test_finished(test_i);
}

void test_complex_to_string::to_string_real_and_imag_minus_test(const unsigned int test_i) {
    util::start_test(test_i);
    std::cout << "Testing real and imaginary minus case" << std::endl;
    std::cout << std::endl;
    const Complex r(0, -3);
    const std::string real = r.to_string();
    if (real != "-3") {
        std::cout << "The Number is: " << real << std::endl;
        throw std::logic_error("Test failed on line 66");
    }
    std::cout << "The Number is: " << real << std::endl;
    std::cout << std::endl;
    util::test_finished(test_i);
}

// complex
void test_complex_to_string::to_string_real_and_imag_plus_test(const unsigned int test_i) {
    util::start_test(test_i);
    std::cout << "Testing real and imaginary plus case" << std::endl;
    std::cout << std::endl;
    const Complex r(1, 2);
    const std::string number = r.to_string();
    if (number != "1+2i") {
        std::cout << "The Number is: " << number << std::endl;
        throw std::logic_error("Test failed on line 83");
    }
    std::cout << "The Number is: " << number << std::endl;
    std::cout << std::endl;
    util::test_finished(test_i);
}

void test_complex_to_string::to_string_imag_minus_test(const unsigned int test_i) {
    util::start_test(test_i);
    std::cout << "Testing imaginary minus case" << std::endl;
    std::cout << std::endl;
    const Complex r(1, -3);
    const std::string number = r.to_string();
    if (number != "1-3i") {
        std::cout << "The Number is: " << number << std::endl;
        throw std::logic_error("Test failed on line 98");
    }
    std::cout << "The Number is: " << number << std::endl;
    std::cout << std::endl;
    util::test_finished(test_i);
}



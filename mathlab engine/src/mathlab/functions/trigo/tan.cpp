#include <mathlab/functions/trigo/tan.h>
#include <mathlab/core/numeric.h>
#include <mathlab/functions/functions.h>

// tan
Tan::Tan(const double t) : _sin(t), _cos(t), _theta(t) {
    if (_cos.is_zero()) {
        throw std::invalid_argument("tan is undefined: cos is zero");
    }
}

double Tan::operator()() const {
    if (_cos.is_zero()) {
        throw std::invalid_argument("tan is undefined: cos is zero");
    }
    return _sin() / _cos();
}

std::string Tan::to_string() const noexcept {
    return "tan(" + numeric::convert_num_to_string(_theta) + ")";
}

// cot, cot := 1/ tan
Cot::Cot(const double t) : _sin(t), _cos(t), _theta(t) {
    if (_sin.is_zero()) {
        throw std::invalid_argument("cot is undefined: sin is zero");
    }
}

double Cot::operator()() const {
    if (_sin.is_zero()) { // safety guard
        throw std::invalid_argument("cot is undefined: sin is zero");
    }
    return _cos() / _sin();
}

std::string Cot::to_string() const noexcept {
    return "cot(" + numeric::convert_num_to_string(_theta) + ")";
}

// arctan, tan^-1, the inverse function of tan
Arctan::Arctan(const double t) : _theta(t) {}

double Arctan::operator()() const noexcept {
    if (_theta < 0.0) {
        return -arctan_taylor(-_theta);
    }
    if (_theta > 1.0) {
        return numeric::PI / 2.0 - arctan_taylor(1/_theta);
    }
    return arctan_taylor(_theta);
}

double Arctan::arctan_taylor(const double t) noexcept {
    double sum_element = t;
    double taylor_sum = sum_element;
    unsigned int k = 0; // sun index
    const double theta_squared = t * t;
    // arctan(x) = ∞ Σᵢ₌₀ ((x²ⁿ⁺1) / (2n+1))
    while (numeric::taylor_iterations(sum_element, k)) {
        ++k;
        const double denominator = 2.0 * k + 1.0; // (2n + 1)
        const double numerator = (-1.0) * sum_element * theta_squared * (2.0 * k - 1.0);
        sum_element = numerator / denominator;
        taylor_sum += sum_element;
    }
    return taylor_sum;
}

std::string Arctan::to_string() const noexcept {
    return "arctan(" + numeric::convert_num_to_string(_theta) + ")";
}
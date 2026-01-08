#include <mathengine/functions/trigo/cos.h>
#include <mathengine/core/numeric.h>
#include <mathengine/functions/functions.h>

Cos::Cos(const double x) {
    _theta = x;
}

double Cos::operator()() const {
    double sum_element = 1.0;
    double taylor_sum = sum_element;
    const double theta_squared = _theta * _theta;
    unsigned int k = 0; // sum index

    // Taylor Series computed using Lagrange remainder
    // cos(x) = ∞ Σᵢ₌₀ ((x²ⁿ) / (2n!))
    while (numeric::taylor_iterations(sum_element, k)) {
        ++k;
        const double numerator = (-1.0) * sum_element * theta_squared;
        const double denominator = (2.0 * k - 1.0) * (2.0 * k);
        sum_element = numerator / denominator;
        taylor_sum += sum_element;
    }
    return taylor_sum;
}

bool Cos::is_zero() const noexcept {
    return functions::abs((*this)()) < numeric::EPSILON;
}

std::string Cos::to_string() const noexcept {
    std::string result = "cos(";
    result += numeric::convert_num_to_string(_theta);
    result += ")";
    return result;
}
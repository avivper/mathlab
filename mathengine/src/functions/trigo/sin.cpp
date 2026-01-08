#include <mathengine/functions/trigo/sin.h>
#include <mathengine/functions/functions.h>
#include <mathengine/core/numeric.h>

Sin::Sin(const double x) {
    _theta = x;
}

double Sin::operator()() const noexcept {
    double sum_element = _theta;
    double taylor_sum = sum_element;
    const double theta_squared = _theta * _theta;
    unsigned int k = 0; // sum index
    // sin(x) = ∞ Σᵢ₌₀ ((x²ⁿ⁺¹) / (2n+1!))
    while (numeric::taylor_iterations(sum_element, k)) {
        ++k;
        const double numerator = (-1.0) * sum_element * theta_squared * (2.0 * k - 1.0);
        const double denominator = (2.0 * k) * (2.0 * k + 1.0);
        sum_element = numerator / denominator;
        taylor_sum += sum_element;
    }
    return taylor_sum;
}

bool Sin::is_zero() const noexcept {
    return functions::abs((*this)()) < numeric::EPSILON;
}

std::string Sin::to_string() const noexcept{
    std::string result = "sin(";
    result += numeric::convert_num_to_string(_theta);
    result += ")";
    return result;
}

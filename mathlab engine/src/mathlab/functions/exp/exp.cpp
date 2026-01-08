#include <mathlab/functions/exp/exp.h>
#include <mathlab/core/numeric.h>
#include <mathlab/functions/functions.h>

/// Constructors ///
Exp::Exp() : _x(1.0), _z(_x,0.0), _sin(0.0), _cos(0.0) {}
Exp::Exp(const double x) : _x(x), _z(x,0.0),_sin(0.0), _cos(0.0) {}
Exp::Exp(const Complex &z) : _x(z.get_real()), _z(z), _sin(_z.arg()), _cos(_z.arg()) {}

/// Operators ///
// Complex Exp::cis() const noexcept { // e^(a+bi) = cis(t) = cos(t) + isin(t)
//     const double cos_part = Trigo::cos(_z.get_imag());();
//     const double sin_part = Trigo::sin(_z.get_imag())();
//     return Complex(cos_part, sin_part);
// }

double Exp::operator()() const noexcept {
    return exp_taylor(_x); // todo: finish with complex/real
}

/// Representations ///
std::string Exp::to_string() const noexcept {
    if (_z.is_zero()) {
        return "1"; // e⁰ = 1
    }
    std::string exp = "exp";
    exp += "(" + _z.to_string() + ")"; // z ∈ ℂ
    return exp;
}



double Exp::exp_taylor(const double x) noexcept { // todo: finish taylor with range reduced
    double sum_element = 1.0; // e⁰ = 1
    double taylor = sum_element;
    unsigned int k = 0; // sum index
    // eˣ = ∞ Σᵢ₌₀ ((xⁿ) / (n!))
    while (numeric::taylor_iterations(sum_element, k)) {
        ++k;
        const double denominator = k;
        const double numerator = x;
        sum_element *= numerator / denominator;
        taylor += sum_element;
    }
    return taylor;
}

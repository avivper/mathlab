#ifndef EXP_H
#define EXP_H

#include <mathlab/functions/trigo/trigo.h>
#include <mathlab/algebra/complex.h>
#include <mathlab/core/numeric.h>

class Exp { // todo: work with ln
public:
    /// Constructors ///
    Exp();
    explicit Exp(double x); // Real, eˣ
    explicit Exp(const Complex& z); // Complex, eᵏ, k ∈ ℂ

    /// Operators ///
    double operator()() const;

    // todo:
    // Complex cis() const noexcept;  // e^(a+bi) = cis(t) = cos(t) + isin(t)

    /// Representations ///
    std::string to_string() const noexcept;
private:
    double _x; // eˣ
    Complex _z; // eˣ⁺iy
    Sin _sin;
    Cos _cos;
    static double exp_taylor(double x) noexcept; // eˣ ∈ (0,∞)
};

#endif //EXP_H

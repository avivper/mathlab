#ifndef COMPLEX_H
#define COMPLEX_H

#include <mathengine/lib/io.h>

// todo:
// In other file/object:
// Exponential & Logarithmic Functions
// (exp, log, pow, sqrt)

// Trigonometric Functions
// sin, cos, tan, asin, acos, atan

/*
10. Error Handling
 ------------------
 - Division by zero protection
 - Logarithm of zero handling
 - Numerical stability considerations
 */

/*
- std::pair<double, double> toPolar() const;
- static Complex fromPolar(double r, double theta);
- std::string toString() const;
- std::string toStringPolar() const;
*/

/*
11. C++20 Integration
---------------------
- constexpr where applicable
- [[nodiscard]] on computational functions
- noexcept where guaranteed
- Optional std::hash specialization
*/


class Complex { // ℂ
public:
    /// Constructors ///
    // Default Constructors
    Complex();
    explicit Complex(double r); // explicit: avoid from the automatic casting from this constructor
    explicit Complex(double r, double i);

    // Getters
     double get_real() const;
     double get_imag() const;

    /// Arithmetic Operators ///

    // w = z (operator) scalar
    Complex operator+(double scalar) const noexcept;
    Complex operator-(double scalar) const noexcept;
    Complex operator*(double scalar) const noexcept;
    Complex operator/(double scalar) const;

    // Operators with scalars
    Complex& operator+=(double scalar) noexcept;
    Complex& operator-=(double scalar) noexcept;
    Complex& operator*=(double scalar) noexcept;
    Complex& operator/=(double scalar);

    // Unary
    Complex operator-() const noexcept; // -z = -(a+bi)

    // self-complex operators
    Complex& operator+=(const Complex& rhs) noexcept;
    Complex& operator-=(const Complex& rhs) noexcept;
    Complex& operator*=(const Complex& rhs) noexcept;
    Complex& operator/=(const Complex& rhs);

    // Complex-Complex
    // a + bi + c + di := (a + c) + (b+d)i
    Complex operator+(const Complex& rhs) const noexcept;
    // a + bi - (c + di) := (a - c) + (b - d)i
    Complex operator-(const Complex& rhs) const noexcept;
    //  (a+bi)(c+di) := (ac - bd) + (ad + bc)i
    Complex operator*(const Complex& rhs) const noexcept;
    // Can throw for division by zero
    // (a+bi)/(c+di) := (ac + bd)/c² + d² + (bc - ad)/c² + d²
    Complex operator/(const Complex& rhs) const;

    /// Logical Operators ///
    bool operator==(const Complex& rhs) const noexcept;
    bool operator!=(const Complex& rhs) const noexcept;

    /// Mathematical Methods ///
    // z ∈ ℂ, |z| = √a² + b², abs := modolus
    double abs() const noexcept;
    // z ∈ ℂ, conj(z) = a - bi
    Complex conj() const noexcept;
    // z^-1 if z != 0 => z^-1 =  a - bi / a² + b²
    Complex inverse() const;
    // Polar
    // z ∈ ℂ, if z = a + bi, Re(z),Im(z) != 0, arg(z) := arctan(b/a)
    // z ∈ ℝ\{0}, arg(z) = { π z < 0, 0 else
    // arg(0) is undefined => throws exception
    double arg() const;
    // z ∈ ℂ
    Complex polar_complex() const;

    /// Properties ///
    bool is_zero() const noexcept; // z = 0
    bool have_real_part() const noexcept; // ∃Re(z)
    bool have_complex_part() const noexcept; // ∃Im(z)
    bool is_real() const noexcept; // z ∈ ℝ
    bool is_imag() const noexcept; // Re(z) = 0, Im(z) != 0, z ∈ ℂ
    bool is_complex() const noexcept; // Re(z),Im(z) != 0, z ∈ ℂ

    /// Representations ///
    std::string to_string() const noexcept;
    std::string to_polar_string(bool expand_cis) const noexcept;

private:
    // Mathematical Methods
    // double angle() const;
    // Class fields
    double real;
    double imag;
    // static fields
    inline static const Complex ZERO{0.0,0.0};
    inline static const Complex ONE{1.0,0.0};
    inline static const Complex I{0.0,1.0};
};

// this namespace handle scalar (operator) complex
namespace complex_arithmetic {
   Complex operator+(double scalar, const Complex& rhs) noexcept; // scalar + z
   Complex operator-(double scalar, const Complex& rhs) noexcept; // scalar - z
   Complex operator*(double scalar, const Complex& rhs) noexcept; // scalar * z
   Complex operator/(double scalar, const Complex& rhs); // scalar / z
}

// Representations
std::ostream& operator<<(std::ostream& os, const Complex& rhs);

#endif //COMPLEX_H

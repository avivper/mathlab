#include <mathlab/algebra/complex.h>
#include <mathlab/functions/functions.h>
#include <mathlab/core/numeric.h>

/// Constructors ///
// Default Constructors
Complex::Complex() : real(0), imag(0) {}
Complex::Complex(const double r) : real(r), imag(0) {}
Complex::Complex(const double r, const double i) : real(r), imag(i) {}

// Getters
double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

/// Logical Operators ///
bool Complex::operator==(const Complex &rhs) const noexcept {
    return real == rhs.real && imag == rhs.imag;
}

bool Complex::operator!=(const Complex &rhs) const noexcept {
    return real != rhs.real || imag != rhs.imag;
}

/// Properties ///
bool Complex::is_zero() const noexcept {
    return real == 0 && imag == 0;
}

bool Complex::have_real_part() const noexcept {
    return real != 0;
}

bool Complex::have_complex_part() const noexcept {
    return imag != 0;
}

bool Complex::is_real() const noexcept {
    return have_real_part() && !have_complex_part();
}

bool Complex::is_imag() const noexcept {
    return !have_real_part() && have_complex_part();
}

bool Complex::is_complex() const noexcept {
    return have_real_part() && have_complex_part();
}

/// Arithmetic Operators ///
// todo: create tests for every operator

// Operators with scalars
Complex& Complex::operator+=(const double scalar) noexcept {
    real += scalar;
    return *this;
}

Complex& Complex::operator*=(const double scalar) noexcept {
    real *= scalar;
    imag *= scalar;
    return *this;
}

Complex& Complex::operator-=(const double scalar) noexcept {
    real -= scalar;
    return *this;
}

Complex& Complex::operator/=(const double scalar)  {
    if (scalar == 0.0) {
        throw std::invalid_argument("division by zero");
    }
    real /= scalar;
    imag /= scalar;
    return *this;
}

// w = z + scalar, w = z - scalar, w = z * scalar, w = z / scalar implementations:
Complex Complex::operator+(const double scalar) const noexcept {
    return Complex(real + scalar, imag);
}

Complex Complex::operator-(const double scalar) const noexcept {
    return Complex(real - scalar, imag);
}

Complex Complex::operator*(const double scalar) const noexcept {
    return Complex(real * scalar, imag * scalar);
}

Complex Complex::operator/(const double scalar) const noexcept {
    if (scalar == 0.0) {
        throw std::invalid_argument("division by zero");
    }
    return Complex(real / scalar, imag / scalar);
}

// Unary
Complex Complex::operator-() const noexcept {
    return Complex(-real, -imag);
}

// Complex operators
// self-complex operators
Complex& Complex::operator+=(const Complex &rhs) noexcept {
    real += rhs.real;
    imag += rhs.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex &rhs) noexcept {
    real -= rhs.real;
    imag -= rhs.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex &rhs) noexcept {
    real = (real * rhs.real) - (imag * rhs.imag);
    imag = (real * rhs.imag) + (imag * rhs.real);
    return *this;
}

Complex& Complex::operator/=(const Complex &rhs) {
    if (rhs.is_zero()) {
        throw std::invalid_argument("division by zero");
    }
    real = (real / rhs.real) + (imag / rhs.imag);
    imag = (real / rhs.imag) - (imag / rhs.real);
    return *this;
}

// Complex Complex
Complex Complex::operator+(const Complex &rhs) const noexcept {
    return Complex(real + rhs.real, imag + rhs.imag);
}

Complex Complex::operator-(const Complex &rhs) const noexcept {
    return (*this) + (-rhs);
}

Complex Complex::operator*(const Complex &rhs) const noexcept {
    const double real_part = (real * rhs.real) - (imag * rhs.imag);
    const double imag_part = (real * rhs.imag) + (imag * rhs.real);
    return Complex(real_part, imag_part);
}

Complex Complex::operator/(const Complex &rhs) const {
    return (*this) * (rhs.inverse()); // rhs.inverse := rhs^-1
}

// Complex Arithmetic
// w = scalar + z, w = scalar - z, w = scalar * z, w = scalar / z implementations:
Complex complex_arithmetic::operator+(const double scalar, const Complex &rhs) noexcept {
    return rhs + scalar;
}

Complex complex_arithmetic::operator-(const double scalar, const Complex &rhs) noexcept {
    return rhs - scalar;
}

Complex complex_arithmetic::operator*(const double scalar, const Complex &rhs) noexcept {
    return rhs * scalar;
}

Complex complex_arithmetic::operator/(const double scalar, const Complex &rhs) {
    return rhs.inverse() * scalar;
}

/// Mathematical Methods ///
double Complex::abs() const noexcept { // todo: maybe use my own sqrt
    return sqrt(functions::pow(real, 2) + functions::pow(imag, 2));
}

Complex Complex::conj() const noexcept {
    return Complex(real, -imag);
}

Complex Complex::inverse() const {
    if (is_zero()) {
        throw std::invalid_argument("division by zero");
    }
    const double denominator = functions::pow(real, 2) + functions::pow(imag, 2);
    const double real_part = real / denominator;
    const double imag_part = -(imag / denominator);
    return Complex(real_part, imag_part);
}

double Complex::arg() const {
    if (is_zero()) {
        throw std::invalid_argument("arg(0) is undefined");
    }
    // Re(z) = 0, Im(z) != 0
    if (is_imag()) {
        return functions::sgn(imag) * numeric::PI / 2;
    }
    // Re(z), Im(z) != 0
    if (is_complex()) {
        if (functions::sgn(real) > 0) {
            return Trigo::arctan(imag/real)();
        }
        if (functions::sgn(imag) > 0) {
            return Trigo::arctan(imag/real)() + numeric::PI;
        }
        return Trigo::arctan(imag/real)() - numeric::PI;
    }
    // Logic: Re(z) exists because is_zero is false and Im(z) doesn't exists
    if (functions::sgn(real) < 0) {
        return numeric::PI;
    }
    return 0;
}

Complex Complex::polar_complex() const {
    const double angle = arg();
    const double radius = abs();
    return Trigo::cis(angle) * radius;
}


/// Representations ///
std::string Complex::to_string() const noexcept {
    if (is_zero()) {
        return "0";
    }
    std::string result;
    if (have_real_part()) {
        result += numeric::convert_num_to_string(real);
    }
    if (have_complex_part()) {
        if (functions::sgn(imag) > 0 && have_real_part()) {
            result += "+";
        }
        result += numeric::convert_num_to_string(imag); // already have -
        result += "i";
    }
    return result;
}

std::string Complex::to_polar_string(const bool expand_cis) const noexcept {
    if (is_zero()) {
        return "0";
    }
    const std::string radius = numeric::convert_num_to_string(abs());
    const double angle = arg();
    if (!expand_cis) {
        // rcis(t)
        return radius + "cis(" + numeric::convert_num_to_string(angle) + ")";
    }
    const std::string cos = Trigo::cos(angle).to_string();
    const std::string sin = Trigo::sin(angle).to_string();
    // r(cos(t) + isin(t))
    return radius + "(" + cos + "+ i" + sin + ")";
}

std::ostream& operator<<(std::ostream &os, const Complex &rhs) {
    os << rhs.to_string();
    return os;
}

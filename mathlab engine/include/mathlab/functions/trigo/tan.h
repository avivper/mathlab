#ifndef TAN_H
#define TAN_H

#include "sin.h"
#include "cos.h"

class Tan {
public:
    /// Constructors ///
    explicit Tan(double t);

    /// Operators ///
    double operator()() const;

    /// Representations ///
    std::string to_string() const noexcept;
private:
    Sin _sin;
    Cos _cos;
    double _theta;
};

class Cot {
public:
    /// Constructors ///
    explicit Cot(double t);

    /// Operators ///
    double operator()() const;

    /// Representations ///
    std::string to_string() const noexcept;
private:
    Sin _sin;
    Cos _cos;
    double _theta;
};

class Arctan {
public:
    /// Constructors ///
    explicit Arctan(double t);

    /// Operators ///
    /*
     In practice, we compute the Taylor series until the magnitude of the next term
     is smaller than epsilon, because by Taylor’s theorem with the Lagrange remainder,
     the next term provides an upper bound on the truncation error.
     */
    double operator()() const noexcept;

    /// Representations ///
    std::string to_string() const noexcept;
private:
    static double arctan_taylor(double t) noexcept;
    double _theta;
};

#endif //TAN_H

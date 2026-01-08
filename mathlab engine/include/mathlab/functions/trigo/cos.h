#ifndef COS_H
#define COS_H

#include "sin.h"

class Cos {
public:
    /// Constructors ///
    explicit Cos(double x);

    /// Operators ///
    /*
    In practice, we compute the Taylor series until the magnitude of the next term
    is smaller than epsilon, because by Taylor’s theorem with the Lagrange remainder,
    the next term provides an upper bound on the truncation error.
    */
    double operator()() const;

    /// Properties ///
    bool is_zero() const;

    /// Representations ///
    std::string to_string() const noexcept;
private:
    double _theta;
};

#endif //COS_H

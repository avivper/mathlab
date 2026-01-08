#ifndef SINE_H
#define SINE_H

#include <mathlab/libs.h>
#include <mathlab/algebra/complex.h>

class Sin {
public:
    /// Constructors ///
    explicit Sin(double x);

    /// Operators ///
    /*
     In practice, we compute the Taylor series until the magnitude of the next term
     is smaller than epsilon, because by Taylor’s theorem with the Lagrange remainder,
     the next term provides an upper bound on the truncation error.
     */
    double operator()() const noexcept;

    /// Properties ///
    bool is_zero() const noexcept;

    /// Representations ///
    std::string to_string() const noexcept;
private:
    double _theta;
};


#endif //SINE_H

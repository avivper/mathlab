#ifndef NUMERIC_H
#define NUMERIC_H

#include <mathengine/lib/io.h>

namespace numeric {
    // ε > 0
    constexpr double EPSILON = 1e-15;

    // PI values
    constexpr double PI = 3.14159265358979323846; // π
    constexpr double TWO_PI = 2 * PI; // 2π
    constexpr double PI_OVER_TWO = PI / 2; // π * (1/2)

    // ln
    constexpr double LN2 = 0.693147180559945309417232121458176568; // ln(2)
    constexpr double INV_LN2 = 1.44269504088896340735992468100189214; // ln(2)⁻¹

    // exp, eˣ
    constexpr double E = 2.71828182845904523536; // e
    // todo: check for stackoverflow, that's the limit of exp
    constexpr double EXP_MAX = 709.782712893384;
    constexpr double EXP_MIN = -745.133219101941;

    // delete "0" from the numeric representations of the number
    std::string convert_num_to_string(double num);

    // todo: consider taylor in a different class/namespace
    constexpr unsigned int MAX_ITERATIONS = 1000000; // safety guard for taylor series
    bool taylor_iterations(double element, unsigned int index);
}

// constexpr double LN2     = 0.693147180559945309417232121458176568;
// constexpr double INV_LN2 = 1.44269504088896340735992468100189214;
//
// constexpr double EXP_MAX = 709.782712893384;
// constexpr double EXP_MIN = -745.133219101941;

#endif //NUMERIC_H
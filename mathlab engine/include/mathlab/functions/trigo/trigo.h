#ifndef TRIGO_H
#define TRIGO_H

#include "tan.h"

namespace Trigo {
    Sin sin(double t) noexcept;
    Cos cos(double t) noexcept;

    // Tan functions
    // tan(π/2) is undefined => throw exception
    Tan tan(double t);
    Cot cot(double t) noexcept; // cot = 1 / tan(t)
    Arctan arctan(double t); // arctan(t) := tan⁻¹(t)

    // Complex
    // cis(t) = cos(t) + isin(t)
    Complex cis(double t);
    // todo: csc, sec, arcsin, arccos, working with PI
}

#endif //TRIGO_H

#include <mathlab/functions/trigo/trigo.h>
#include <mathlab/functions/trigo/tan.h>

Sin Trigo::sin(const double t) noexcept {
    return Sin(t);
}

Cos Trigo::cos(const double t) noexcept {
    return Cos(t);
}

Tan Trigo::tan(const double t) {
    return Tan(t);
}

Cot Trigo::cot(const double t) {
    return Cot(t);
}

Arctan Trigo::arctan(const double t) {
    return Arctan(t);
}

// Complex
Complex Trigo::cis(const double t) noexcept {
    return Complex(cos(t)(), sin(t)());
}


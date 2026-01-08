#include <mathlab/functions/functions.h>
#include <mathlab/core/numeric.h>
#include <cmath>
#include <stdexcept>

// Utility functions
double natural_pow(double x, unsigned int n);

int functions::sgn(const double x) noexcept {
    if (x > 0) {
        return 1;
    }
    if (x < 0) {
        return -1;
    }
    return 0;
}

unsigned int functions::abs(const double x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

bool functions::is_int(const double x) {
    return abs(x - std::round(x)) < numeric::EPSILON;
}

double functions::pow(const double x, const int n) {
    if (n < 0) {
        if (x == 0) {
            throw std::invalid_argument("Division by zero");
        }
        const double result = natural_pow(x, -n);
        return 1/result;
    }
    return natural_pow(x, n);
}

unsigned long long functions::factorial(const unsigned int n) {
    unsigned long long result = 1;
    for (unsigned int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Utility functions
double natural_pow(const double x, const unsigned int n) {
    double result = 1;
    for (unsigned int i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}
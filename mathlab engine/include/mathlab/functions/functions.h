#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace functions {
    // sgn: ℝ -> {1,0,-1}
    // sgn(x) = { 1  x > 0
    //          { -1 x < 0
    //          {  0 x = 0
    int sgn(double x) noexcept;

    // abs(x) = |x|
    unsigned int abs(double x) noexcept;

    // is_int: ℝ -> {1,0}
    // is_int(x) = { 1 x ∈ ℤ
    //             { 0 otherwise
    bool is_int(double x) noexcept;

    // pow: ℝ -> ℝ: pow(x)=xⁿ, n ∈ ℤ
    double pow(double x, int n);

    // factorial: ℕ ∪ {0} -> ℕ: factorial(n) = n!
    unsigned long long factorial(unsigned int n);
}

#endif //FUNCTIONS_H

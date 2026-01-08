#include <mathlab/core/numeric.h>
#include <mathlab/functions/functions.h>

std::string numeric::convert_num_to_string(const double num) {
    std::string result = std::to_string(num);
    result.erase(result.find_last_not_of('0') + 1);
    if (result.back() == '.') {
        result.pop_back();
    }
    return result;
}

bool numeric::taylor_iterations(const double element, const unsigned int index) {
    return (functions::abs(element) > EPSILON && index < MAX_ITERATIONS);
}

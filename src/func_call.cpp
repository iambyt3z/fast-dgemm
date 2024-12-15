#include "func_call.h"

void 
func_call
(const std::string &func_name, std::vector<double> &C, const std::vector<double> &A, const std::vector<double> &B, int n) {
    if (func_name == "dgemm")
        dgemm(C, A, B, n);

    else if (func_name == "dgemm2")
        dgemm2(C, A, B, n);

    else {
        std::cerr << "Error: Unknown function name '" << func_name << "'" << '\n';
        std::exit(1); // Exit with an error code
    }
}
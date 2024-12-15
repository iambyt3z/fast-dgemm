#include "name_check.h"

void name_check(const std::string &func_name) {
    bool valid_name = (func_name == "dgemm") || (func_name == "dgemm2");

    if (!valid_name) {
        std::cerr << "Invalid function name" << '\n';
        std::exit(1); // Exit with an error code
    }
}

#ifndef FUNC_CALL_H
#define FUNC_CALL_H

#include <string>
#include <iostream>

#include "dgemm.h"
#include "dgemm2.h"

void func_call(const std::string &func_name, std::vector<double> &C, const std::vector<double> &A, const std::vector<double> &B, int n);

#endif // FUNC_CALL_H

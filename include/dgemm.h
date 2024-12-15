#ifndef DGEMM_H
#define DGEMM_H

#include <vector>

void dgemm(std::vector<double> &C, const std::vector<double> &A, const std::vector<double> &B, int n);

#endif // DGEMM_H
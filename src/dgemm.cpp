#include "dgemm.h"

void
dgemm
(std::vector<double> &C, const std::vector<double> &A, const std::vector<double> &B, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i * n + j] += A[i * n + k] * B[k * n + j];
}
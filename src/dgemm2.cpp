#include "dgemm2.h"

void
dgemm2
(std::vector<double> &C, const std::vector<double> &A, const std::vector<double> &B, int n)
{
    const int b = 8; // Block size

    for (int i = 0; i < n; i += b) {
        for (int k = 0; k < n; k += b) {
            for (int j = 0; j < n; j += b) {

                for (int ii = i; ii < i + b; ii++) {
                    for (int kk = k; kk < k + b; kk++) {
                        double a_ik = A[ii * n + kk];

                        for (int jj = j; jj < j + b; jj++) {
                            C[ii * n + jj] += a_ik * B[kk * n + jj];
                        }
                    }
                }
            }
        }
    }
}

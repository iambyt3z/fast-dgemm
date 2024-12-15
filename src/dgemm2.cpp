#include "dgemm2.h"

void
dgemm2
(std::vector<double> &C, const std::vector<double> &A, const std::vector<double> &B, int n)
{
    const int b = 8; // Block size
    
    for (int j = 0; j < n; j += b) {
        for (int i = 0; i < n; i += b) {
            for (int k = 0; k < n; k += b) {

                for (int jj = j; jj < j + b; jj += 2) {
                    for (int ii = i; ii < i + b; ii += 2) {

                        double c00_ij = C[ii * n + jj];
                        double c01_ij = C[ii * n + jj + 1];
                        double c10_ij = C[(ii + 1) * n + jj];
                        double c11_ij = C[(ii + 1) * n + jj + 1];

                        for (int kk = k; kk < k + b; kk += 3) {
                            
                            double a00_ik = A[ii * n + kk];
                            double a01_ik = A[ii * n + kk + 1];
                            double a02_ik = A[ii * n + kk + 2];

                            double a10_ik = A[(ii + 1) * n + kk];
                            double a11_ik = A[(ii + 1) * n + kk + 1];
                            double a12_ik = A[(ii + 1) * n + kk + 2];

                            double b00_kj = B[kk * n + jj];
                            double b10_kj = B[(kk + 1) * n + jj];
                            double b20_kj = B[(kk + 2) * n + jj];

                            double b01_kj = B[kk * n + jj + 1];
                            double b11_kj = B[(kk + 1) * n + jj + 1];
                            double b21_kj = B[(kk + 2) * n + jj + 1];

                            c00_ij += a00_ik * b00_kj + a01_ik * b10_kj + a02_ik * b20_kj;
                            c01_ij += a00_ik * b01_kj + a01_ik * b11_kj + a02_ik * b21_kj;
                            c10_ij += a10_ik * b00_kj + a11_ik * b10_kj + a12_ik * b20_kj;
                            c11_ij += a10_ik * b01_kj + a11_ik * b11_kj + a12_ik * b21_kj;
                        }

                        C[ii * n + jj] = c00_ij;
                        C[ii * n + jj + 1] = c01_ij;
                        C[(ii + 1) * n + jj] = c10_ij;
                        C[(ii + 1) * n + jj + 1] = c11_ij;
                    }
                }
            }
        }
    }
}

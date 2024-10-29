void dgemm_opt(double *C,double *A,double *B,int n)
{
    int i, ii, j, jj, k, kk;
    int b = 12;

    for (j = 0; j < n; j += b)
    {
        for (i = 0; i < n; i += b)
        {
            for (k = 0; k < n; k += b)
            {
                for (jj = j; jj < j + b; jj+=2)
                {
                    for (ii = i; ii < i + b; ii+=2)
                    {
                        register double c00_ij = C[ii * n + jj];
                        register double c01_ij = C[ii * n + jj + 1];
                        register double c10_ij = C[(ii + 1) * n + jj];
                        register double c11_ij = C[(ii + 1) * n + jj + 1];

                        for (kk = k; kk < k + b; kk+=3)
                        {
                            register double a00_ik = A[ii * n + kk];
                            register double a01_ik = A[ii * n + kk + 1];
                            register double a02_ik = A[ii * n + kk + 2];

                            register double a10_ik = A[(ii + 1) * n + kk];
                            register double a11_ik = A[(ii + 1) * n + kk + 1];
                            register double a12_ik = A[(ii + 1) * n + kk + 2];

                            register double b00_kj = B[kk * n + jj];
                            register double b10_kj = B[(kk + 1) * n + jj];
                            register double b20_kj = B[(kk + 2) * n + jj];

                            register double b01_kj = B[kk * n + jj + 1];
                            register double b11_kj = B[(kk + 1) * n + jj + 1];
                            register double b21_kj = B[(kk + 2) * n + jj + 1];

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
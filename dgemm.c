void dgemm(double *C, double *A, double *B, int n)
{
    int i, j, k;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                C[i*n + j] += A[i*n + k] * B[k*n + j];
}
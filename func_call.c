void func_call(char *func_name,double *C,double *A,double *B,int n)
{
    if (strcmp(func_name,"dgemm")==0)  dgemm(C,A,B,n);
    if (strcmp(func_name,"dgemm_opt")==0)  dgemm_opt(C,A,B,n);
}
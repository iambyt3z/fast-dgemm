To test a single GEMM function,
* Compile the corresponding file using `make`
* Test the code with `./main {function_name} {n} {pad}` (e.g. `./main dgemm 1024 1`). 
* {function name} is the name of the GEMM function you want to test.
* {n} is the axis length of the square matrix being tested. For example, n=2048
means you want the matrix size to be 2048*2048.
* {pad} is the length of padding. You can use proper padding to avoid corner
cases when tiling. For example, n=2048 and pad=30 means n=2070.

#include <chrono>
#include <random>
#include <iostream>

#include "func_call.h"
#include "name_check.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./main -func -n -pad" << std::endl;
        return 1;
    }

    std::string func_name = argv[1];
    int n = std::atoi(argv[2]);
    int pad = std::atoi(argv[3]);
    n = ((n + pad - 1) / pad) * pad;

    name_check(func_name);
    std::cout << "n = " << n << std::endl;

    std::vector<double> A_backup(n * n);
    std::vector<double> B_backup(n * n);
    std::vector<double> C_backup(n * n);

    std::vector<double> A(n * n);
    std::vector<double> B(n * n);
    std::vector<double> C(n * n);

    // Random number generation
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    for (int i = 0; i < n * n; i++) {
        A_backup[i] = dist(gen);
        A[i] = A_backup[i];
        B_backup[i] = dist(gen);
        B[i] = B_backup[i];
        C_backup[i] = dist(gen);
        C[i] = C_backup[i];
    }

    // Timing using C++ <chrono>
    auto start = std::chrono::high_resolution_clock::now();
    func_call(func_name, C, A, B, n);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    double time_taken = elapsed.count();
    double gflops = (2.0 * n * n * n) / (time_taken * 1e9);

    std::cout << "time = " << time_taken << " sec" << std::endl;
    std::cout << "performance = " << gflops << " Gflops" << std::endl;

    for (int t = 0; t < 10; t++) {
        int i = std::uniform_int_distribution<>(0, n - 1)(gen);
        int j = std::uniform_int_distribution<>(0, n - 1)(gen);

        double standard = C_backup[i * n + j];
        for (int k = 0; k < n; k++) {
            standard += A_backup[i * n + k] * B_backup[k * n + j];
        }

        if (std::fabs(C[i * n + j] - standard) > 1e-5) {
            std::cerr 
                << "Error at (" << i << "," << j 
                << "): standard = " << standard << ", output = " 
                << C[i * n + j] << std::endl;
        }
    }

    return 0;
}

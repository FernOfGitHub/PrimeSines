//============================================================================
// Name        : PrimeAndSines.cpp
// Author      : smithkm
// Version     :
// Copyright   : Don't need no stinkin' copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include "genprime.h"

int main() {
	std::cout << "Calculate Primes" << std::endl;
	CPrimes primes(ONE_MILLION);

    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();

    primes.makelist(20LL*ONE_MILLION);

    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();
    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms\n";
    std::cout << std::endl;

    primes.print();

	std::cout << "Mod Primes" << std::endl;
	CPrimeSines sineprime(ONE_MILLION);
    c_start = std::clock();
    t_start = std::chrono::high_resolution_clock::now();

	sineprime.makelist(20LL*ONE_MILLION);

    c_end = std::clock();
    t_end = std::chrono::high_resolution_clock::now();
    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms\n";
    std::cout << std::endl;

    sineprime.print();
	return 0;
}

/*
 * GenPrime.cpp
 *
 *  Created on: Jul 18, 2018
 *      Author: smithkm
 */

/* List and count primes.
   Written by tege while on holiday in Rodupp, August 2001.
   Between 10 and 500 times faster than previous program.

Copyright 2001, 2002, 2006, 2012 Free Software Foundation, Inc.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see https://www.gnu.org/licenses/.  */

// This file is a derived, in part, from GMP 6.1.2 demos/primes.c

#include <cstring>	// memset
#include <cstdlib>
#include <iostream>

#include "genprime.h"

CPrimes::CPrimes(void):
m_prime(nullptr), m_maxAllowedPrimes(0), m_maxvalidprimes(0)
{
	m_prime = (long long *)malloc(1000*sizeof(*m_prime));
	if(m_prime != nullptr) {
		m_maxAllowedPrimes = 1000;
	}
}
CPrimes::CPrimes(long long maxprimes):
m_prime(nullptr), m_maxAllowedPrimes(0), m_maxvalidprimes(0)
{
	if(maxprimes < 2) maxprimes = 2;
	m_prime = (long long *)malloc(maxprimes*sizeof(*m_prime));
	if(m_prime != nullptr) {
		m_maxAllowedPrimes = maxprimes;
	}
}

CPrimes::~CPrimes(void)
{
	free(m_prime);
}

// This 'makelist' is modified from the GMP 6.1.2 demos/primes.c
void CPrimes::makelist(long long upperlimit)
{
	if(m_maxAllowedPrimes == 0) return;
	if(upperlimit <= 0) return;

	unsigned char *s;
	long long ssize = upperlimit/2;	// odd numbers only
	long long i, ii, j;

	s = (unsigned char *)malloc (ssize);
	memset (s, ~0, ssize);
	for (i = 3; ; i += 2)
	{
		if (i*i >= upperlimit) {
			break;
		}
		if (s[i * i / 2 - 1] == 0) {
			continue;				/* only sieve with primes */
		}
		for (ii = i * i / 2 - 1; ii < ssize; ii += i) {	// eliminate multiples
			s[ii] = 0;
		}
	}
	long long n_primes = 0;
	for (j = 0; j < ssize; j++)
	{
		if (s[j] != 0)
		{
			m_prime[n_primes] = j * 2 + 3;
			n_primes++;
			if(n_primes >= m_maxAllowedPrimes) break;
		}
	}
	m_maxvalidprimes = n_primes;
	free (s);
}

void CPrimes::print(void)
{
	std::cout << "Number of primes " << m_maxvalidprimes << std::endl;
	if(m_maxvalidprimes > 0) {
		std::cout << "Max prime " << m_prime[m_maxvalidprimes-1] << std::endl;
	}
}

CPrimeSines::CPrimeSines(void):
m_prime(nullptr), m_maxAllowedPrimes(0), m_maxvalidprimes(0)
{
	m_prime = (long long *)malloc(1000*sizeof(*m_prime));
	if(m_prime != nullptr) {
		m_maxAllowedPrimes = 1000;
	}
}

CPrimeSines::CPrimeSines(long long maxprimes):
m_prime(nullptr), m_maxAllowedPrimes(0), m_maxvalidprimes(0)
{
	if(maxprimes < 2) maxprimes = 2;
	m_prime = (long long *)malloc(maxprimes*sizeof(*m_prime));
	if(m_prime != nullptr) {
		m_maxAllowedPrimes = maxprimes;
	}
}

CPrimeSines::~CPrimeSines(void)
{
	free(m_prime);
}

void CPrimeSines::makelist(long long upperlimit)
{
	if(m_maxAllowedPrimes == 0) return;
	if(upperlimit <= 0) return;

	m_prime[0] = 2;
	m_maxvalidprimes = 1;
	if(upperlimit <= 2) return;
	if(m_maxAllowedPrimes == 1) return;

	m_prime[1] = 3;
	m_maxvalidprimes = 2;
	if(upperlimit <= 3) return;
	if(m_maxAllowedPrimes == 2) return;

	long long start_digit = m_prime[m_maxvalidprimes-1] + 2;	// first start_digit=5
	while(1) {
		// first end_digit=25
		long long end_digit = (m_prime[m_maxvalidprimes-1] + 2)*(m_prime[m_maxvalidprimes-1] + 2);
		if(end_digit > upperlimit) {
			end_digit = upperlimit;
		}
		long long current_valid_primes = m_maxvalidprimes;
		for(long long ii = start_digit; ii < end_digit; ii += 2) {
			long long mod;
			for(long long ip = 1; ip <current_valid_primes; ip++) {	// skip 2
				mod = ii % m_prime[ip];
				if(mod == 0) {
					break;
				}
				if(m_prime[ip]*m_prime[ip] > ii) {
					break;
				}
			}
			if(mod != 0) {
				m_prime[m_maxvalidprimes] = ii;
				m_maxvalidprimes++;
				if(m_maxvalidprimes % 100000 == 0) {
					std::cout << " found " << m_maxvalidprimes << std::endl;
				}
				if(m_maxvalidprimes >= m_maxAllowedPrimes) {
					return;
				}
			}
		}
		if(end_digit >= upperlimit) break;
		start_digit = end_digit;
	}
}

void CPrimeSines::print(void)
{
	std::cout << "Number of primes " << m_maxvalidprimes << std::endl;
	if(m_maxvalidprimes > 0) {
		std::cout << "Max prime " << m_prime[m_maxvalidprimes-1] << std::endl;
	}
}

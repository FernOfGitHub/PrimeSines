/*
 * genprime.h
 *
 *  Created on: Jul 18, 2018
 *      Author: smithkm
 */

#ifndef GENPRIME_H_
#define GENPRIME_H_

#define ONE_MILLION (1000LL*1000LL)
#define ONE_BILLION (1000LL*1000LL*1000LL)
class CPrimes
{
public:
	CPrimes(long long maxprimesallowed);
	CPrimes(void);
	~CPrimes(void);
	void makelist(long long upperlimit);
	void print(void);
private:
	long long *m_prime;
	long long m_maxAllowedPrimes;
	long long m_maxvalidprimes;
};

class CPrimeSines
{
public:
	CPrimeSines(long long maxprimesallowed);
	CPrimeSines(void);
	~CPrimeSines(void);
	void makelist(long long upperlimit);
	void print(void);
private:
	long long *m_prime;
	long long m_maxAllowedPrimes;
	long long m_maxvalidprimes;
};

#endif /* GENPRIME_H_ */

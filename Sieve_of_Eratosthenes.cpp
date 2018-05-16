#include <iostream>
using namespace std;

// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *	Problems:												*
 *		receiving segmentation error when calculating with	*
 *		boundary above 10^7.								*
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void SieveOfEratosthenes(long long int limit)
{
	long long int i;
	long long int k;
	long long int primeCount;
	bool isPrime[limit + 1];

	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = false;
	isPrime[1] = false;

	for (i = 2; i*i <= limit; i++)
	{
		if (isPrime[i])
		{
			for (k = i*i; k <= limit; k += i)
			{
				isPrime[k] = false;
			}
		}
	}
	primeCount = 0;
	for (i = 2; i <= limit; i++)
	{
		if (isPrime[i])
		{
			primeCount ++;
		}
	}
	cout << "\nThere are " << primeCount << " prime numbers between 2 and "
		 << limit << ".\n\n";
}

long long int upperBound;

int main()
{
	cout << "Enter upper bound: ";
	cin  >> upperBound;

	cout << "Finding all prime numbers below " << upperBound
		 << "...\n";

	SieveOfEratosthenes(upperBound);

	return 0;
}
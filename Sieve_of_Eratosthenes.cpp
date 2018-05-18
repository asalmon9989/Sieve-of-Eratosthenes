
//#include "stdafx.h"
#include <iostream>
#include <string>
#include "time.h"
#include <fstream>
using namespace std;

// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*	Problems:												*
*		Can't go too far over a billion for the limit		*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void SieveOfEratosthenes(__int64 limit, bool write = false, string fileName = "")
{
	__int64 i;
	__int64 k;
	__int64 primeCount;
	bool * isPrime = new bool[limit + 1];


	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = false;
	isPrime[1] = false;

	primeCount = limit - 1;

	for (i = 2; i*i <= limit; i++)
	{
		if (isPrime[i])
		{
			for (k = i * i; k <= limit; k += i)
			{
				if (isPrime[k])
				{
					primeCount--;
				}
				isPrime[k] = false;
			}
		}
	}
	
	if (write) {
		ofstream outFile;
		fileName = fileName + ".txt";
		outFile.open(fileName.c_str(), ios::binary);  //open file in binary mode
		for (i = 2; i <= limit; i++)
		{
			if (isPrime[i])
			{
				outFile << i << endl;
			}
		}
		outFile.close();
	}
	
	
	cout << "\nThere are " << primeCount << " prime numbers between 2 and "
		<< limit << ".\n\n";
	delete[] isPrime;
}



int main()
{
	__int64 upperBound;
	__int64 a = 10000000000;
	bool write = false;
	string fileName = "";
	string yn;
	cout << "Enter upper bound: ";
	cin >> upperBound;
	cout << "Do you want to write results to a new file? (Y/N)";
	cin.ignore(1000, '\n');
	getline(cin, yn);
	if (yn[0] == 'Y' || yn[0] == 'y') {
		write = true;
		cout << "Enter the file name to write to (exclude extention): ";
		getline(cin, fileName);
	}


	cout << "Finding all prime numbers below " << upperBound
		<< "...\n";

	SieveOfEratosthenes(upperBound, write, fileName);
	system("PAUSE");

	return 0;
}
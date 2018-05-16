import time

# https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
def Sieve_Of_Eratosthenes(limit):
	prime_cat = [False, False]
	for i in range(2, limit + 1):
		prime_cat.append(True)

	for i in range(2, len(prime_cat)):
		if (prime_cat[i]):
			j = i**2
			while (j <= limit):
				prime_cat[j] = False
				j += i
	
	prime_count = 0
	for i in range(2, len(prime_cat)):
		if (prime_cat[i]):
			prime_count += 1

	print("There are {} prime numbers below {}.".format(prime_count, limit))

upper_bound = input("Enter upper bound (inclusive): ")
print("Thinking...")

start_time = time.time()
Sieve_Of_Eratosthenes(int(upper_bound))
end_time = time.time()

print("Run time: {:.3e}s".format(end_time - start_time))
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int checkprime(int n, int *isprime)
{
	if(n < 0) n = -n;
	
	if(isprime[n] == -1) {
		for(int i = 2; i < sqrt(n) + 1; i++) {
			if(n % i == 0) {
				isprime[n] = 0;
				break;
			}
		}
	}
	
	if(isprime[n] == -1) {
		isprime[n] = 1;
	}
	
	return isprime[n];
}

int checkquad(int a, int b, int *isprime)
{
	int q = b;
	int n = 0;
	
	while(checkprime(q, isprime)) {
		n++;
		q = n * n + a * n + b;
	}
	
	return n;
}

int main(int argc, char *argv[])
{
	int max_primes = 0;
	long max_product = 0;
	int *isprime = malloc(111000 * sizeof(int)); // 1 if prime, 0 if not, -1 if unchecked
	for(int i = 0; i < 111000; i++) {
		isprime[i] = -1;
	}
	isprime[0] = 0;
	isprime[1] = 0;
	
	for(int a = -999; a < 1000; a++) {
		for(int b = -999; b < 1000; b++) {
			int primes = checkquad(a, b, isprime);
			if(primes > max_primes) {
				max_primes = primes;
				max_product = ((long)a) * ((long)b);
			} 
		}
	}
	
	printf("%ld\n", max_product);
	
	return 0;
}
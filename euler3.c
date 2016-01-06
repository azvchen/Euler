#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

//#define SIZE 6000

int isprime(long n)
{
	for(long i = 2; i < sqrt(n) + 1; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

long largestprimefactor(long n)
{
	long max = 0;
	for(long i = 2; i < (long)(sqrt(n)) + 1; i++) {
		if(n % i == 0) {
			printf("%ld\n", i);
			if(isprime(n / i)) {
				return n / i;
			} else if(isprime(i)) {
				max = i;
			}
		}
	}
	return max;
}

int main(int argc, char *argv[])
{
	long n = 600851475143;
	printf("%ld\n", largestprimefactor(n));
	
	return 0;
}
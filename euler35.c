#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000000

bool *get_prime_list(long n)
{
	bool *is_prime = malloc(n * sizeof(bool));
	is_prime[0] = false;
	is_prime[1] = false;
	for(long i = 2; i < n; i++) {
		is_prime[i] = true;
		for(long f = 2; f < (long)sqrt(i) + 1; f++) {
			if(i % f == 0) {
				is_prime[i] = false;
				break;
			}
		}
	}
	return is_prime;
}

int digits_in(long n)
{
	int d = 0;
	while(n > 0) {
		n /= 10;
		++d;
	}
	return d;
}

int pow10(int n)
{
	int i = 1;
	while(n > 0) {
		i *= 10;
		n--;
	}
	return i;
}

bool is_circular_prime(long n, bool *is_prime)
{
	int d = digits_in(n);
	for(int i = 0; i < d; i++) {
		//printf("%ld\n", n);
		if(!is_prime[n])
			return false;
		n = (n % 10) * pow10(d-1) + n / 10;
	}
	return true;
}

int main(int argc, char *argv[])
{
	bool *is_prime = get_prime_list(SIZE);
	
	int sum = 0;
	for(long n = 2; n < SIZE; n++) {
		if(is_circular_prime(n, is_prime)) {
			printf("%ld\n", n);
			sum++;
		}
		//printf("\n");
	}
	printf("---\n%d\n", sum);
	
	return 0;
}
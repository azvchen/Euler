#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int digits_in(int n)
{
	int d = 0;
	while(n > 0) {
		n /= 10;
		++d;
	}
	return d;
}

long lpow(int i)
{
	long p = 1;
	while(i > 0) {
		p *= 10;
		i--;
	}
	return p;
}

int is_prime(long n)
{
	if(n == 0 || n == 1) return 0;
	
	for(long f = 2; f < (int)sqrt(n) + 1; f++)
		if(n % f == 0)
			return 0;
	return 1;
}

int is_left_prime(long n)
{
	int d = digits_in(n);
	while(d > 0) {
		if(!is_prime(n))
			return 0;
		d--;
		n = n % lpow(d);
	}
	return 1;
}

int is_right_prime(long n)
{
	while(n > 0) {
		if(!is_prime(n))
			return 0;
		n /= 10;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	long sum = 0;
	int count = 0;
	
	long n = 11;
	printf("%ld\n", LONG_MAX);
	while(count < 11 && n <= LONG_MAX) {
		if(is_left_prime(n) && is_right_prime(n)) {
			count++;
			sum += n;
			printf("%ld\n", n);
		}
		n++;
	}
	
	printf("Sum: %ld\n", sum);
	printf("Count: %d\n", count);
	
	return 0;
}
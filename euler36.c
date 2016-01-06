#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000000

int powb(int i, int b)
{
	int n = 1;
	while(i > 0) {
		i--;
		n *= b;
	}
	return n;
}

int digits_in(int n, int b)
{
	int d = 0;
	while(n > 0) {
		n /= b;
		++d;
	}
	return d;
}

int digit_at(int n, int b, int d)
{
	return (n / powb(d, b)) % b;
}

int is_palin(int n, int b)
{
	int digits = digits_in(n, b);
	
	for(int d = 0; d < digits/2; d++) {
		if(digit_at(n, b, d) != digit_at(n, b, digits - d - 1)) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[])
{
	long sum = 0;
	
	for(long n = 1; n < SIZE; n++) {
		if(is_palin(n, 10) && is_palin(n, 2)) {
			sum += n;
			printf("%ld\n", n);
		}
	}
	printf("Sum: %ld\n", sum);
	
	return 0;
}
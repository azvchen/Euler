#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 10

long *get_factorials(int n)
{
	long *facs = malloc(n * sizeof(long));
	facs[0] = 1;
	for(int i = 1; i < n; i++)
		facs[i] = i * facs[i-1];
	return facs;
}

int is_fac_sum(long n, long *facs)
{
	long sum = 0;
	long digits = n;
	while(digits > 0) {
		sum += facs[digits % 10];
		digits /= 10;
	}
	return sum == n;
}

int main(int argc, char *argv[])
{
	long *facs = get_factorials(SIZE);
	
	long long sum = 0;
	for(long n = 10; n < 50000; n++) {
		if(is_fac_sum(n, facs)) {
			sum += n;
			printf("%ld\n", n);
		}
	}
	printf("%lld\n", sum);
	
	return 0;
}
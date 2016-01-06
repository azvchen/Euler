#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//#define SIZE 6000

int isprime(int n)
{
	for(int i = 2; i < sqrt(n) + 1; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	int count = 0;
	int n = 2;
	while(count < 10000) {
		if(isprime(n)) {
			count++;
		}
		n++;
	}
	printf("%d: %d\n", count, n);
	
	return 0;
}
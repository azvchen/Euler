#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int ispalin(long n)
{
	return n / 100000 == n % 10 
		&& (n / 10000) % 10 == (n / 10) % 10 
		&& (n / 1000) % 10 == (n / 100) % 10;
}

int main(int argc, char *argv[])
{
	long max = 100001;
	
	for(long a = 100; a < 1000; a++)
		for(long b = a; b < 1000; b++)
			if(ispalin(a * b) && a * b > max)
				max = a * b;
	printf("%ld\n", max);
	
	return 0;
}
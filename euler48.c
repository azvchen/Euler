#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define E10 10000000000

long get_ten(int n)
{
	long product = 1;
	for(int i = 0; i < n; i++)
		product = (product * n) % E10;
	return product;
}

int main(int argc, char *argv[])
{
	long sum = 0;
	for(int i = 1; i < 1001; i++)
		sum = (sum + get_ten(i)) % E10;
	printf("%ld\n", sum);
		
	return 0;
}
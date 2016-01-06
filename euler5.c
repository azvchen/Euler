#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int isdiv(long n)
{
	for(int f = 2; f <= 20; f++)
		if(n % f != 0)
			return 0;
	return 1;
}

int main(int argc, char *argv[])
{
	long n = 1;
	while(1) {
		if(isdiv(n)) {
			printf("%ld\n", n);
		}
		n++;
	}
	
	return 1;
}
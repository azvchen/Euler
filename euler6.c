#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	long sum = 0;
	long sumsquares = 0;
	for(long n = 1; n < 101; n++) {
		sum += n;
		sumsquares += n * n;
	}
	printf("%ld\n", sum * sum - sumsquares);
	
	return 0;
}
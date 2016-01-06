#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int ntri = 285, npent = 165, nhex = 143;
	long tri = 40755, pent = 40755, hex = 40755;
	
	do {
		tri += ++ntri;
		while(pent < tri)
			pent += (3 * ++npent) - 2;
		while(hex < tri)
			hex += (4 * ++nhex) - 3;
	} while(tri != pent || tri != hex);
	
	printf("%ld\n", tri);
	
	return 0;
}
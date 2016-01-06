#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 4

int has_n_factors(int i, int n)
{
	printf("%d: ", i);
	int factors[n];
	int nfactors = 0;
	
	/** This for loop finds the first prime factor (f) of i and adds it to 
	  * factors[], then divides i by f and repeats, until i is prime.
	  * If nfactors gets greater than n, it returns 0 immediately. */
	for(int f = 2; f < (int)sqrt(i) + 1; f++) {
		if(i % f == 0) {
			int nf;
			for(nf = 0; nf < nfactors; nf++)
				if(factors[nf] == f)
					break;
			if(nf == n) {	// too many factors
				printf("\n");
				return 0;
			} else if(nf == nfactors) {
				printf("%d ", f);
				factors[nf] = f;
				nfactors++;
			}
			// remove factor f from i, reset f to 1 (becomes 2 at f++ above)
			i /= f;
			f = 1;
		}
	}
	for(int nf = 0; nf < nfactors; nf++)
		if(factors[nf] == i) {
			i = 1;
			break;
		}
	if(i > 1)
		printf("%d", i);
	printf("\n");
	if((i == 1 && nfactors == n) || (i > 1 && nfactors == n-1))
		return 1;
	else
		return 0;
}

int main(int argc, char *argv[])
{
	int count = 0;
	for(int i = 2; i <= INT_MAX; i++) {
		if(has_n_factors(i, SIZE)) {
			count++;
			if(count == SIZE) {
				printf("%d to %d\n", i-SIZE+1, i);
				return 0;
			}
		}
		else
			count = 0;
	}
	
	printf("No ints found.\n");
		
	return 0;
}
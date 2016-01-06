#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// returns pointer to unsigned long array of first n-1 pentagon numbers
unsigned long *make_pents(int n)
{
	unsigned long *pents = malloc(n * sizeof(unsigned long));
	//printf("\nPents:\n");
	for(int k = 0; k < n; k++) {
		pents[k] = k * (3*k - 1) / 2;
		//printf("%d: %lu\n", k, pents[k]);
	}
	//printf("\n");
	return pents;
}

unsigned long *expand_pents(unsigned long *old_pents, int n)
{
	free(old_pents);
	return make_pents(n);
}

// returns if n is in pents, assumes that n is less that largest value of pents
int is_pent(int n, unsigned long *pents)
{
	int i = 0;
	while(pents[++i] <= n)
		if(pents[i] == n)
			return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	long size = 64;
	unsigned long *pents = make_pents(size);
	
	int d = 100;
	while(d < 10000) {	// will run until a valid D is found
		unsigned long D = pents[d];	// loop starts at the lowest d remaining
		
		// clearly must have pents[k] > D
		// through mathy analysis, j is slightly bigger than this expression
		int k = d+1;
		int j = (int)sqrtl((pents[k] - D) / 3 * 2);
		printf("%d: %lu %d %d\n", d, D, j, k);
		
		// at some point, D will be so small relative to k that j >= k,
		// so quit the loop then
		// j starts out too big, dec. j until it becomes too small, 
		// which is when D < pents[k] - pents[j]
		// as j dec., diff inc.
		while(j+70 < k) {
			unsigned long diff = pents[k] - pents[j];
			//printf("j = %d, k = %d\n", j, k);
			if(D == diff) {	// diff is a pentagon number, now check sum
				unsigned long sum = pents[j] + pents[k];
				printf("   %lu %lu : %lu\n", pents[j], pents[k], sum);
				if(sum > pents[size-1])	// expand pents if sum is too big
					pents = expand_pents(pents, (size = size / 2 * 3));
				if(is_pent(sum, pents)) {	// both conditions met, done
					printf("Done: %lu: %lu %lu\n", D, pents[j], pents[k]);
					return 0;
				}
			}
			
			if(D > diff) {	// inc. diff by dec. j
				j--;
			} else {	// inc. k and reset j
				if(++k >= size)	// expand pents if k is too big
					pents = expand_pents(pents, (size = size / 2 * 3));
				j = (int)sqrtl((pents[k] - D) / 3 * 2) + 1;
				/*if(d == 212 && k > 26755) {
					printf("   %lu %d %d %lu\n", D, j, k, pents[k]);
					printf("%u %lu\n", UINT_MAX, ULONG_MAX);
				}*/
			}
		}
		d++;
	}
	
	return 1;	// something in the loop failed, should never be reached
}
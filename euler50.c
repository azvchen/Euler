#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000000

int is_prime(long n)
{
	for(int f = 2; f < (long)sqrt(n) + 1; f++)
		if(n % f == 0)
			return 0;
	return 1;
}

int bin_search(long n, long *list, long size)
{
	long lower = 0, upper = size-1;
	while(lower != upper) {
		long mid = (lower + upper) / 2;
		long diff = n - list[mid];
		if(diff == 0)
			return 1;
		else if(diff < 0) {
			upper = mid-1;
		} else {
			lower = mid+1;
		}
	}
	if(list[lower] == n)
		return 1;
	return -1;
}

long *get_primes(long size)
{
	//printf("Got to get_primes() with size %ld.\n", size);
	long *primes = malloc(size * sizeof(long));
	//printf("Made primes.\n");
	
	primes[0] = 2;
	//printf("%ld ", primes[0]);
	for(long i = 1; i < size; i++) {
		long n = primes[i-1] + 1;
		for(long j = 0; j < i; j++) {
			if(n % primes[j] == 0) {
				n++;
				j = -1;
			} else if(sqrt(n) <= primes[j]) {
				break;
			}
		}
		primes[i] = n;
		//printf("%ld ", primes[i]);
	}
	
	return primes;
}

long get_sum(int count, long max, long *primes, long size)
{
	long sum = 0;
	long i;
	for(i = 0; i < count; i++) {
		sum += primes[i];
	}
	printf("%d: %ld, %ld to %ld\n", count, sum, i-count, i);
	
	while(sum < max) {
		if(is_prime(sum)) {
			printf("%d: %ld, %ld to %ld\n", count, sum, i-count, i);
			return sum;
		}
		if(i >= size)
			return 0;
		sum += primes[i] - primes[i-count];
		i++;
	}
	
	return 0;
}

int main(int argc, char *argv[])
{
	long size = 80000;
	long *primes = get_primes(size);
	printf("%ldth prime: %ld\n", size, primes[size-1]);
	/*for(long i = 0; i < 1000; i++)
		printf("%ld ", primes[i]);
	printf("\n");*/
	
	long p = 0;
	for(int count = 21; count < 1000; count++) {
		long sum = get_sum(count, MAX, primes, size);
		if(sum > 0)
			p = sum;
	}
	printf("%ld\n", p);
	free(primes);
		
	return 0;
}
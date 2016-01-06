#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int is_prime(int n)
{
	for(int i = 2; i < sqrt(n) + 1; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

long permute(char *perm, char *remain, int size, int r_size, int orig)
{
	if(r_size == 0) {
		//printf("%s\n", perm);
		long n = atol(perm);
		if(is_prime(n) && n != orig) {
			printf("%ld\n");
			return n;
		}
		return 0;
	}
	
	char *newremain = malloc((r_size - 1) * sizeof(char));
	int newindex = size - r_size;
	long sum = 0;
	for(int r = 0; r < r_size; r++) {
		perm[newindex] = remain[r];
		for(int j = 0; j < r_size; j++) {
			if(j < r) {
				newremain[j] = remain[j];
			}
			else if(j > r) {
				newremain[j-1] = remain[j];
			}
		}
		long p = permute(perm, newremain, size, r_size - 1, orig);
		if(p > 0) {
			if(sum > 0) {
				if(p > sum)
					sum = sum * 10000 + p;
				else
					sum = p * 10000 + sum;
			} else {
				sum = p;
			}
		}
	}
	free(newremain);
	
	return sum;
}

int main(int argc, char *argv[])
{
	for(int i = 1000; i < 1500; i++) {
		if(is_prime(i)) {
			char *perm = malloc(4 * sizeof(char));
			char *remain = malloc(4 * sizeof(char));
			int n = i;
			for(int j = 0; j < 4; j++) {
				remain[i] = '0' + (n % 10);
				n /= 10;
			}
			printf("%d %s\n", i, remain);
			long p = permute(perm, remain, 4, 4, i);
			if(p > 9999) {
				printf("%d%ld\n", i, p);
				return 0;
			}
			free(perm);
			free(remain);
		}
	}
	
	return 0;
}
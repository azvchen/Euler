#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int isprime(long n)
{
	for(long i = 2; i < sqrt(n) + 1; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

void permute(char *perm, char *remain, int size, int r_size)
{
	if(r_size == 0) {
		//printf("%s\n", perm);
		if(isprime(atol(perm))) {
			printf("%s\n", perm);
			exit(0);
		}
		return;
	}
	
	char *newremain = malloc((r_size - 1) * sizeof(char));
	int newindex = size - r_size;
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
		permute(perm, newremain, size, r_size - 1);
	}
	free(newremain);
}

int main(int argc, char *argv[])
{
	for(int size = 7; size > 0; size--) {
		char *perm = malloc(size * sizeof(char));
		char *remain = malloc(size * sizeof(char));
		for(int i = 0; i < size; i++) {
			remain[i] = '0' + size - i;
		}
		printf("%s\n", remain);
		permute(perm, remain, size, size);
		free(perm);
		free(remain);
		printf("%d done\n", size);
	}
	
	return 0;
}
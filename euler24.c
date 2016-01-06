#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int permute(char *perm, char *remain, int size, int r_size, int count)
{
	if(r_size == 0) {
		if(count == 999999) {
			printf("%s\n", perm);
			exit(0);
		}
		if(count < 1000) {
			printf("%s\n", perm);
		}
		return count + 1;
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
		count = permute(perm, newremain, size, r_size - 1, count);
	}
	
	return count;
}

int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("INPUT: ./euler24 [1-10]\n");
		return 1;
	}
	int size = atoi(argv[1]);
	
	char *perm = malloc(size * sizeof(char));
	char *remain = malloc(size * sizeof(char));
	for(int i = 0; i < size; i++) {
		remain[i] = '0' + i;
	}
	
	permute(perm, remain, size, size, 0);
	
	return 0;
}
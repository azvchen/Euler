#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

long pow10(int n)
{
	long i = 1;
	while(n > 0) {
		i *= 10;
		n--;
	}
	return i;
}

/**	three digits starting from the dth digit, with total digits == 10
 *	dig3(1234567890, 2) == 234 */
int dig3(long n, int d)
{
	return ((int)(n / pow10(8 - d))) % 1000;
}

int is_special(long n)
{
	return dig3(n, 2) % 2 == 0 && dig3(n, 3) % 3 == 0 
		&& dig3(n, 4) % 5 == 0 && dig3(n, 5) % 7 == 0 
		&& dig3(n, 6) % 11 == 0 && dig3(n, 7) % 13 == 0 
		&& dig3(n, 8) % 17 == 0;
}

long permute(char *perm, char *remain, int size, int r_size)
{
	if(r_size == 0) {
		//printf("%s\n", perm);
		long n = atol(perm);
		if(is_special(n)) {
			printf(" %s\n", perm);
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
		sum += permute(perm, newremain, size, r_size - 1);
	}
	free(newremain);
	
	return sum;
}

int main(int argc, char *argv[])
{
	int size = 10;
	
	char *perm = malloc(size * sizeof(char));
	char *remain = malloc(size * sizeof(char));
	for(int i = 0; i < size; i++) {
		remain[i] = '0' + i;
	}
	printf("%ld\n", permute(perm, remain, size, size));
	free(perm);
	free(remain);
	
	return 0;
}
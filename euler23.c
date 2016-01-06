#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int isabundant(int n)
{
	int sum = 0;
	for(int f = 1; f < (int)(sqrt(n) + 1); f++) {
		if(n % f == 0) {
			sum += f;
			if(f * f != n && f != 1) {
				sum += n / f;
			}
		}
	}
	return sum > n;
}

void printarray(int *array, size_t size)
{
	for(int i = 0; i < size; i++) {
		printf("%d: %d\n", i, array[i]);
	}
}

int main(int argc, char *argv[])
{
	int *abundants = malloc(10000 * sizeof(int));
	int size = 0;
	for(int n = 0; n < 28124; n++) {
		if(isabundant(n)) {
			abundants[size] = n;
			size++;
		}
	}
	//printarray(abundants, size);
	
	int *integers = malloc(30000 * sizeof(int));
	for(int i = 0; i < 30000; i++) {
		integers[i] = i;
	}
	for(int a = 0; a < size; a++) {
		for(int b = 0; b < size; b++) {
			integers[abundants[a] + abundants[b]] = 0;
		}
	}
	
	long sum = 0;
	for(int i = 0; i < 30000; i++) {
		printf("%d: %d\n", i, integers[i]);
		sum += integers[i];
	}
	printf("\nsum: %ld\n", sum);
	
	free(abundants);
		
	return 0;
}
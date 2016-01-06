#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 13

int main(int argc, char *argv[])
{
	FILE *file = fopen("num8.txt", "r");
	
	int product = 1, max_product = 1;
	int count = 0;
	int *storage = malloc(SIZE * sizeof(int));
	int i = 0;
	char c;
	
	for(i = 0; i < SIZE; i++) {
		c = fgetc(file);
		if(c >= '0' && c <= '9') {
			storage[i] = c - '0';
			product *= storage[i];
			if(product > max_product)
				max_product = product;
		} else if(c == EOF) {
			printf("Only %d digits, product was: %d", i, product);
			return 1;
		}
	}
	i = 0;
	
	while((c = fgetc(file)) != EOF) {
		if(c >= '0' && c <= '9') {	// is number
			product = product / storage[i] * (c - '0');
			storage[i] = c - '0';
			i = (i+1) % 13;
			if(product > max_product)
				max_product = product;
		}
	}
	
	printf("%d\n", max_product);
	
	return 0;
}
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//#define SIZE 6000

int isprime(int n)
{
	for(int i = 2; i < sqrt(n) + 1; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

void trianglepath(int **triangle)
{
	for(int i = 15 - 2; i >= 0; i--) {
		for(int j = 0; j <= i; j++) {
			triangle[i][j] += triangle[i+1][j] > triangle[i+1][j+1] ? 
								triangle[i+1][j] : triangle[i+1][j+1];
		}
	}
}

int namevalue(char *name)
{
	int sum = 0;
	for(int i = 0; i < strlen(name); i++) {
		sum += name[i] - 'A' + 1;
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int SIZE = 6000;
	char **names = malloc(SIZE * sizeof(char *));
	names[0] = malloc(SIZE * 20 * sizeof(char));
	for(int i = 1; i < SIZE; i++) {
		names[i] = names[0] + i * 20;
	}
	
	FILE *file = fopen("names22.txt", "r");
	size_t *len = malloc(sizeof(size_t));
	char *line = fgetln(file, len);
	printf("names: %p, len: %p, line: %p\n", names, len, line);
	printf("len: %lu", *len);
	int i = 0;
	while(line != NULL) {
		char *token = strsep(&line, ",");
		memcpy(names[i], &token[1], strlen(token) - 2);
		i++;
		//printf("%d: %s\n", names[i]);
	}
	fclose(file);
	free(len);
	SIZE = i;
	
	qsort(names[0], SIZE, 20, strcmp);
	long sum = 0;
	for(int i = 0; i < SIZE; i++) {
		printf("%d: %s\n", i, names[i]);
		sum += (i + 1) * namevalue(names[i]);
	}
	printf("%ld\n", sum);
	
	for(int i = 0; i < SIZE; i++) {
		free(names[i]);
	}
	free(names);
	fclose(file);
	
	return 0;
}
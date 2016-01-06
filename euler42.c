#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int valueofc(char c)
{
	return c - 'A' + 1;
}

/**	alloc and return array of size n+1 containing first n triangle numbers, and zero
 *	t[n] == t_n == n(n+1)/2
 *	t[0] = 0, t[k] = t[k-1] + k
 */
int *get_triangles(int n)
{
	int *triangles = malloc((n + 1) * sizeof(int));
	for(int i = 0; i < n + 1; i++)
		triangles[i] = triangles[0];
	int tri = 1, k = 1;
	while(tri < n) {
		triangles[tri] = 1;
		tri += ++k;
	}
	return triangles;
}

int main(int argc, char *argv[])
{
	int count = 0;
	int *triangles = get_triangles(300);
	
	FILE *file = fopen("words42.txt", "r");
	int value = 0;
	while(!feof(file)) {
		char c = fgetc(file);
		if(c == ',') {
			if(triangles[value])
				count++;
			value = 0;
		} else if(c != '"') {
			value += valueofc(c);
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}
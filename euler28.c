#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int size = 1001;
	
	int sum = 1;
	int level = 1;
	int count = 1;
	int i = 3;
	
	while(i <= size * size) {
		sum += i;
		if(count == 4) {
			count = 1;
			level++;
		} else {
			count++;
		}
		i += 2 * level;
	}
	
	printf("%d\n", sum);
	
	return 0;
}
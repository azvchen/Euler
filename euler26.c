#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int cycle(const int denom, int *decimal, int *remains)
{
	decimal[0] = 0;
	remains[0] = 1;
	int i = 0;
	int c = 0;
	
	while(1) {
		int numer = remains[i] * 10;
		i++;
		decimal[i] = numer / denom;
		remains[i] = numer % denom;
		
		if(remains[i] == 0) {
			break;
		}
		for(int j = 0; j < i; j++) {
			if(decimal[j] == decimal[i] && remains[j] == remains[i]) {
				c = i - j;
			}
		}
		
		if(c > 0) {
			break;
		}
	}
	
	printf("%d: %d\n", denom, c);
	
	return c;
}

int main(int argc, char *argv[])
{
	int longest = 0;
	int longest_cycle = 0;
	int *decimal = malloc(1000 * sizeof(int));
	int *remains = malloc(1000 * sizeof(int));
	
	for(int i = 2; i < 1000; i++) {
		int cycle_length = cycle(i, decimal, remains);
		if(cycle_length > longest_cycle) {
			longest = i;
			longest_cycle = cycle_length;
		}
	}
	
	printf("---\n%d: %d\n", longest, longest_cycle);
	
	return 0;
}
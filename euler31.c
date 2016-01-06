#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int addcoins(int total, int c, int *coins)
{
	if(coins[c] == 1) {
		if(total < 0) return 0;
		else return 1;
	}
	
	int count = 0;
	for(int i = 0; i <= total / coins[c]; i++) {
		count += addcoins(total - i * coins[c], c - 1, coins);
	}
	return count;
}

int main(int argc, char *argv[])
{
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
	int num_coins = sizeof(coins) / sizeof(int);
	int total = 200;
	
	int count = addcoins(total, num_coins-1, coins);
	
	printf("%d\n", count);
	
	return 0;
}
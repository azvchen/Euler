#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int is_prime(int n)
{
	for(int i = 2; i < sqrt(n) + 1; i++) {
		if(n % i == 0) return 0;
	}
	return 1;
}

int main(int argc, char *argv[])
{
	for(int n = 3; n <= INT_MAX; n += 2) {
		if(!is_prime(n)) {
			int i = 1;
			int s;
			while((s = 2 * i*i) < n) {
				if(is_prime(n-s)) {
					printf("%d = %d + 2x%d^2\n", n, n-s, i);
					break;
				}
				i++;
			}
			if(s > n) {
				printf("%d\n", n);
				return 0;
			}
		}
	}
	
	printf("No int found.\n");
		
	return 0;
}
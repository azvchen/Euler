#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int pow10(int n)
{
	int i = 1;
	while(n > 0) {
		i *= 10;
		n--;
	}
	return i;
}

int digits_in(int n)
{
	int d = 0;
	while(n > 0) {
		n /= 10;
		++d;
	}
	return d;
}

int digit_at(int n, int d)
{
	return (n / pow10(d)) % 10;
}

int main(int argc, char *argv[])
{
	long product = 1;
	int targets[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
	
	int n = 0;
	int i = 1;
	int digit = 1;
	while(n < 7) {
		if(digit + digits_in(i) > targets[n]) {
			product *= digit_at(i, digits_in(i) - (targets[n] - digit) - 1);
			//printf("%d %ld\n", i, digits_in(i) - (targets[n] - digit) - 1);
			n++;
		}
		digit += digits_in(i);
		i++;
	}
	
	printf("Product: %ld\n", product);
	
	return 0;
}
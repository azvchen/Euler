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

int digits_in(long n)
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

int is_pan(long n)
{
	int digits = digits_in(n);
	if(digits != 9) return 0;
	for(int i = 0; i < digits; i++) {
		if(digit_at(n, i) == 0)
			return 0;
		for(int j = i + 1; j < digits; j++)
			if(digit_at(n, i) == digit_at(n, j))
				return 0;
	}
	return 1;
}

long make_cp(int base, int n)
{
	long catprod = 0;
	for(int i = 1; i <= n; i++) {
		long prod = base * i;
		catprod *= pow10(digits_in(prod));
		catprod += prod;
	}
	return catprod;
}

int main(int argc, char *argv[])
{
	long max_cp = 123456789;
	for(int base = 1; base < 10000; base++) {
		for(int n = 2; n < 10; n++) {
			long catprod = make_cp(base, n);
			if(digits_in(catprod) == 9 && is_pan(catprod)) {
				printf("%d %d: %ld\n", base, n, catprod);
				if(catprod > max_cp) {
					max_cp = catprod;
				}
			}
		}
	}
	
	printf("%ld\n", max_cp);
	
	return 0;
}
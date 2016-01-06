#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int ndigits(int i)
{
	int n = 0;
	while(i > 0) {
		i /= 10;
		++n;
	}
	return n;
}

int digit_at(int i, int d)
{
	while(d > 0) {
		i /= 10;
		--d;
	}
	return i % 10;
}

int is_self_unique(int n)
{
	int digits = ndigits(n);
	for(int i = 0; i < digits; i++) {
		if(digit_at(n, i) == 0)
			return 0;
		for(int j = i + 1; j < digits; j++)
			if(digit_at(n, i) == digit_at(n, j))
				return 0;
	}
	return 1;
}

int is_both_unique(int n, int m)
{
	for(int i = 0; i < ndigits(n); i++)
		for(int j = 0; j < ndigits(m); j++)
			if(digit_at(n, i) == digit_at(m, j))
				return 0;
	return 1;
}

int is_product_pan(int product)
{
	if(!is_self_unique(product))
		return 0;
	for(int f = 1; f <= 99; f++)
		if(product % f == 0) {
			int g = product / f;
			if(ndigits(f) + ndigits(g) + ndigits(product) == 9 && 
				is_self_unique(f) && is_self_unique(g) && is_both_unique(f, g) && 
				is_both_unique(f, product) && is_both_unique(g, product)) {
				printf("%d * %d = %d\n", f, g, product);
				return 1;
			}
		}
	return 0;
}

main()
{
	int sum = 0;
	
	int product;
	for(product = 1234; product <= 9876; ++product)
		if(is_product_pan(product))
			sum += product;
	
	printf("%d\n", sum);
}
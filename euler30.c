#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int iround(double d) { return d > 0 ? (int)(d + .5) : (d < 0 ? (int)(d - .5) : 0); }

int checkdigits(int n, int p)
{
	int sum = 0;
	int i = n;
	while(i > 0) {
		sum += iround(pow(i % 10, p));
		i = i / 10;
	}
	return sum == n;
}

int main(int argc, char *argv[])
{
	int sum = 0;
	int size = 5;
	
	for(int n = 10; n < pow(10, size + 1); n++) {
		if(checkdigits(n, size)) {
			sum += n;
		}
	}
	
	printf("%d\n", sum);
	
	return 0;
}
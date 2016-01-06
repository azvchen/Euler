#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int numer;
	int denom;
} Frac;

Frac *init_frac(int n, int d)
{
	Frac *frac = malloc(sizeof(Frac));
	frac->numer = n;
	frac->denom = d;
	return frac;
}

float eval_frac(Frac *frac)
{
	return ((float)frac->numer) / frac->denom;
}

Frac *simplify_frac(Frac *frac)
{
	int n = frac->numer, d = frac->denom;
	for(int f = 2; f < sqrt(frac->numer) + 1; f++) {
		if(n % f == 0 && d % f == 0) {
			n = n / f;
			d = d / f;
			f--;
		}
	}
	return init_frac(n, d);
}

void multiply_frac(Frac *f, Frac *f2)
{
	f->numer *= f2->numer;
	f->denom *= f2->denom;
}

void print_frac(Frac *frac)
{
	printf("%d/%d", frac->numer, frac->denom);
}

void printl_frac(Frac *frac)
{
	print_frac(frac);
	printf("\n");
}

int main(int argc, char *argv[])
{
	Frac *agg = init_frac(1, 1);
	for(int a = 10; a <= 99; a++) {
		for(int b = 1; b <= 9; b++) {
			Frac *frac = init_frac(a, (a % 10) * 10 + b);
			float value = eval_frac(frac);
			if(value < 1 && value == ((float)(a / 10)) / (float)(b)) {
				printl_frac(frac);
				multiply_frac(agg, frac);
			}
			free(frac);
		}
	}
	printl_frac(simplify_frac(agg));
	
	return 0;
}
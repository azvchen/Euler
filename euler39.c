#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int check_right(int ai, int bi, int ci)
{
	long a = ai;
	long b = bi;
	long c = ci;
	return a*a + b*b == c*c;
}

int pcount(int perim)
{
	int count = 0;
	for(int a = 1; a < perim / 2 + 1; a++) {
		for(int b = 1; b < perim / 2 && b + a < perim; b++) {
			if(check_right(a, b, perim - a - b)) {
				count++;
				//printf("%d: %d %d %d\n", perim, a, b, perim - a - b);
			}
		}
	}
	return count / 2;
}

int main(int argc, char *argv[])
{
	int max_perim = 0;
	int max_count = 0;
	
	for(int perim = 3; perim <= 1000; perim++) {
		int count = pcount(perim);
		if(count > max_count) {
			max_count = count;
			max_perim = perim;
		}
	}
	
	printf("%d: %d\n", max_perim, max_count);
	
	return 0;
}
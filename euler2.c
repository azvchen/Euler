#include <stdio.h>

int main(int argc, char *argv[])
{
	int sum = 0;
	
	int e = 1;
	int f = 1;
	
	while(f < 4e6) {
		if(f % 2 == 0) sum += f;
		
		int t = f;
		f = e + f;
		e = t;
	}
	
	printf("%d\n", sum);
	
	return 0;
}
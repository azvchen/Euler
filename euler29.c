#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// THIS DOES NOT WORK FOR SOME REASON, I WANT MY BIG INTS
struct pair {
	int a;
	int b;
};

void init_pair(struct pair *temp, int a, int b)
{
	temp->a = a;
	temp->b = b;
}

struct pair *create_pair(int a, int b)
{
	struct pair *p = malloc(sizeof(struct pair));
	p->a = a;
	p->b = b;
	return p;
}

int intround(double d) { return d > 0 ? (int)(d + .5) : (int)(d - .5); }
int signofd(double d) { return d > 0 ? 1 : (d < 0 ? -1 : 0); }
int signofi(int i) { return i > 0 ? 1 : (i < 0 ? -1 : 0); }
int findroot(int a, int b)
{
	int r = 0;
	while(b > 1) {
		if(b % a == 0) {
			b = b / a;
			r++;
		}
		else {
			return 0;
		}
	}
	return r;
}
int compare(struct pair *mp, struct pair *np)
{
	struct pair m = *mp;
	struct pair n = *np;
	
	return signofd(powl(m.a, m.b) - powl(n.a, n.b));
	/*
	int root;
	if(m.a < n.a) root = findroot(m.a, n.a);
	else root = findroot(n.a, m.a);
	
	if(root == 0) {
		return signofd(powl(m.a, m.b) - powl(n.a, n.b));
	} else if(root == 1) {
		return signofd(m.b - n.b);
	}
	
	if(m.a < n.a) {
		return signofi(m.b - n.b * root);
	} else {
		return signofi(n.b - m.b * root);
	}*/
}

int main(int argc, char *argv[])
{
	int size = 100;
	int total = (size - 1) * (size - 1);
	struct pair *list = malloc(total * sizeof(struct pair));
	
	int i = 0;
	for(int a = 2; a <= size; a++) { // for every base
		for(int b = 2; b <= size; b++) { // for every exponent
			struct pair *temp = create_pair(a, b);
			memcpy(&list[i], temp, sizeof(struct pair));
			i++;
			free(temp);
		}
	}
	
	int (*compare_cv)(const void *m, const void *n) = &compare;
	qsort(list, total, sizeof(struct pair), compare_cv);
	
	int count = total;
	printf("%d: %d %d\n", 0, list[0].a, list[0].b);
	for(int i = 1; i < total; i++) {
		printf("%d: %d %d\n", i, list[i].a, list[i].b);
		if(compare(&list[i], &list[i - 1]) == 0) {
			/*if(compare(&list[i], &list[i-2]) != 0) {
				printf("%d: %d %d\n", i-1, list[i-1].a, list[i-1].b);
			}
			printf("%d: %d %d\n", i, list[i].a, list[i].b);*/
			count--;
		}
	}
	
	printf("Not sorted at: ");
	for(int i = 1; i < total; i++) {
		if(compare(&list[i-1], &list[i]) > 0) {
			printf("%d ", i);
			//exit(1);
		}
	}
	printf("\n");
	
	printf("%d\n", count);
		
	free(list);
	
	return 0;
}
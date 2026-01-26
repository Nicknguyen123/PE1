#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, l;
	printf("Area = ");
	scanf("%d", &a);
	printf("Length = ");
	scanf("%d", &l);
	float r = (float)a / l;
	float p = 0;
	p = (float)(l + r) * 2;
	printf("Perimeter = %.1f", p);

	return 0;
}
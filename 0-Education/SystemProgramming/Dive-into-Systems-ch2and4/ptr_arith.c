#include <stdio.h>

int main(void)
{
#define N 5
	int a[N], * p, * q, * r, i;
	p = a;      // Same as p = &a[0];
	q = a + 3;    // Same as q = &a[3]; Adding an integer to a pointer
	r = q - 2;    // Same as p = &a[1]; Subtracting an integer from a pointer
	i = q - p;    // Same as i = 3; Subtracting pointers results in the difference in the number of elements between two pointers
	// Comparison pointer depends on the relative position of two pointers
	if (p > q) printf(¡°pointer p has a small index value¡±); // (p > q) is 0
	if (p < q) printf(¡°pointer p has a large index value¡±); // (p < q) is 1
	if (p == q) printf(¡°equal index value¡±);         		// (p == q) is 0




	double b[2], * s, * t;
	s = &b[0];
	t = s + 1;

	printf("%d\n", t - s);
	printf("%d\n", (int)t - (int)s);
	printf("%d\n", sizeof(double));

	return 0;
}
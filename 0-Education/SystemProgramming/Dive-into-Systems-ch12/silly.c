#include <stdio.h>
#include <limits.h>

int silly(int a) {
	int b = a+1;
	printf("%d, %x\n", b, b);
	printf("%d, %x\n", a, a);
	return b > a;
}

int main() {
	int max = INT_MAX;
	printf("%d\n", silly(max));
}


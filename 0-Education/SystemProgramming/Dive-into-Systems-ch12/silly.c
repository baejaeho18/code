#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int silly(int a) {
	return (a + 1) > a;
}

int main() {
	int max = INT_MAX;

	printf("%d", silly(max));
}


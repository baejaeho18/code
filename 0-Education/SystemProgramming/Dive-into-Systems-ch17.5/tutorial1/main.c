#include "foo.h"
#include "bar.h"

int main() {
    int x = foo(bar());
    printf("Result is %d\n", x);
    return 0;
}



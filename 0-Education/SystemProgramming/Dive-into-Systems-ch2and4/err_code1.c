#include <stdio.h>

main()
{
    int a = -1, b = 0, c = 2;

    if (a < b < c)
        printf("a < b < c\n");
    else
        printf("a >= b or b >= c\n");

    if (3 > c > 1)
        printf("1 < c < 3");
    else
        printf("1 >= c or c >= 3");

    return 0;
}

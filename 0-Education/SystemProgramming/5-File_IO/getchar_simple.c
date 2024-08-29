#include <stdio.h>
#include <unistd.h>

int getchar(void) {
    static char c;
    if (read(0, &c, 1) == 1)  
        return c;
    else
        return EOF;
}

int main() {
    int c;

    printf("Enter some characters (Press Enter to quit):\n");

    while ((c = getchar()) != EOF) {
        if (c == '\n')  
            break;
        putchar(c);  
    }

    printf("\nGoodbye!\n");

    return 0;
}

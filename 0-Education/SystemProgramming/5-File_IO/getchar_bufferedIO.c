#include <stdio.h>
#include <unistd.h>

int getchar(void) {
    static char base[1024];
    static char *ptr;       
    static int cnt = 0;     

    if (cnt--) 
        return *ptr++;  

    cnt = read(0, base, sizeof(base));
    if (cnt <= 0) 
        return EOF; 
    ptr = base;  
    return getchar(); 
}

int main() {
    int c;

    printf("Enter text :\n");

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    printf("\nFinished reading input.\n");

    return 0;
}

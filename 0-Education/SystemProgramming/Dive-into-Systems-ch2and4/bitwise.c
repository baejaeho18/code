#include <stdio.h>

void bdisp(c) int c;
{
    int i, wc;
    for (i=15; i>=0; i--) {
        wc = (c >> i) & 0x01;
        printf("%1d", wc);
    }
    printf("\n");
}

int main() {
    
    int x = 123, y;

    printf("%7s%15s\t%s\n", "decimal", "hexadecimal", "bit pattern");
    printf("%7d%15x\t", x, x); bdisp(x);

    y = ~x;
    printf("%7d%15x\t", y, y); bdisp(y);

    y = x | 128;
    printf("%7d%15x\t", y, y); bdisp(y);

    y = ~x >> 2;
    printf("%7d%15x\t", y, y); bdisp(y);
    
    y = x << 8;
    printf("%7d%15x\t", y, y); bdisp(y);

    return 0;
}



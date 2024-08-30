#include <stdio.h>

int main() {
    char str[100];
    int i, j, len, len1;

    printf("Enter any string: ");
    fgets(str, sizeof(str), stdin);
    
    for (len = 0; str[len] != '\0' && str[len] != '\n'; len++)
        ;
    str[len] = '\0';

    len1 = 0;
    for (i = 0; i < (len - len1);) {
        if (str[i] == str[i + 1]) {
            for (j = i; j < (len - len1); j++)
                str[j] = str[j + 1];
            len1++;
        } else {
            i++;
        }
    }

    printf("String after removing characters: %s\n", str);
    return 0;
}

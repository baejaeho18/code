#include <stdio.h>

int main()
{
    char* s;
    int i;

    fgets(s);

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a'&& s[i] <= 'z')
            s[i] = s[i] -'a'+ 'A'; /* capitalize */
        if (s[i] >= 'A'&& s[i] <= 'Z')
            s[i] = s[i] - 'A'+ 'a'; /* convert to lower*/
    }
    puts(s);

    return 0;
}

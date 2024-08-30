#include <stdio.h>

int main() 
{
    FILE *fp;
    int iCount;
    char arr[6] = "Hello";
    
    fp = fopen("sample.txt", "wb");
    iCount = fwrite(arr, 1, 5, fp);
    fclose(fp);
    return 0;
}

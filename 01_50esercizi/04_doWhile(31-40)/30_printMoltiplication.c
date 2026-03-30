#include <stdio.h>

int main() {
    printf("\n exercise n30 \n");

    int n,i = 1;
    printf("\n Enter a number: \n");
    scanf("%d", &n);

    do{
        printf("%d x %d = %d\n", n, i, n * i);
        i++;
    } while (i <= 10);
    
    return 0;
}
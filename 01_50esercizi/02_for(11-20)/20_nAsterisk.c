#include <stdio.h>

int main() {
    printf("\n exercise n20 \n");

    int n, i;

    printf("Enter a natural number: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        printf("*");
    }

    printf("\n the number of asterisk was print is: %d\n",i);
    return 0;
}
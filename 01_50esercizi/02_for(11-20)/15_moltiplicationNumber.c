#include <stdio.h>
int main() {
    printf("\n exercise n15 \n");

    int n, molt = 1;
    
    printf("Enter a positive integer: \n");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        molt *= i;
    }
        printf("The moltiplication is: %d\n", molt);

    return 0;
}
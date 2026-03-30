#include <stdio.h>

int main() {
    printf("\n exercise n14 \n");

    int n, sum = 0;

    printf("Enter a positive integer: \n");
    scanf("%d", &n);
    
    if (n < 1)
    {
        printf("Please enter a positive integer greater than 0.\n");
        return ;
    }
    
    for (int i = 0; i <=n; i++)
    { 
        sum += i;
    }
    printf("The sum is: %d\n", sum);
    
    return 0;
}
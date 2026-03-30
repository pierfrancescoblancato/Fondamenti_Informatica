#include <stdio.h>
#define SIZE 10

int main() {
    int number[SIZE], i;
    
    printf("Enter  %d number: ", SIZE);
    for(i = 0; i < SIZE; i++) {
        scanf("%d", &number[i]);  
    }
    
    printf("You entered:");
    for(i = 0; i < SIZE; i++) {
        printf("%d ", number[i]);  
    }
    printf("\n");

    printf("The inverted array: ");
    for ( i = SIZE - 1; i >= 0; i--)
    {
        printf("%d ", number[i]);
    }
    
    return 0;
}

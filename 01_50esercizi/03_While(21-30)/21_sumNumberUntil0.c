#include <stdio.h>

int main() {
    printf("\n exercise n21 \n");

    int n,sum=0;
    
    printf("Enter an integer: ");
    scanf("%d", &n);

    while(n != 0){

        sum += n;  
        printf("Enter another integer (0 to stop): ");
        scanf("%d", &n);
        
    }     

    printf("Sum of numbers is: %d\n", sum);
    return 0;
    
}
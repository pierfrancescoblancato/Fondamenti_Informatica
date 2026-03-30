#include <stdio.h>

int main() {
    printf("\n exercise n26 \n");

    int n;
    
    printf("Enter an integer number: ");
    scanf("%d", &n);

    while(n % 2 != 0){

        printf("Enter another integer (even number to stop): ");
        scanf("%d", &n);
        
        if(n % 2 == 0){
            printf("Even number entered : %d, stopping.\n", n);
            break;
        }

        printf("Enter number is: %d is odd, continue... \n", n);
        
    }     

    return 0;
}
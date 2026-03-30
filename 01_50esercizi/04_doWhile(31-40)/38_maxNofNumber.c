#include <stdio.h>

int main() {
    printf("\n exercise n38 \n");

    int n, max = 0 ;
    
    do {
        printf("Enter an integer number (or a non-integer to stop): \n");
        int result = scanf("%d", &n);

        if (result != 1) {
            //controlla se e' un input non intero
            printf("No integer input, stopping.\n");
            break;
        }
        
        if (n > max) {
            max = n;
        }
        
        printf("Current max: %d\n", max);
       
        
    } while (1);
    
    printf(" Max: %d\n", max);

    return 0;
}
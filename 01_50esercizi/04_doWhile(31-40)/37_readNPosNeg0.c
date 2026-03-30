#include <stdio.h>

int main() {
    printf("\n exercise n37 \n");

    int n, positiveCount = 0, negativeCount = 0, zeroCount = 0;
    int result;
    
    do {
        printf("Enter an integer number (or a non-integer to stop): \n");
        result = scanf("%d", &n);

        if (result != 1) {
            printf("No integer input, stopping.\n");
            break;
        }
        
        if (n == 0) {
            zeroCount++;
        } else if (n > 0) {
            positiveCount++;
        } else { 
            negativeCount++;
        }

    } while (1); 

    printf("\nPositive numbers entered: %d\n", positiveCount);
    printf("Negative numbers entered: %d\n", negativeCount);
    printf("Zeros entered: %d\n", zeroCount);
    return 0;
}
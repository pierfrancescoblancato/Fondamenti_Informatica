#include <stdio.h>

int main() {
    printf("\n exercise n41 \n");

    int n, sum = 0, count = 0;
    
    float average = 0;
    do {
        printf("Enter an integer number (or a non-integer to stop): \n");
        int result = scanf("%d", &n);

        if (result != 1) {
            //controlla se e' un input non intero
            printf("No integer input, stopping.\n");
            break;
        }

        sum+=n;
        count++;        
        
        average=(float)sum/count; //cast
        
        printf("Current averange: %.2f \n", average);
       
        
    } while (1);

    if (count > 0) {
        printf("Total numbers entered: %d\n", count);
        printf("Sum: %d\n", sum);
        printf("Average: %.2f\n", average);
    } else {
        printf("No numbers were entered.\n");
    }

    return 0;
}
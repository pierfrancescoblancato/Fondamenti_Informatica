#include <stdio.h>

int main() {
    printf("\n exercise n36 \n");

    int row = 0, currentRow = 0, currentCount = 0, i = 0;
    printf("Enter an integer number: \n");
    scanf("%d", &row);

    do {
        currentCount = 1;
        i = 0;
        
        do {

            printf("%d ", currentCount);  
            i++;
            currentCount++;
        } while (i <= currentRow);

       
        
        printf("\n");
        currentRow++;
        
    } while (currentRow < row);
        
    return 0;
}
#include <stdio.h>

int main() {
    printf("\n exercise n35 \n");

    int row = 0,currentRow = 0, i = 0;
    printf("Enter a integer numbers: \n");
    scanf("%d", &row);

    do
    {
          do
        {
            
            printf("*");
            i++;

        } while (i<=currentRow);
        
        i = 0;
        printf("\n");
        
        currentRow++;

    } while (currentRow < row );
        
    return 0;
}
#include <stdio.h>

int main() {
    
    int row,square,i=1;

    printf("Enter a Number greater of 0: ");
    scanf("%d", &row);

    if (row>0)
    {
        for(int i =1; i<=row;i++){
                square = i*i;
                printf("the square of %d is %d: \n", i, square);
            }
    }else{
        printf("Row must be bigger than 0\n");
        return 1;
    }
    return 0;
}
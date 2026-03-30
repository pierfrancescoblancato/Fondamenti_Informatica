#include <stdio.h>

int main() {
    
    int row,square,i=1;

    printf("Enter a Number greater of 0: ");
    scanf("%d", &row);
    
    if(row>0){
        while(row>0){

        square = i*i;
        printf("the square of %d is %d: \n", i, square);
         
        row--;
        i++;
    }

    }else{
        printf("Row must be bigger than 0\n");
    }
    
}
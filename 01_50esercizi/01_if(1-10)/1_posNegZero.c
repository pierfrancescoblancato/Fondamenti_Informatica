#include <stdio.h>

int main() {
    printf("\n exercise n1 \n");

    int n;
    
    printf("Enter a integer number: \n");
    scanf("%d", &n);

    if(n > 0){
        printf("the number is positive \n");
    }
    else if(n < 0){
        printf("the number is negative \n");
    }
    else{
        printf("the number is zero \n");  
    }        

        return 0;
}
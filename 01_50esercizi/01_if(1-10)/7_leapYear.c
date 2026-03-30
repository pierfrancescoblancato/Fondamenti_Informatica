#include <stdio.h>

int main() {
    printf("\n exercise n7 \n");

    int n;
    
    printf("Enter an year: ");
    scanf("%d", &n);

    if(n % 100 != 0 && n % 400 != 0){
        if(n % 4 == 0){
            printf("the year %d is a leap year\n", n);  
        }
        else{
            printf("the year %d is not a leap year\n", n);  
        }
    }
    else{
            printf("the year %d is not a leap year\n", n);  
        }
    return 0;
}
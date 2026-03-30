#include <stdio.h>

int main() {
    printf("\n exercise n4 \n");

    int n;
    
    printf("Enter a integer number: \n");
    scanf("%d", &n);
    if(n % 2 == 0){
        printf("the number is even\n");
    }
    else{
        printf("the number is odd\n");  
    }
        return 0;
}
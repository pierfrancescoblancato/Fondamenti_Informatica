#include <stdio.h>


int main() {
    printf("\n exercise n47 \n");

    int n,divisor;  
    
    printf("Enter number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if(n % i == 0 ){
            printf("%d, ", i);
        }else{
        }
    }
    return 0;
}
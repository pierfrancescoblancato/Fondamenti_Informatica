#include <stdio.h>


int main() {
    printf("\n exercise n47 \n");
    // Leggere numeri finché la somma non supera 100 e stampare quanti numeri sono stati inseriti

    printf("\n exercise n47 \n");

    int n, sum = 0 ,count=0;  
    
    do
    {
        printf("Enter number: ");
        scanf("%d", &n);

        if (n > 0 && n <= 100)
        {
            sum+=n;
            count++;
            printf("Actual sum is %d and numbers enter is %d \n",sum, count);
            
        }else{
            printf("%d is not a valid number \n",n);
            continue;
        }
        
    } while (sum < 100);
    
    return 0;
}
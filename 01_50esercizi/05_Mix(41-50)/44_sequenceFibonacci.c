#include <stdio.h>

int main() {
    printf("\n exercise n44 \n");

    int lenght,n1 = 0 ,n2 = 1,next;  
    
    printf("Enter n: ");
    scanf("%d", &lenght);
    
    printf("%d, ",n1);
    for (int i = 3; i <= lenght; i++)
    {
        next=n1+n2;
        printf("%d, ",next);
        
        n1 = n2;
        n2 = next;
    }

    return 0;
}
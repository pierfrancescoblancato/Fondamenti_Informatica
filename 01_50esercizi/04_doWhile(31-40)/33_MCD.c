#include <stdio.h>

int main() {
    printf("\n exercise n33 \n");

    int n1,n2;
    int rest;

    printf("Enter a 2 number: \n");
    scanf("%d %d", &n1, &n2);

    int a = n1, b = n2;

    // se b è zero, MCD è l'altro, percio a 
    if (b == 0) {
        printf("MCD(%d, %d) = %d\n", n1, n2, a);
        return 0;
    }

    // Euclide algorithm for MCD calculation
    do
    {
        rest = a % b;
        a = b;
        b = rest;

    } while (b !=0);
    
    printf("MCD(%d, %d) = %d\n", n1, n2, a);
    
    return 0;
}
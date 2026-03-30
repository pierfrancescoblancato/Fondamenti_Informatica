#include <stdio.h>

int main() {
    printf("\n exercise n23 \n");

    int n, cont = 0;
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("the number must be positive!\n");
        return 1;
    }
    if (n == 0) {
        cont = 1;
    } else {
        while (n > 0) {
            n = n / 10; 
            n++;
        }
    }
    
    printf("the number have %d number/e\n", cont);
    
    return 0;
}
#include <stdio.h>

int main() {
    printf("\n exercise n28 \n");

    int n, i = 0;
    printf("Enter a natural number greatest of 0: ");
    scanf("%d", &n);

    if (n > 0)
    {
        while (i <= n) {
            printf("%d\n", i);
            i++;
        }
        
    }else{
        printf("The number is not natural greater than 0.\n");
        return 1;
    }

    return 0;
}
 
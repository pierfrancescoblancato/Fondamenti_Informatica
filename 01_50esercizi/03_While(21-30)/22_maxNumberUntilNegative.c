#include <stdio.h>

int main() {
    printf("\n exercise n22 \n");

    int n, max;

    printf("Enter an integer (negative to stop): ");
    scanf("%d", &n);

while(n > 0) {      
        max =n;
        printf("Enter another integer (negative to stop): ");  
        scanf("%d", &n);

        if(n > max) {
            max = n;
        }
    }
    printf("The maximum number entered is: %d\n", max);
    return 0;
}
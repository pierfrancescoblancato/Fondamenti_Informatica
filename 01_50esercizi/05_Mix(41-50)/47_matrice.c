#include <stdio.h>

int main() {
    printf("\n exercise n47 \n");

    int n = 0;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i == j) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");  // Add newline after each row
    }
    
    return 0;
}
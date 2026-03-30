#include <stdio.h>

int main() {
    printf("\n exercise n16 \n");

    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
    return 0;
}
#include <stdio.h>

int main() {
    printf("\n exercise n32 \n");

    int n;
    printf("Enter a number to check if it is prime (greatest of 2):\n");
    scanf("%d", &n);

    if (n < 2) {
        printf("%d is not prime\n", n);
        return 0;
    }

    int i = 2;
    int isPrime = 1;

    do {
        
        if (n % i == 0) {

            isPrime = 0;
            break;

        }

        i++;

    } while (i < n);

    if (isPrime) {
        printf("%d is prime\n", n);
    } else {
        printf("%d is not prime\n", n);
    }

    return 0;
}
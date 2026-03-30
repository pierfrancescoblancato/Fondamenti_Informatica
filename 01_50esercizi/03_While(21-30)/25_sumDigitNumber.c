#include <stdio.h>

int main() {
    printf("\n exercise n25 \n");
    int n, digit = 0, sumDigit = 0;

    printf("Enter a natural number greater than 0:\n");
    scanf("%d", &n);

    if (n > 0) {
        while (n != 0) {
            digit = n % 10;   // prende l'ultima cifra
            sumDigit += digit; // somma la cifra
            n = n / 10;       // rimuove l'ultima cifra
        }
    } else {
        printf("The number is not natural greater than 0.\n");
        return 1;
    }

    printf("The sum of the digits is: %d\n", sumDigit);

    return 0;
}

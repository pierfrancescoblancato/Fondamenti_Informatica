#include <stdio.h>

int main() {

    printf("\n exercise n47 \n");

    int pin;
    int savedPin = 12345;
    int attempts = 3;

    while (attempts > 0) {
        printf("Enter your pin (%d attempts): ", attempts);
        scanf("%d", &pin);

        if (pin < 0 || pin > 99999) {
            printf("Invalid number\n");
            continue;
        }

        if (pin == savedPin) {
            printf("The PIN is right\n");
            return 0;
        } else {
            attempts--;
            printf("Wrong PIN\n");
        }
    }

    printf("No attempts. Access blocked\n");
    return 0;
}

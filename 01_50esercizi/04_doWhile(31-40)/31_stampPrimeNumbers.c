#include <stdio.h>

int main() {
    printf("\n exercise n31 \n");

    int n = 0; 

    do {
        int isPrime = 1; // assumiamo che sia primo, "si" finche non si dimostra il contrario

        for (int i = 2; i < n; i++) {

            if (n % i == 0) {

                isPrime = 0; // abbiamo trovato un divisore, percio "no" 
                break;
            }
        }

        if (isPrime) {
            printf("%d\n", n);
        }

        n++;

    } while (n <= 100);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    int attempts = 5;

    srand(time(NULL));
    int nRandom = rand() % 5 + 1;

    for (int i = 1; i <= attempts; i++) {
        printf("Attempt %d of %d: ", i, attempts);
        scanf("%d", &n);

        if (n < 1 || n > 5) {
            printf("Invalid number\n");
            i--; 
            continue;
        }

        if (n == nRandom) {
            printf("Nice, the number was %d\n", nRandom);
            return 0;
        } else {
            printf("Wrong number\n");
        }
    }

    printf("No attempts. The number was: %d\n", nRandom);
    return 0;
}

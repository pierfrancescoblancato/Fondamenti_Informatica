#include <stdio.h>

int main() {
    printf("\n exercise n34 \n");

    int n1, n2;
    int rest;

    printf("Enter 2 numbers: \n");
    scanf("%d %d", &n1, &n2);

    int a = n1, b = n2;

    // se uno dei due è zero, MCD è l'altro, invece il mcm = 0
    if (a == 0 && b == 0) {
        printf("MCD(0, 0) non è definito.\n");
        return 1;
    }
    if (a == 0) {
        printf("MCD(%d, %d) = %d\n", n1, n2, b);
        printf("mcm(%d, %d) = 0\n", n1, n2);
        return 0;
    }
    if (b == 0) {
        printf("MCD(%d, %d) = %d\n", n1, n2, a);// se b è zero, MCD è l'altro, percio a 
        printf("mcm(%d, %d) = 0\n", n1, n2);
        return 0;
    }

    // Euclide algorithm for MCD calculation
    do {
        rest = a % b;
        a = b;
        b = rest;
    } while (b != 0);

    int mcd = a;
    printf("MCD(%d, %d) = %d\n", n1, n2, mcd);

    int mcm = (n1 * n2) / mcd;
    printf("mcm(%d, %d) = %d\n", n1, n2, mcm);

    return 0;
}
#include <stdio.h>

int main() {
    int i, j;
    double capital = 100, rate;
    int years;

    printf("Enter interest rate and number of years: ");
    scanf("%lf %d", &rate, &years);

    printf("Rate: %.2f%% Years: %d\n", rate, years);
    printf("Year 0: %.2f\n", capital);

    double balance[years];

    for (i = 1; i <= years; i++) {
        capital = capital + (capital * rate / 100.0);
        balance[i - 1] = capital;
    }

    printf("| Anno  |  Bilancio    |\n");
    for (j = 0; j < years; j++) {
        printf("|   %d   |   %.2f €   |\n", j + 1, balance[j]);
    }

    return 0;
}

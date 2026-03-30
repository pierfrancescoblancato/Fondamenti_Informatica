#include <stdio.h>

//Questa funzione read_int_in_range serve per leggere un numero intero da tastiera validando che sia compreso in un intervallo specificato.

int read_int_in_range(const char prompt[], int min_value, int max_value) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            continue;
        }

        if (value >= min_value && value <= max_value) {
            return value;
        }
    }
}
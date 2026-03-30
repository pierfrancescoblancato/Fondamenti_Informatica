#include <stdio.h>
#include <stdlib.h>   // per rand() e srand()
#include <time.h>     // per time()

int main() {
    printf("\n exercise n45 \n");

    int n,temp;  
    int array[6] = {0};

    printf("Enter n: ");
    scanf("%d", &n);

    srand(time(NULL));// senza questo avremo generazioni sempre iuguali, serve per cambiare il seme di generazione
    
    for (int i = 0; i < n; i++)
    {
        temp = rand() % 6 + 1;
        printf("%d, ",temp);
        array[temp-1]++;//incrementare il valore memorizzato in un array in una posizione specifica
    }
    printf("\n");

    for (int i = 0; i < 6; i++) {
    printf("face %d: %d times\n", i+1, array[i]);
}

    return 0;
}
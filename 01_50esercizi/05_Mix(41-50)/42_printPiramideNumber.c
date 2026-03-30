#include <stdio.h>

int main() {
    printf("\n exercise n42 \n");

    int height, i, j, count = 1;  // count parte da 1
    
    printf("Enter height of the piramide: ");
    scanf("%d", &height);
        
    // PRIMO CICLO: controlla le righe della piramide
    // i = numero della riga corrente (da 1 a height)
    for(i = 1; i <= height; i++) {
        
        // SECONDO CICLO: stampa gli spazi per centrare la piramide
        // Alla riga i-esima stampa (height - i) spazi
        // Esempio con height=4:
        // - Riga 1: stampa 3 spazi (4-1)
        // - Riga 2: stampa 2 spazi (4-2)
        // - Riga 3: stampa 1 spazio (4-3)
        // - Riga 4: stampa 0 spazi (4-4)
        for(j = 1; j <= height - i; j++) {
            printf(" ");
        }
        
        // TERZO CICLO: stampa i numeri nella riga
        // Stampa (2*i - 1) numeri tutti uguali a 'count'
        // Formula: 2*i - 1 perché:
        // - Riga 1: 2*1-1 = 1 numero
        // - Riga 2: 2*2-1 = 3 numeri
        // - Riga 3: 2*3-1 = 5 numeri
        // - Riga 4: 2*4-1 = 7 numeri
        // Tutti i numeri nella stessa riga sono uguali a 'count'
        for(j = 1; j <= (2 * i - 1); j++) {
            printf("%d", count);  // Stampa sempre lo stesso numero 'count'
        }
        
        count++;  // Incrementa count per la prossima riga
        
        printf("\n");  // Vai a capo per la prossima riga
    }
    
    return 0;
}
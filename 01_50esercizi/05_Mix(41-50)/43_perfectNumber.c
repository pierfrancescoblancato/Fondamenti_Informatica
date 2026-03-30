#include <stdio.h>

int main() {
    printf("\n exercise n43 \n");

    int n, sum = 0;

    printf("Enter a number: ");
    scanf("%d",&n);

    //esempio con '6' i divisori di 6 sono: 1,2,3 escludendo se stesso, 
    //un numero perfetto e' quando la somma dei suoi divisori e' uguale al numero di partenza, 6 = 1 + 2 + 3
    
    // Ciclo per trovare i divisori
    // I divisori propri non possono superare n/2 (eccetto n stesso)
    for(int i = 1; i <= (n/2); i++){
        // Se i divide n senza resto, allora i è un divisore
        if (n % i == 0)
        {
            // Aggiungo il divisore alla somma totale
            sum += i;
        }
    }

    
    if(sum == n){
        printf("the number %d is perfect \n",n);
    } else {
        printf("the number %d isnt perfect \n",n);
    }
    
    return 0;
}
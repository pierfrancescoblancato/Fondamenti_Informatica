/* Test per numeri primi */
#include <stdio.h>
#include <stdbool.h> /* Serve per avere il valore bool in C */


bool is_prime(int n){
    int divisor;

    if (n <= 1){
        return false;
    }
    for (divisor = 2; divisor * divisor <= n; divisor++){
        if (n % divisor == 0){
            return false;
        }
        // Il return true; è dentro il ciclo for,  viene eseguito alla prima iterazione, senza controllare tutti i divisori.
        //la funzione controllava solo se 2 divide n, e poi ritornava subito true, dichiarando primi anche numeri come 9, 15, 21, ecc.
        //return true; spostato fuori dal ciclo
    }
    return true;

}

int main(void){
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (is_prime(n)){
        printf("Prime\n");
    }
    else{
        printf("Not prime\n");
    }
    
    return 0;
}
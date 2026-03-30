#include <stdio.h>
int readRange(const char prompt[], int min_value, int max_value) {
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

void fillArray(int array[],int lenght){
    for(int i = 0; i < lenght; i++){
        printf("enter a number: %d: ",i);
        scanf("%d ",&array[i]);
    }
}
void reverse(int array[],int lenght){
    for (int i = 0; i < lenght/2; i++) { // si scorre solo meta array perche per ogni giro si scambiano 2 elemeneti(inizio e fine)
        int temp = array[i];//Salvi il valore array a indice i in una variabile temp
        array[i] = array[lenght - 1 - i];//N - 1 è l’ultimo indice dell’array, N - 1 - i ti dà l’indice “specchiato” rispetto a i,prendi l’elemento in fondo e lo metti nella posizione di sinistra
        array[lenght - 1 - i] = temp; // con temp(vecchio valore a sinistra) lo metti nella posizione destra
    }
}
void printArray(int array[],int lenght){
    for(int i = 0; i < lenght; i++){
        printf("%d, ",array[i]);
    }
}


int main() {
    
    
    int lenght = readRange("enter a size of array", 1 , 30);
    int array[lenght];
    fillArray(array,lenght);


    printf("\nArray:\n");    
    printArray(array,lenght);

    reverse(array,lenght);

    printf("\nReversed array:\n");
    printArray(array,lenght);


    return 0;
}

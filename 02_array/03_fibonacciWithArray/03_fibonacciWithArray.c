#include <stdio.h>
// esercizio 44 ma con funzioni e array(da completare,non ancora implementato)
int readInt(const char prompt[]) {
    int value;
    while (1) {
        printf("%s", prompt);

        if (scanf("%d", &value) == 1) {
            return value;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Input not valid. Try again.\n");
    }
}

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

int sum(int a, int b){return a+b;}

void fibonacci(int lenght){
    int i = 0, n1 = 0 ,n2 = 1,next;
    printf("%d, ",n1);

    while(i<= lenght){
        // swap(&n1, &n2);
        next = sum(n1,n2);
        printf("%d, ",next);

        n1 = n2;
        n2 = next;

        i++;
    }

}

int main() {    
    int lenght = readInt("Enter a number greater 1: ");
    fibonacci(lenght);
    return 0;
}
#include <stdio.h>

int main() {
    printf("\n exercise n17 \n");
    int sum = 0;

    for (int i = 0; i <= 100; i++)
    {
        printf("natural number: %d\n", i);
        sum += i;
    }
        
    printf("total sum of naturla number from 0 at 100: %d\n", sum);

    return 0;
}
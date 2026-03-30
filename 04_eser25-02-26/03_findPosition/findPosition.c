#include <stdio.h>

void findPositions(int array[], int length, int find) {
    int count = 0;
    
    printf("The number %d is found at positions: ", find);
    for (int i = 0; i < length; i++) {
        if (find == array[i]) {
            printf("%d ", i);
            count++;
        }
    }
    
    if (count == 0) {
        printf("none");
    }
    
    printf("\nThe number %d appears %d times in the array\n", find, count);
}

int main(void) {
    int votes[] = {2, 3, 4, 5, 6, 7, 4, 3, 2, 8};
    int arrayLength = sizeof(votes) / sizeof(votes[0]);

    int numberBySearch = 8;
    findPositions(votes, arrayLength, numberBySearch);
    
    numberBySearch = 4;
    findPositions(votes, arrayLength, numberBySearch);
    
    return 0;
}
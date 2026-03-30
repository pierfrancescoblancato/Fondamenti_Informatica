#include <stdio.h>

void printArray(int array[], int length){
    for(int i = 0; i < length; i++){
        printf("%d \n", array[i]);
    }
}

void readArray(int array[], int length){
    printf("Enter integer numbers for the array:\n");
    for (int i = 0; i < length; i++)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &array[i]);  // <-- rimosso lo spazio
    }
}

int summarize(int array[], int length){
    int currentSum = 0;
    for(int i = 0; i < length; i++){
        currentSum += array[i];
        printf("%d ", currentSum);
    }
    return currentSum;
}

float avg(int sum, float elements){
    return (float)sum / elements;  // <-- cast corretto
}

int searchArrayLength(){
    int dim = 0;
    printf("Enter size of array: ");
    scanf("%d", &dim);
    return dim;
}

int main(void){
    int arrayLength = searchArrayLength();  // <-- aggiunto ;
    int votes[arrayLength];
    
    readArray(votes, arrayLength);
    
    printf("The array is: \n");
    printArray(votes, arrayLength);

    int sumArray = summarize(votes, arrayLength);
    printf("\nThe sum of array is: %d \n", sumArray);

    float average = avg(sumArray, arrayLength);
    printf("The average of array is: %.2f \n", average);
    
    return 0;
}
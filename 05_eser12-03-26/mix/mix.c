#include <stdio.h>
#define ARRAY_SIZE 50

// leggere un valore
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
//leggere N voti
void readVotes(int array[], int length){
    printf("Enter integer numbers for the array:\n");
    for (int i = 0; i < length; i++)
    {
        char prompt[64];
        snprintf(prompt, sizeof(prompt), "Inserire voto %d (0..30): ", i);
        printf("Enter the %d element: ", i);
        array[i] = readRange(prompt, 0, 30);
    }
}
//stampare l’array
void printArray(int array[], int length){
    for(int i = 0; i < length; i++){
        printf("%d \n", array[i]);
    }
}
//calcolare media, minimo, massimo
int min(int array[],int lenght ){
    int tmp = array[0];
    for (int i = 1; i < lenght; i++)
    {
        if(tmp > array[i]){
            tmp = array[i];
        }
    }
    return tmp;
}

int max(int array[],int lenght ){
    int tmp = array[0];
    for (int i = 1; i < lenght; i++)
    {
        if(tmp < array[i]){
            tmp = array[i];
        }
    }
    return tmp;
}

int summarize(int array[], int length){
    int currentSum = 0;
    for(int i = 0; i < length; i++){
        currentSum += array[i];
    }
    return currentSum;
}

float avg(int sum, float elements){
    return (float)sum / elements;  
}
//contare voti sopra una soglia
int countAboveThreshold( int array[], int length, int theshold) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] >= theshold) {
            count++;
        }
    }
    return count;
}

//cercare un voto specifico
int targetValue( int array[],int lenght, int target){
    for(int i = 0; i < lenght; i++){
        if(array[i] == target){
            return i;
        }
    }
    return -1;
}

int main(void){
    int votes[ARRAY_SIZE];
    
    int count = readRange("Number you want enter: (0..30): ", 1, ARRAY_SIZE);
    readVotes(votes,count);

    printf("\n you has insered this votes:\n");
    printArray(votes,count);

    int minValue = min(votes,count);
    int maxValue = max(votes,count);
    float average = avg(summarize(votes,count),count);

    printf("the minimum value is: %d \n", minValue);
    printf("the maximun value is: %d \n", maxValue);
    printf("the average of the total votes is: %.2f \n",average);

    printf("Which number do you want to search? (0, 30)");
    int theshold = readRange("Enter the theshold: (0, 30)",0,30);
    int votesAboveThreshold = countAboveThreshold(votes,count,theshold);
    printf("Number of votes above or equal to %d: %d\n", theshold, votesAboveThreshold);

    int target = readRange("Enter the target value to search: (0, 30)",0,30);
    int idx = targetValue(votes,count,target);
    if(idx != -1){
        printf("The target value %d is found at index: %d\n", target, idx);
    } else {
        printf("The target value %d is not found in the array.\n", target);
    }

    return 0;
}
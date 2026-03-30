#include <stdio.h>
#include "array_utils.h"

/* --- Input utilities --- */
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

/* --- Array I/O --- */
void readArrayWithRange(int array[], int length, const char basePrompt[], int min_value, int max_value) {
    for (int i = 0; i < length; i++) {
        char prompt[128];
        snprintf(prompt, sizeof(prompt), "%s %d (%d..%d): ", basePrompt, i, min_value, max_value);
        array[i] = readRange(prompt, min_value, max_value);
    }
}

void readFixedArray(int array[], int length) {
    printf("Inserisci %d numeri interi:\n", length);
    for (int i = 0; i < length; i++) {
        while (scanf("%d", &array[i]) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }
}

void printArray(const int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", array[i]);
    }
}

void printArrayInline(const int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void printArrayReversed(const int array[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/* --- Basic statistics --- */
int arrayMin(const int array[], int length) {
    int tmp = array[0];
    for (int i = 1; i < length; i++) {
        if (tmp > array[i]) tmp = array[i];
    }
    return tmp;
}

int arrayMax(const int array[], int length) {
    int tmp = array[0];
    for (int i = 1; i < length; i++) {
        if (tmp < array[i]) tmp = array[i];
    }
    return tmp;
}

int arraySum(const int array[], int length) {
    int s = 0;
    for (int i = 0; i < length; i++) s += array[i];
    return s;
}

float arrayAvg(int sum, int elements) {
    return (float)sum / (float)elements;
}

/* --- Search / counts --- */
int countAboveThreshold(const int array[], int length, int threshold) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] >= threshold) count++;
    }
    return count;
}

int findTargetIndex(const int array[], int length, int target) {
    for (int i = 0; i < length; i++) {
        if (array[i] == target) return i;
    }
    return -1;
}
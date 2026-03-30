#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

/* --- Input utilities --- */
int readRange(const char prompt[], int min_value, int max_value);

/* --- Array I/O --- */
void readArrayWithRange(int array[], int length, const char basePrompt[], int min_value, int max_value);
void readFixedArray(int array[], int length);
void printArray(const int array[], int length);
void printArrayInline(const int array[], int length);
void printArrayReversed(const int array[], int length);

/* --- Basic statistics --- */
int arrayMin(const int array[], int length);
int arrayMax(const int array[], int length);
int arraySum(const int array[], int length);
float arrayAvg(int sum, int elements);

/* --- Search / counts --- */
int countAboveThreshold(const int array[], int length, int threshold);
int findTargetIndex(const int array[], int length, int target);

#endif // ARRAY_UTILS_H
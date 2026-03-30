#include <stdio.h>

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

int sum(int currentSum, int number){
    currentSum += number;
    return currentSum;
}

int count(int currentCount){
    return currentCount + 1;
}



int main() {
    int number = 1, totalSum = 0, numberCount = 0;
    int posCount = 0, negCount = 0;

    while (number != 0) {
        number = readInt("Enter an integer number (0 to stop): ");

        if (number != 0) {
            totalSum = sum(totalSum, number);
            numberCount = count(numberCount);

            if (number >= 0){
                posCount++;
            }else{
                negCount++;
            }
        }
    }

    printf("The total sum is: %d\n", totalSum);
    printf("The total numbers entered are: %d\n", numberCount);
    printf("Positive numbers: %d\n", posCount);
    printf("Negative numbers: %d\n", negCount);

    return 0;
}

#include <stdio.h>

int readMinutes(char prompt[]) {
    int m;
    printf("%s", prompt);
    scanf("%d", &m);
    return m;
}

int calculateExtraHours(int minutes) {
    int extra = minutes - 120;
    return (extra + 59) / 60;
}

int calculateCost(int minutes) {
    if (minutes <= 30) {
        return 1;
    } else if (minutes <= 120) {
        return 3;
    } else {
        return 3 + calculateExtraHours(minutes);
    }
}
int isValid(int minutes) {
    return minutes >= 0;
}
void printError() {
    printf("Error: the minuts not be negative.\n");
}

void printResult(int cost) {
    printf("total import: %d €\n", cost);
}



int main() {
    int minutes = readMinutes("Enter the parking time in minutes: ");

    if (!isValid(minutes)) {
        printError();
        return 1;
    }

    int cost = calculateCost(minutes);
    printResult(cost);
    return 0;
}
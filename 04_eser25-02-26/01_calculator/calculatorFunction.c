#include <stdio.h>

void printMenu() {
    printf("----MENU----\n");
    printf(" 1. sum\n");
    printf(" 2. difference\n");
    printf(" 3. multiplication\n");
    printf(" 4. division\n");
    printf(" 5. rest of division\n");
    printf(" 0. exit\n");
}

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

float readFloat(const char prompt[]) {
    float value;
    while (1) {
        printf("%s", prompt);

        if (scanf("%f", &value) == 1) {
            return value;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Input not valid. Insert a real number.\n");
    }
}

float sum(float a, float b) { return a + b; }
float diff(float a, float b) { return a - b; }
float molt(float a, float b) { return a * b; }

float divide(float a, float b) {
    if (b == 0) {
        printf("Error: division by zero.\n");
        return 0.0f;
    }
    return a / b;
}

int restDivision(float a, float b) {
    if (b == 0) {
        printf("Error: division by zero.\n");
        return 0;
    }
    return (int)a % (int)b;
}

void validateChoice(int choice) {
    if (choice == 0) {
        printf("Exit.\n");
        return;
    }

    float v1 = readFloat("Enter value1: ");
    float v2 = readFloat("Enter value2: ");

    switch (choice) {
        case 1:
            printf("Sum = %.2f\n", sum(v1, v2));
            break;

        case 2:
            printf("Difference = %.2f\n", diff(v1, v2));
            break;

        case 3:
            printf("Multiplication = %.2f\n", molt(v1, v2));
            break;

        case 4:
            printf("Division = %.2f\n", divide(v1, v2));
            break;

        case 5:
            printf("Rest of division = %d\n", restDivision(v1, v2));
            break;

        default:
            printf("Invalid choice.\n");
    }
}

void loopChoice() {
    int choice;
    do {
        choice = readFloat("Enter one choice: ");
        validateChoice(choice);
    } while (choice != 0);
}

int main(void) {
    printMenu();
    loopChoice();
    return 0;
}

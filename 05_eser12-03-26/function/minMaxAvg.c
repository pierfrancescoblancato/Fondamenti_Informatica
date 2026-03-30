#include <stdio.h>
int readRange(const char prompt[], int min_value, int max_value){
    int value;
    while (1){
        printf("%s", prompt);

        if (scanf("%d", &value) != 1){
            int c;
            while ((c = getchar()) != '\n' && c != EOF){} //clear the buffer to handle invalid input
            continue;
        }

        if (value >= min_value && value <= max_value){
            return value;
        }
    }
}

int sum(int x, int y){
    return x + y;
}

double avg(long x, int y){
    return (double)x / y;
}

int min(int currentValue,int newValue){
    if (newValue < currentValue){
        return newValue;
    }else{
        return currentValue;
    }
}

int max(int currentValue,int newValue){
    if (newValue > currentValue)
    {
        return newValue;
    }else{
        return currentValue;
    }
}
int main(){
    int temperature;
    int summarize = 0;
    int minTemp = 9999;
    int maxTemp = -9999;
    int numTemp = readRange("Enter a number of temperature(1,...20): ", 1, 20);

    for (int i = 0; i < numTemp; i++){
        temperature = readRange("Enter a  temperature(-50,..,-50): ", -50, 50);
        summarize = sum(summarize, temperature);

        minTemp = min(minTemp,temperature);
        maxTemp = max(maxTemp,temperature);
    }
    printf("\nMinimum temperature: %d\n", minTemp);
    printf("Maximum temperature: %d\n", maxTemp);

    printf("The averange of the temperature is %.2f\n", avg(summarize, numTemp));

    return 0;
}

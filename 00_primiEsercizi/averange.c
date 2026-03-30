#include <stdio.h>

int main() {
    
    int i = 22;
    int a = 35;

        int sum = i + a;
        printf("the sum of %d and %d is %d\n", i, a, sum);

        float avg = sum / 2.0;
        printf("the averange of %d and %d is %.2f \n", i, a, avg);

        return 0;
}
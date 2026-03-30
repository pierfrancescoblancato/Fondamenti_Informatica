#include <stdio.h>

int main() {
    printf("\n exercise n18 \n");

    int count = 0;
    
    for (int i = 3; i <= 100; i += 3) {
        count++;
    }

    printf("count of multiples of 3 between 0 and 100: %d /n", count);
  
    return 0;
}
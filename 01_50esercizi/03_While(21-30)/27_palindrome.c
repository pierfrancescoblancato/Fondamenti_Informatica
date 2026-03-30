#include <stdio.h>

int main() {
    printf("\n exercise n27 \n");

    int n,original, reverse = 0;
    printf("Enter a natural number greatest of 0: ");
    scanf("%d", &n);

    original = n;
    if (n > 0)
    {
        while (n != 0) {
            reverse = reverse * 10 + n % 10;

            n = n / 10;
        }
        
    }else{
        printf("The number is not natural greater than 0.\n");
        return 1;
    }

    if(reverse == original){
        printf("The number is palindrome.\n");  
    }else{
        printf("The number is not palindrome.\n");
        return 1;
    }

    return 0;
}
 
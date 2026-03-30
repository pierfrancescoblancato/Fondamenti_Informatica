#include <stdio.h>

int main() {
    printf("\n exercise n6 \n");

    int n;
    
    printf("Enter an integer vote(0-30): ");
    scanf("%d", &n);

    if(n < 18){
        printf("insufficient\n");
    }
    else if(n >=18 && n <=21){
        printf("sufficient\n");
    }
    else if(n >=22 && n <=27){
        printf("good\n");
    }
    else if(n >=28 && n <=30){
        printf("excellent\n");
    }
    else{
        printf("invalid vote\n");  
    }

    return 0;
}
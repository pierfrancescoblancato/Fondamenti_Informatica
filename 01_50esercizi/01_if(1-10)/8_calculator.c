#include <stdio.h>

int main() {
    printf("\n exercise n8 \n");

    int a,b,result;
    char symbol;// + - * /
    
    printf("Enter two a number integer: \n");
    scanf("%d %d", &a, &b);

    printf("Enter an operator (+ - * /): \n");
    scanf(" %c", &symbol);

    if(symbol== '+'){
        result = a + b;
        printf("the result is %d\n", result);
    }
    else if(symbol== '-'){
        result = a - b;
        printf("the result is %d\n", result);
    }
    else if(symbol== '*'){
        result = a * b;
        printf("the result is %d\n", result);
    }
    else if(symbol== '/' && b !=0  ){
        result = a / b;
        printf("the result is %d\n", result);   
    }
    else{
        printf("invalid operator\n");  
    }

    return 0;
}
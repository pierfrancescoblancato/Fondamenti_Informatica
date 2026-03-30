#include <stdio.h>
#include <stdlib.h> 
int readInt(char prompt[]) {
    int number;
    printf("%s", prompt);
    scanf("%d", &number);
    return number;
}

int isEven(int x){
    if(x % 2 == 0){
        printf("the number %d is even\n", x);
     return 1;
    }else{
        printf("The number %d is odd\n", x);
        return 0;
    }
}

int absInt(int x){

    return abs(x);
    // if(x < 0){
    //     return -x;
    // }
    // else{
    //     return  x;
    // }
}

int max2(int x, int y){
    if( x > y ){
        return x;
    }
    else{
        return y;
    }
}

int main() {
    int a = readInt("Enter a first number: ");
    int b = readInt("Enter a second number: ");

    isEven(a);
    isEven(b);

    printf("the absolute number of %d: is %d\n", a, absInt(a));
    printf("the absolute number of %d: is %d\n", b, absInt(b));

    int max = max2(a, b);
    printf("the gretest number between %d and %d is: %d\n", a, b, max);

    return 0;
}

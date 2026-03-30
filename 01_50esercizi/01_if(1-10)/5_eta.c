#include <stdio.h>

int main(){

    printf("\n exercise n5 \n");

    int age;
    printf("Enter your age: \n");
    scanf("%d", &age);

    if (age <= 0){
        printf("you have yet to be born\n");
    }
    else if (age <18){
        printf("you are a minor\n");
    }
    else if (age >=18 && age <65){
        printf("you are a adult\n");
    }
    else {
        printf("you are a old\n"); 
    }
       return 0;
}
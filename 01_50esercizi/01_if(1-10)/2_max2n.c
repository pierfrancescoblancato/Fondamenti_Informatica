#include <stdio.h>

int main() {
    printf("\n exercise n2 \n");
    int a = 4,b = 7;
    int max;

    if(a > b){
        max = a; 
    }
    else if(b > a){
        max = b;    
    }
    else{
        printf("the number is equal\n");  
    }        
    printf("the maximum number is %d\n", max);
        return 0;
}
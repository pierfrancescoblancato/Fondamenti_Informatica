#include <stdio.h>
int main() {
    printf("\n exercise n3 \n");
    
    int a = 4, b = 7, c = 5;
    int max;
    if(a>=b && a>=c){
        max = a; 
    }
    else if(b>=a && b>=c){
        max = b;    
    }
    else if(c>=a && c>=b){
        max = c;    
    }

    printf("the maximum number is %d\n", max);
    return 0;
}
#include <stdio.h>
int main() {
    printf("\n exercise n13 \n");

    for (int i = 0; i <= 100; i++)
    {
        if(i % 2 == 0){
            printf("%d\n", i);
        }
    }
    
    //bis
    for (int i = 0; i <= 100; i += 2)
    {
        printf("%d\n", i);
    }
    
    return 0; 
}
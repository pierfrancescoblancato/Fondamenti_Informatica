#include <stdio.h>

int main(void){
    int votes[] = {2,3,4,5,6,7,4,3,2,8};
    int arrayLenght = sizeof(votes) / sizeof(votes[0]);//divisione tra il byte di tutto l array diviso i byte di un singolo elemento

    // printf("%d \n",arrayLenght);

    for(int i = 0; i < arrayLenght; i++){
        printf("%d ",votes[i]);
    }

    return 0;
}
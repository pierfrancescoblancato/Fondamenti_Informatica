#include <stdio.h>

int max(int array[],int lenght ){
    int tmp = array[0];
    for (int i = 1; i < lenght; i++)
    {
        if(tmp < array[i]){
            tmp = array[i];
        }
    }
    return tmp;
}

int min(int array[],int lenght ){
    int tmp = array[0];
    for (int i = 1; i < lenght; i++)
    {
        if(tmp > array[i]){
            tmp = array[i];
        }
    }
    return tmp;
}

int main(void){
    int votes[] = {2,3,4,5,6,7,4,3,2,8};
    int arrayLenght = sizeof(votes) / sizeof(votes[0]);

    int maxVotes = max(votes, arrayLenght);
    int minVotes = min(votes, arrayLenght);

    printf("the max number in votes is: %d \n",maxVotes);
    printf("the min number in votes is: %d \n",minVotes);

    return 0;
}
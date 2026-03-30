#include <stdio.h>

int sum(int a, int b){
    return a + b;    
}
float average(int sum, int count){
    return (float)sum / count;    
}

int main(){
    int n1,n2;
    int sumTotal;
    float avg;

    printf("Enter 2 number: ");
    scanf("%d %d",&n1,&n2);
    
    sumTotal = sum(n1, n2);
    printf("la somma e': %d \n ", sumTotal);

    avg = average(sumTotal, 2);
    printf("la media e': %.2f \n ", avg);

}
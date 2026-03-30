#include <stdio.h>

int main() {
    printf("\n exercise n10 \n");

    int a,b,c;
    printf("Insert the lengths of the three sides of the triangle:\n");
    scanf("%d %d %d",&a,&b,&c);

    if(a+b>c && a+c>b && b+c>a) // Triangle theorem inequity
    {
        printf("The lengths %d , %d, %d can form a triangle.\n",a,b,c);
    } 
    else {
        printf("The lengths %d, %d, %d cannot form a triangle.\n",a,b,c);
    }

    return 0;
}
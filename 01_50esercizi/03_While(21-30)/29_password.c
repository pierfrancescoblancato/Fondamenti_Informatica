#include <stdio.h>

int main() {
    printf("\n exercise n27 \n");

    int password,password2=12345;
    printf("Enter a number password: ");
    scanf("%d", &password);

    
        while (password != password2) {
            printf("Enter a number password: ");
            scanf("%d", &password2);

            if(password != password2){
                printf("Wrong password, try again.\n");
            }else{
                printf("Password correct.\n");
                break;
            }
        }
    
    return 0;
}
 
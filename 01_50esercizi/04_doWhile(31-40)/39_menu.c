#include <stdio.h>

int main() {
    printf("\n exercise n39 \n");

    int choice;
    
    do {
        printf("\n=== MENU SEMPLICE ===\n");
        printf("1. Opzione 1\n");
        printf("2. Opzione 2\n");
        printf("3. Opzione 3\n");
        printf("4. Opzione 4\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Hai scelto l'opzione 1\n");
                break;
                
            case 2:
                printf("Hai scelto l'opzione 2\n");
                break;
                
            case 3:
                printf("Hai scelto l'opzione 3\n");
                break;
                
            case 4:
                printf("Hai scelto l'opzione 4\n");
                break;
                
            case 0:
                printf("Programma terminato\n");
                break;
                
            default:
                printf("Scelta non valida!\n");
                break;
        }
    } while (choice !=0);
    
    return 0;
}
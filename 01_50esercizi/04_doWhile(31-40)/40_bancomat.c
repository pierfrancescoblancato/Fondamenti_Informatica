#include <stdio.h>

int main() {
    printf("\n Exercise n40 \n");

    int choice, pin, money = 0, accountBalance = 0;

    printf("Enter your pin (ex. 12345): ");
    scanf("%d", &pin);  

    int savedPin = 12345;
    if (pin == savedPin) {
        printf("Welcome Pierfrancesco Blancato\n");  

        do {
            printf("\n=== SIMPLE MENU ===\n");
            printf("1. Withdraw money\n");
            printf("2. Deposit money\n");
            printf("3. Check balance\n");
            printf("0. Exit\n");
            printf("Choice: ");
            scanf("%d", &choice);
            
            switch(choice) {
                case 1:
                    printf("You selected: Withdraw money\n");
                    
                    printf("Choose how much to withdraw: ");
                    scanf("%d", &money); 

                    if (accountBalance < money) {
                        printf("Insufficient balance\n");
                    } else {
                        printf("One moment please...\n");
                        accountBalance -= money;
                        
                        printf("You have withdrawn: €%d\n", money);
                        printf("Your account balance: €%d\n", accountBalance);
                        printf("Operation completed. Goodbye!\n");
                    }
                    break;

                case 2:
                    printf("You selected: Deposit money\n");
                    
                    printf("Choose how much to deposit: ");
                    scanf("%d", &money);
                    
                    printf("Enter cash...\n");
                    printf("One moment please...\n");
                    accountBalance += money;
                    
                    printf("You have deposited: €%d\n", money);
                    printf("Your account balance: €%d\n", accountBalance);
                    printf("Operation completed. Goodbye!\n");
                    break;
                        
                case 3:
                    printf("You selected: Check balance\n");
                    printf("Your account balance: €%d\n", accountBalance);
                    break;
                        
                case 0:
                    printf("Exiting ATM portal\n");
                    break;
                        
                default:
                    printf("Invalid choice!\n");
                    break;
            }
        } while (choice != 0);
    } else {
        printf("Invalid PIN! Access denied.\n");
    }
    
    return 0;
}
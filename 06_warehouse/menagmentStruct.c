#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 30

struct Product {
    int code;
    char name[NAME_LENGTH];
    float price;
    int quantity;
};

int readInt(const char prompt[]) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            return value;
        }
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Input not valid. Try again.\n");
    }
}

int printMenu() {
    printf("\n=========================================\n");
    printf("              INVENTORY SYSTEM\n");
    printf("=========================================\n");
    printf("1. Insert new product\n");
    printf("2. Show all products\n");
    printf("3. Search product by code\n");
    printf("4. Update product price\n");
    printf("5. Update product quantity\n");
    printf("6. Register a sale\n");
    printf("7. Add new stock\n");
    printf("8. Calculate warehouse value\n");
    printf("0. Exit\n");
    printf("=========================================\n");
    return readInt("Select an option: ");
}

void addProduct(struct Product warehouse[], int position) {
    printf("Code: ");
    scanf("%d", &warehouse[position].code);
    printf("Name: ");
    scanf("%s", warehouse[position].name);
    printf("Price: ");
    scanf("%f", &warehouse[position].price);
    printf("Quantity: ");
    scanf("%d", &warehouse[position].quantity);
}

int findProductIndex(struct Product warehouse[], int count, int searchCode) {
    for (int i = 0; i < count; i++) {
        if (warehouse[i].code == searchCode) {
            return i;
        }
    }
    return -1;
}

void printArchive(struct Product warehouse[], int count) {
    if (count == 0) {
        printf("No products available.\n");
    } else {
        printf("\n%-10s %-20s %-10s %-10s\n", "CODE", "NAME", "PRICE", "QUANTITY");
        for (int i = 0; i < count; i++) {
            printf("%-10d %-20s %-10.2f %-10d\n",
                   warehouse[i].code, warehouse[i].name,
                   warehouse[i].price, warehouse[i].quantity);
        }
    }
}

int main() {
    struct Product warehouse[MAX_PRODUCTS];
    int count = 0;
    int choice;
    
    int searchedCode, index, qty;
    float newPrice;

    do {
        choice = printMenu();
        switch (choice) {
            case 1:
                if (count < MAX_PRODUCTS) {
                    addProduct(warehouse, count);
                    count++;
                } else {
                    printf("!!! ARCHIVE IS FULL !!!\n");
                }
                break;

            case 2:
                printArchive(warehouse, count);
                break;

            case 3:
                searchedCode = readInt("Enter code: ");
                index = findProductIndex(warehouse, count, searchedCode);
                if (index != -1) {
                    printf("Name: %s | Price: %.2f | Qty: %d\n", 
                           warehouse[index].name, warehouse[index].price, warehouse[index].quantity);
                } else {
                    printf("Product not found.\n");
                }
                break; 

            case 4:
                searchedCode = readInt("Enter code: ");
                index = findProductIndex(warehouse, count, searchedCode);
                if (index != -1) {
                    printf("New price: ");
                    scanf("%f", &newPrice);
                    warehouse[index].price = newPrice;
                    printf("Price updated.\n");
                } else {
                    printf("Product not found.\n");
                }
                break;

            case 5:
                searchedCode = readInt("Enter code: ");
                index = findProductIndex(warehouse, count, searchedCode);
                if (index != -1) {
                    warehouse[index].quantity = readInt("New quantity: ");
                    printf("Quantity updated.\n");
                } else {
                    printf("Product not found.\n");
                }
                break;

            case 6:
                searchedCode = readInt("Enter code: ");
                index = findProductIndex(warehouse, count, searchedCode);
                if (index != -1) {
                    qty = readInt("Quantity to sell: ");
                    if (qty > 0 && qty <= warehouse[index].quantity) {
                        warehouse[index].quantity -= qty;
                        printf("Sale completed.\n");
                    } else {
                        printf("Insufficient quantity or invalid input.\n");
                    }
                } else {
                    printf("Product not found.\n");
                }
                break;

            case 7:
                searchedCode = readInt("Enter code: ");
                index = findProductIndex(warehouse, count, searchedCode);
                if (index != -1) {
                    qty = readInt("Quantity to add: ");
                    if (qty > 0) {
                        warehouse[index].quantity += qty;
                        printf("Stock updated.\n");
                    }
                } else {
                    printf("Product not found.\n");
                }
                break;

            case 8: {
                float totalValue = 0;
                for (int i = 0; i < count; i++) {
                    totalValue += warehouse[i].price * warehouse[i].quantity;
                }
                printf("Total warehouse value: %.2f\n", totalValue);
                break;
            }

            case 0:
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
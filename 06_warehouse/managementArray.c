#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 30

int readInt(const char prompt[])
{
    int value;
    while (1)
    {
        printf("%s", prompt);

        if (scanf("%d", &value) == 1)
        {
            return value;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        printf("Input not valid. Try again.\n");
    }
}

int printMenu()
{
    int choice;
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
    printf("9. Calculate warehouse value\n");
    printf("0. Exit\n");
    printf("=========================================\n");

    return readInt("Select an option: ");
}

void addProduct(int codes[], char names[][NAME_LENGTH], float prices[], int quantities[], int position)
{
    printf("Code: ");
    scanf("%d", &codes[position]);

    printf("Name: ");
    scanf("%s", names[position]);

    printf("Price: ");
    scanf("%f", &prices[position]);

    printf("Quantity: ");
    scanf("%d", &quantities[position]);
}

int findProduct(int codes[], int count, int searchCode)
{
    for (int i = 0; i < count; i++)
    {
        if (codes[i] == searchCode)
        {
            return i;
        }
    }
    return -1;
}

void printArchive(int codes[], char names[][NAME_LENGTH], float prices[], int quantities[], int count)
{
    if (count == 0)
    {
        printf("No products available.\n");
    }
    else
    {
        printf("\n%-10s %-20s %-10s %-10s\n", "CODE", "NAME", "PRICE", "QUANTITY");
        for (int i = 0; i < count; i++)
        {
            printf("%-10d %-20s %-10.2f %-10d\n",
                   codes[i], names[i], prices[i], quantities[i]);
        }
    }
}

int main()
{
    int codes[MAX_PRODUCTS];
    char nameProduct[MAX_PRODUCTS][NAME_LENGTH];
    float prices[MAX_PRODUCTS];
    int quantities[MAX_PRODUCTS];
    int count = 0;
    int choice;
 
    int searchedCode, index, newQuantity, soldQuantity, addedQuantity;
    float newPrice, totalValue;

    do
    {
        choice = printMenu();
        switch (choice)
        {
        case 1:
            if (count < MAX_PRODUCTS)
            {
                printf("You selected (1):\n");
                addProduct(codes, nameProduct, prices, quantities, count);
                count++;
            }
            else
            {
                printf("!!! ARCHIVE IS FULL !!!\n");
            }
            break;

        case 2:
            printf("You selected (2):\n");
            printArchive(codes, nameProduct, prices, quantities, count);
            break;

        case 3:
            printf("You selected (3):\n");
            printf("Enter code: ");
            scanf("%d", &searchedCode);

            index = findProduct(codes, count, searchedCode);

            if (index != -1)
            {
                printf("Code: %d\n", codes[index]);
                printf("Name: %s\n", nameProduct[index]);
                printf("Price: %.2f\n", prices[index]);
                printf("Quantity: %d\n", quantities[index]);
            }
            else
            {
                printf("Product not found.\n");
            }
            break;

        case 4:
            printf("You selected (4):\n");
            printf("Enter code: ");
            scanf("%d", &searchedCode);

            index = findProduct(codes, count, searchedCode);

            if (index != -1)
            {
                printf("New price: ");
                scanf("%f", &newPrice);
                prices[index] = newPrice;
                printf("Price updated.\n");
            }
            else
            {
                printf("Product not found.\n");
            }
            break;

        case 5:
            printf("You selected (5):\n");
            printf("Enter code: ");
            scanf("%d", &searchedCode);

            index = findProduct(codes, count, searchedCode);

            if (index != -1)
            {
                printf("New quantity: ");
                scanf("%d", &newQuantity);
                quantities[index] = newQuantity;
                printf("Quantity updated.\n");
            }
            else
            {
                printf("Product not found.\n");
            }
            break;

        case 6:
            printf("You selected (6):\n");
            printf("Enter code: ");
            scanf("%d", &searchedCode);

            index = findProduct(codes, count, searchedCode);
            
            if (index != -1)
            {
                printf("Quantity to sell: ");
                scanf("%d", &soldQuantity);
                if (soldQuantity > 0 && soldQuantity <= quantities[index])
                {
                    quantities[index] = quantities[index] - soldQuantity;
                    printf("Sale completed.\n");
                }
                else
                {
                    printf("Insufficient quantity or invalid input.\n");
                }
            }
            else
            {
                printf("Product not found.\n");
            }
            break;

        case 7:
            printf("You selected (7):\n");
            printf("Enter code: ");
            scanf("%d", &searchedCode);
            
            index = findProduct(codes, count, searchedCode);
            
            if (index != -1)
            {
                printf("Quantity to add: ");
                scanf("%d", &addedQuantity);
                if (addedQuantity > 0)
                {
                    quantities[index] = quantities[index] + addedQuantity;
                    printf("Stock updated.\n");
                }
                else
                {
                    printf("Invalid quantity.\n");
                }
            }
            else
            {
                printf("Product not found.\n");
            }
            break;

        case 9:
            printf("You selected (9):\n");
            totalValue = 0;
            for (int i = 0; i < count; i++)
            {
                totalValue = totalValue + (prices[i] * quantities[i]);
            }
            printf("Total warehouse value: %.2f\n", totalValue);
            break;

        case 0:
            printf("You selected (0): EXIT NOW!\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
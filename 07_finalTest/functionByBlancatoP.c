// Library
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// MACRO
#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

#define MIN_MENU 1
#define MAX_MENU 13
typedef struct
{
    int id;
    char name[NAME_LENGTH];
    char brand[NAME_LENGTH];
    char category[NAME_LENGTH];
    float price;
    int quantity;
    int warranty;
    bool status;

} Product;

// By Mirko Di Natale
void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void pause()
{
    printf("\nPress Enter to be continue...");
    getchar();
    printf("\033[H\033[2J");
}

// By Pierfrancesco Blancato
int readInt(const char prompt[])
{
    int value;
    while (1)
    {
        printf("%s", prompt);

        if (scanf("%d", &value) == 1)
        {
            clearBuffer();
            return value;
        }

        clearBuffer();
        printf("Input not valid. Try again.\n");
    }
}

// By Pierfrancesco Blancato
float intToFloat(int value)
{
    return (float)value / 100;
}

// By Pierfrancesco Blancato
int readRange(const char prompt[], int min_value, int max_value)
{
    int value;
    while (1)
    {
        value = readInt(prompt);

        if (value >= min_value && value <= max_value)
        {
            return value;
        }
        printf("Error: value must be between %d and %d.\n", min_value, max_value);
    }
}

// By Mirko Di Natale
void printMenu()
{
    printf("\n--- ELECTRONICS STORE MANAGEMENT ---\n");
    printf("1. Insert new product\n");
    printf("2. Show all products\n");
    printf("3. Search product by code\n");
    printf("4. Update price\n");
    printf("5. Update available quantity\n");
    printf("6. Update product status\n");
    printf("7. Register sale\n");
    printf("8. Add stock\n");
    printf("9. Calculate total warehouse value\n");
    printf("10. Count products by category\n");
    printf("11. Find product with longest warranty\n");
    printf("12. Calculate average price\n");
    printf("13. Exit\n");
}

// N2 - By Pierfrancesco Blancato - Show all products in the warehouse
void printAllProducts(Product products[], int countProduct){
    if (countProduct == 0){
        printf("No products available.\n");
        return;
        }
    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");
    printf("| Cod | Name                 | Brand           | Cat          | Price    | Qty Avail. | Warr. (Mo) | Status     |\n");
    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");

    for (int i = 0; i < countProduct; i++){
        printf("| %-3d | %-20s | %-15s | %-12s | %-8.2f | %-10d | %-10d | %-10s |\n",
        products[i].id,
        products[i].name,
        products[i].brand,
        products[i].category,
        products[i].price,
        products[i].quantity,
        products[i].warranty,
        products[i].status ? "Avb" : "Not Avb.");
    }
    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");
}

// N5 - By Pierfrancesco Blancato - Update the available quantity of a product in the warehouse
void addQuantity(Product products[], int countProduct, int searchCode)
{
    int index = searchProduct(products, countProduct, searchCode);

    if (index == -1)
    {
        printf("\nProduct not found\n");
        return;
    }

    printf("\nSelected Product -> Code: %d, Name: %s, Actual Quantity: %d\n", products[index].id, products[index].name, products[index].quantity);

    int newQuantity = readInt("Enter a new quantity: ");
    products[index].quantity = newQuantity;

    if (products[index].quantity > 0)
    {
        products[index].status = true;
    }
    else
    {
        products[index].status = false;
    }

    printf("Update Successful -> Code: %d, Name: %s, New Quantity: %d\n\n", products[index].id, products[index].name, products[index].quantity);
}

// N10 - By Pierfrancesco Blancato - Count how many products are in a specific category in the warehouse
void countProductForCategory(Product products[], int countProduct)
{
    if (countProduct == 0)
    {
        printf("No products available.\n");
        return;
    }

    char searchCategory[50];
    printf("Enter the category you wish to search: ");
    scanf("%49s", searchCategory);
    clearBuffer();

    int counter = 0;

    for (int i = 0; i < countProduct; i++)
    {
        if (strcasecmp(products[i].category, searchCategory) == 0)
        {
            counter++;
        }
    }
    printf("\nCategory '%s' contains %d product(s).\n", searchCategory, counter);
}

int main()
{
    // Hardcoded data to test the code
    Product products[MAX_PRODUCTS] = {
        {1, "ThinkPad T14", "Lenovo", "Laptops", 1250.50, 12, 24, true},
        {2, "iPhone 15 Pro", "Apple", "Smartphones", 1199.99, 0, 12, false},
        {3, "AirPods Pro", "Apple", "Audio", 249.00, 30, 24, true},
        {4, "MX Master 3S", "Logitech", "Accessories", 99.90, 50, 24, true}};

    int count = 4;

    printf("\n--- INITIAL TABLE ---\n");
    printAllProducts(products, count);

    printf("\n--- TEST MODIFY QUANTITY ---\n");
    addQuantity(products, count);

    printf("\n--- UPDATED TABLE ---\n");
    printAllProducts(products, count);

    printf("\n--- Count for category ---\n");
    countProductForCategory(products, count);

    return 0;
}
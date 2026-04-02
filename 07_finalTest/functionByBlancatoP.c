#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 30

typedef struct
{
    int id;
    char name[50];
    char brand[50];
    char category[50];
    float price;
    int quantity;
    int warranty;
    bool status;
} Product;

// By Pierfrancesco Blancato
int readInt(const char prompt[])
{
    int value;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1)
        {
            int c;
            // Clear buffer if input is wrong (e.g., user enters a letter)
            while ((c = getchar()) != '\n' && c != EOF)
            {
            } 
            printf("Invalid input. Please enter an integer.\n");
            continue;
        }
        return value;
    }
}

// N2 - By Pierfrancesco Blancato
void printAllProducts(Product products[], int countProduct)
{
    if (countProduct == 0)
    {
        printf("No products available.\n");
        return;
    }

    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");
    printf("| Cod | Name                 | Brand           | Cat          | Price    | Qty Avail. | Warr. (Mo) | Status     |\n");
    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");
    
    for (int i = 0; i < countProduct; i++)
    {
        /*
         * FORMATTING SPACES:
         * %-3d   -> 3 spaces for ID
         * %-20s  -> 20 spaces for Name
         * %-15s  -> 15 spaces for Brand
         * %-12s  -> 12 spaces for Category
         * %-8.2f -> 8 spaces for Price (2 decimal places)
         * %-10d  -> 10 spaces for Quantity
         * %-10d  -> 10 spaces for Warranty
         * %-10s  -> 10 spaces for Status
         */
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

// Mock function to test addQuantity (da rimuovere quando marco la farà)
int searchProduct(Product products[], int countProduct)
{
    int searchId = readInt("Enter the Product Code (ID) to search: ");
    for (int i = 0; i < countProduct; i++)
    {
        if (products[i].id == searchId)
        {
            return i; // Return index if product is found
        }
    }
    return -1; // Return -1 if not found
}
// N5 - By Pierfrancesco Blancato
void addQuantity(Product products[], int countProduct)
{
    int index = searchProduct(products, countProduct); 

    if (index == -1)
    {
        printf("\nProduct not found\n");
        return;
    }

    printf("\nSelected Product -> Code: %d, Name: %s, Actual Quantity: %d\n", products[index].id, products[index].name, products[index].quantity);

    int newQuantity = readInt("Enter a new quantity: "); 
    products[index].quantity = newQuantity;
    
    printf("Update Successful -> Code: %d, Name: %s, New Quantity: %d\n\n", products[index].id, products[index].name, products[index].quantity);
}



// N10 - By Pierfrancesco Blancato
void countProductForCategory(Product products[], int countProduct)
{
   
}

int main()
{
    // Hardcoded data to test the code
    Product products[MAX_PRODUCTS] = {
        {1, "ThinkPad T14", "Lenovo", "Laptops", 1250.50, 12, 24, true},
        {2, "iPhone 15 Pro", "Apple", "Smartphones", 1199.99, 0, 12, false},
        {3, "AirPods Pro", "Apple", "Audio", 249.00, 30, 24, true},
        {4, "MX Master 3S", "Logitech", "Accessories", 99.90, 50, 24, true}
    };

    int count = 4;

    printf("\n--- INITIAL TABLE ---\n");
    printAllProducts(products, count);

    printf("\n--- TEST MODIFY QUANTITY ---\n");
    addQuantity(products, count);

    printf("\n--- UPDATED TABLE ---\n");
    printAllProducts(products, count);

    return 0;
}
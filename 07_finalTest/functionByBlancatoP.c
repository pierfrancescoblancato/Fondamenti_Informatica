#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 30

typedef struct{
    int id;
    char name[50];
    char brand[50];
    char category[50];
    float price;
    int quantity;
    int warranty;
    bool status;

} Product;

// Robust function that read a user input
// By Pierfrancesco Blancato
int readInt(const char prompt[]){
    int value;
    while (1){
        printf("%s", prompt);

        if (scanf("%d", &value) == 1){
            return value;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF){}
        printf("Input not valid. Try again.\n");
    }
}
// By Pierfrancesco Blancato
float intToFloat(int value){
    return (float)value/100;
}
// By Pierfrancesco Blancato
int readRange(const char prompt[], int min_value, int max_value)
{
    int value;
    while (1){
        printf("%s", prompt);
        if (scanf("%d", &value) != 1){
            int c;
            while ((c = getchar()) != '\n' && c != EOF){}
            continue;
        }

        if (value >= min_value && value <= max_value){
            return value;
        }
    }
}
void printMenu(){
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

// N2 - By Pierfrancesco Blancato
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

// N5 - By Pierfrancesco Blancato
void addQuantity(Product products[], int countProduct)
{
    int index = searchProduct(products, countProduct);

    if (index == -1){
        printf("\nProduct not found\n");
        return;
    }

    printf("\nSelected Product -> Code: %d, Name: %s, Actual Quantity: %d\n", products[index].id, products[index].name, products[index].quantity);

    int newQuantity = readInt("Enter a new quantity: ");
    products[index].quantity = newQuantity;

    printf("Update Successful -> Code: %d, Name: %s, New Quantity: %d\n\n", products[index].id, products[index].name, products[index].quantity);
}

// N10 - By Pierfrancesco Blancato
void countProductForCategory(Product products[], int countProduct){
    if (countProduct == 0){
        printf("No products available.\n");
        return;
    }
    char searchCategory[50];
    printf("Enter the category you wish to search: ");
    scanf("%49s", &searchCategory);
    int counter = 0;

    // Iterates through the array, checking each individual product
    for (int i = 0; i < countProduct; i++){ 
        
        // The strcmp function compares the current product's category with the searched one.
        // If it returns 0, it means the two strings are exactly identical.
        if (strcmp(products[i].category, searchCategory) == 0){
            
            // Match found: increment the product counter by 1
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
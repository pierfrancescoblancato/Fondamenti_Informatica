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

// N1 - By Mirko Di Natale - Add a new product to the warehouse
int addProduct(Product products[], int position)
{

    if (position >= MAX_PRODUCTS)
    {
        printf("\nERROR: Warehouse is full!\n");
        return position;
    }

    printf("\n--- INSERT NEW PRODUCT ---\n");
    products[position].id = readInt("Code ID: ");

    if (searchProduct(products, position, products[position].id) != -1)
    {
        printf("ERROR: ID %d already exists!\n", products[position].id);
        return position;
    }

    printf("Name: ");
    scanf("%49s", products[position].name);
    clearBuffer();

    printf("Brand: ");
    scanf("%49s", products[position].brand);
    clearBuffer();

    printf("Category: ");
    scanf("%49s", products[position].category);
    clearBuffer();

    int tempPrice = readInt("Price (in cents - NO DOTS/COMMAS - eg. 1250 for 12.50): ");
    products[position].price = intToFloat(tempPrice);

    products[position].quantity = readInt("Quantity: ");
    products[position].warranty = readInt("Warranty (months): ");

    if (products[position].quantity > 0)
    {
        products[position].status = true;
    }
    else
    {
        products[position].status = false;
    }

    printf("\n--- Product '%s' added successfully! ---\n", products[position].name);

    printf("Status set automatically to: ");
    if (products[position].status == true)
    {
        printf("Available\n");
    }
    else
    {
        printf("Not Available\n");
    }

    return position + 1;
}

// N2 - By Pierfrancesco Blancato - Show all products in the warehouse
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

// N3 - By Marco Ventimiglia - Search for a product by code
int searchProduct(Product products[], int countProduct, int searchCode)
{
    if (countProduct == 0)
    {
        printf("The warehouse is empty.\n");
        return -1;
    }

    for (int i = 0; i < countProduct; i++)
    {
        // Compare the id of the current product with the search code
        if (products[i].id == searchCode)
        {
            return i; // Code found, return the index of the product in the array
        }
    }
    return -1;
}

// N3.5 - By Marco Ventimiglia - Print the details of a product found by code
void printProductByCode(Product products[], int countProduct, int index)
{
    if (countProduct == 0)
    {
        printf("ERROR: Warehouse is empty\n");
        return;
    }

    if (index != -1 && index < countProduct)
    {
        printf("--- Product Found ---\n");
        printf("Code (ID): %d\n", products[index].id);
        printf("Name:      %s\n", products[index].name);
        printf("Brand:     %s\n", products[index].brand);
        printf("Category:  %s\n", products[index].category);
        printf("Price:     €%.2f\n", products[index].price);
        printf("Quantity:  %d\n", products[index].quantity);
        printf("Warranty:  %d months\n", products[index].warranty);
        // Print "Available" if status is true (1), otherwise "Out of Stock" (0)
        printf("Status:    %s\n", products[index].status ? "Available" : "Out of Stock");
        printf("---------------------\n");
    }
    else
    {
        printf("Product not found\n");
    }
}

// N4 - By Matteo Ventimiglia - Update the price of a product in the warehouse
void updatePrice(Product products[], int countProduct, int searchCode)
{
    if (countProduct == 0)
    {
        printf("The warehouse is empty.\n");
        return;
    }

    int index = searchProduct(products, countProduct, searchCode);
    if (index == -1)
    {
        printf("ERROR: Product with ID %d not found.\n", searchCode);
        return;
    }
    printf("Product found: %s\n", products[index].name);
    printf("Current price: %.2f\n", products[index].price);
    int newPrice = readInt("Enter the new price (in cents): ");
    products[index].price = intToFloat(newPrice);
    printf("Price updated successfully!\n");
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

// N6 - By Mirko Di Natale - Update the status of a product in the warehouse
void updateProductStatus(Product products[], int countProduct)
{

    int searchCode, index;

    if (countProduct == 0)
    {
        printf("The warehouse is empty.\n");
        return;
    }
    // If index is -1, the product was not found
    do
    {
        searchCode = readInt("Enter the code of the product: ");
        index = searchProduct(products, countProduct, searchCode);
        if (index == -1)
        {
            printf("\nError: Product not found. Try again.\n");
        }
    } while (index == -1);

    printf("\nSelected Product: --> Code: %d, Name: %s\n", products[index].id, products[index].name);
    printf("Current Status: ");
    if (products[index].status == true)
    {
        printf("Available\n");
    }
    else
    {
        printf("Not Available\n");
    }

    int choice = readRange("Enter new status (1 for Available, 0 for Not Available): ", 0, 1);

    if (choice == 1)
    {
        products[index].status = true;
        addQuantity(products, countProduct, searchCode);
    }
    else
    {
        products[index].status = false;
        products[index].quantity = 0;
    }
    printf("--- Update completed successfully! ---\n");
}

// N7 - By Marco Ventimiglia - Register a sale of a product in the warehouse
bool registerSale(Product products[], int countProduct, int searchId, int quantityToSell)
{
    if (quantityToSell <= 0)
    {
        printf("ERROR: Please enter a valid quantity.\n");
        return false;
    }

    int index = searchProduct(products, countProduct, searchId);

    if (index == -1)
    {
        printf("ERROR: Product with ID %d not found.\n", searchId);
        return false;
    }

    if (products[index].quantity < quantityToSell)
    {
        printf("ERROR: Out of stock for '%s'. Available: %d\n",
               products[index].name, products[index].quantity);
        return false;
    }

    // Calculation and update
    float totalAmount = products[index].price * (float)quantityToSell;
    products[index].quantity -= quantityToSell;

    if (products[index].quantity == 0)
    {
        products[index].status = false;
    }

    printf("--- SALE REGISTERED ---\n");
    printf("Product:  %s\n", products[index].name);
    printf("Quantity:  %d\n", quantityToSell);
    printf("Total:    EUR %.2f\n", totalAmount);
    printf("Remaining: %d\n", products[index].quantity);
    printf("--------------------------\n");

    return true;
}

// N8 - By Gioele Marcinnò - Add Stock
void addStock(Product products[], int countProduct, int searchCode, int extraQuantity)
{

    int index = searchProduct(products, countProduct, searchCode);

    if (index == -1)
    {
        printf("Error: Product not found.\n");
        return;
    }

    if (extraQuantity > 0)
    {
        printf("Add stock: %s\n", products[index].name);
        printf("Current quantity: %d\n", products[index].quantity);

        products[index].quantity += extraQuantity;
        products[index].status = true;

        printf("Update successful! New quantity: %d\n", products[index].quantity);
    }
    else
    {
        printf("Error: quantity must be greater than zero.\n");
    }
}

// N9 - By Gioele Marcinnò - Calculate total warehouse value
float calculateTotalValue(Product products[], int countProduct)
{
    float totalValue = 0;

    if (countProduct == 0)
    {
        printf("The warehouse is empty.The value is not calculate.\n");
        return 0.0f;
    }
    printf("Calculating total warehouse value..\n");

    for (int i = 0; i < countProduct; i++)
    {
        totalValue = totalValue + products[i].price * products[i].quantity;
    }
    printf("Total warehouse value: %.2f\n", totalValue);
    return totalValue;
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

// N11 - By Matteo Ventimiglia - Find the product with the longest warranty in the warehouse
void longestWarrantyProduct(Product products[], int countProduct)
{
    if (countProduct == 0)
    {
        printf("The inventory is empty. No products to evaluate.\n");
        return;
    }
    int max_warranty = products[0].warranty;
    int max_index = 0;
    for (int i = 0; i < countProduct; i++)
    {
        if (products[i].warranty > max_warranty)
        {
            max_warranty = products[i].warranty;
            max_index = i;
        }
    }
    printf("\nPRODUCT WITH LONGEST WARRANTY\n");
    printf("Name: %s\n", products[max_index].name);
    printf("Brand: %s\n", products[max_index].brand);
    printf("Warranty (months): %d\n", products[max_index].warranty);
}

// N12 - By Mirko Di Natale - Calculate the average price of products in the warehouse
void calculateAveragePrice(Product products[], int countProduct)
{
    if (countProduct == 0)
    {
        printf("\nThe warehouse is empty. Average price cannot be calculated.\n");
        return;
    }

    float sumTotalPrice = 0;
    int numberOfItems = 0;

    for (int i = 0; i < countProduct; i++)
    {
        sumTotalPrice += products[i].price * products[i].quantity;
        numberOfItems += products[i].quantity;
    }

    if (numberOfItems == 0)
    {
        printf("\nNo items in the warehouse. Average price cannot be calculated.\n");
        return;
    }

    float averagePrice = sumTotalPrice / numberOfItems;

    printf("\nThe average price of items in the warehouse is: %.2f\n", averagePrice);
}

// By Mirko Di Natale - Main application loop
void runApplication()
{
    // clear console
    system("clear");

    Product products[MAX_PRODUCTS];
    int currentCount = 0;
    int choice;

    do
    {
        printMenu();
        choice = readRange("Choice: ", MIN_MENU, MAX_MENU);

        switch (choice)
        {

        case 1:
        {
            currentCount = addProduct(products, currentCount);
            pause();
            break;
        }

        case 2:
        {
            printAllProducts(products, currentCount);
            pause();
            break;
        }

        case 3:
        {
            int searchCode = readInt("Enter the code you want to search: ");
            int index = searchProduct(products, currentCount, searchCode);
            printProductByCode(products, currentCount, index);
            pause();
            break;
        }

        case 4:
        {
            int searchCode = readInt("Enter the code you want to search: ");
            updatePrice(products, currentCount, searchCode);
            pause();
            break;
        }

        case 5:
        {
            int searchCodeForQuantity = readInt("Enter the code of the product you want to update the quantity: ");
            addQuantity(products, currentCount, searchCodeForQuantity);
            pause();
            break;
        }

        case 6:
        {
            updateProductStatus(products, currentCount);
            pause();
            break;
        }

        case 7:
        {
            int searchIdForSale = readInt("Enter the code of the product you want to sell: ");
            int quantityToSell = readInt("Enter the quantity you want to sell: ");
            registerSale(products, currentCount, searchIdForSale, quantityToSell);
            pause();
            break;
        }

        case 8:
        {
            int searchCodeForStock = readInt("Enter the code of the product you want to add stock: ");
            int extraQty = readInt("Enter the quantity you want to add: ");
            addStock(products, currentCount, searchCodeForStock, extraQty);
            pause();
            break;
        }

        case 9:
        {
            calculateTotalValue(products, currentCount);
            pause();
            break;
        }

        case 10:
        {
            countProductForCategory(products, currentCount);
            pause();
            break;
        }

        case 11:
        {
            longestWarrantyProduct(products, currentCount);
            pause();
            break;
        }
        case 12:
        {
            calculateAveragePrice(products, currentCount);
            pause();
            break;
        }

        case 13:
        {
            printf("Exiting system. Goodbye!\n");
            break;
        }

        default:
            printf("Invalid option. Try again.\n");
            break;
        }

    } while (choice != 13);
}

int main()
{

    runApplication();
    return 0;
}
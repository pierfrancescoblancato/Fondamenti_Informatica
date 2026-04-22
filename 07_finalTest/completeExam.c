// ── Libraries ─────────────────────────────────────────────────────────────────
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// ── Warehouse limits ──────────────────────────────────────────────────────────
#define MAX_PRODUCTS   100      // Maximum number of distinct products storable
#define NAME_LENGTH     50      // Maximum character length for name/brand/category

// ── Menu range ────────────────────────────────────────────────────────────────
#define MIN_MENU         1      // First valid menu option
#define MAX_MENU        13      // Last valid menu option

// ── Product field limits ──────────────────────────────────────────────────────
#define MIN_ID           1      // Minimum valid product ID
#define MAX_ID       99999      // Maximum valid product ID
#define MIN_PRICE        0      // Minimum price in cents (€ 0.00)
#define MAX_PRICE  9999999      // Maximum price in cents (€ 99999.99)
#define MIN_QUANTITY     0      // Minimum quantity (0 = out of stock)
#define MAX_QUANTITY 99999      // Maximum quantity storable per product
#define MIN_WARRANTY     0      // Minimum warranty in months
#define MAX_WARRANTY   999      // Maximum warranty in months (~83 years)
#define MIN_SELL         1      // Minimum quantity per sale/restock transaction
#define MIN_STATUS       0      // Status value: 0 = Not Available
#define MAX_STATUS       1      // Status value: 1 = Available

// ── Struct ────────────────────────────────────────────────────────────────────
typedef struct {
    int   id;
    char  name[NAME_LENGTH];
    char  brand[NAME_LENGTH];
    char  category[NAME_LENGTH];
    float price;
    int   quantity;
    int   warranty;
    bool  status;
} Product;

// Forward declaration
int searchProduct(Product products[], int countProduct, int searchCode);


// ═══════════════════════════════════════════════════════════════════════════════
//  BASE INPUT / OUTPUT UTILITIES
// ═══════════════════════════════════════════════════════════════════════════════

// By Mirko Di Natale — flushes leftover characters from stdin
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// By Mirko Di Natale — waits for Enter then clears the console
void pause() {
    printf("\nPress Enter to continue...");
    getchar();
    printf("\033[H\033[2J");
}

// By Pierfrancesco Blancato — reads an integer, retrying on bad input
int readInt(const char prompt[]) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            clearBuffer();
            return value;
        }
        clearBuffer();
        printf("Input not valid. Try again.\n");
    }
}

// By Pierfrancesco Blancato — reads an integer guaranteed to be in [min, max]
int readRange(const char prompt[], int min_value, int max_value) {
    int value;
    while (1) {
        value = readInt(prompt);
        if (value >= min_value && value <= max_value) {
            return value;
        }
        printf("Error: value must be between %d and %d.\n", min_value, max_value);
    }
}

// By Pierfrancesco Blancato — converts an integer in cents to a float price
float intToFloat(int value) {
    return (float)value / 100;
}


// ═══════════════════════════════════════════════════════════════════════════════
//  SHARED HELPER FUNCTIONS
// ═══════════════════════════════════════════════════════════════════════════════

// Prints an error and returns true if the warehouse has no products
bool isWarehouseEmpty(int countProduct) {
    if (countProduct == 0) {
        printf("ERROR: The warehouse is empty.\n");
        return true;
    }
    return false;
}

// Searches for a product by ID; prints an error and returns -1 if not found
int findAndValidate(Product products[], int countProduct, int searchCode) {
    int index = searchProduct(products, countProduct, searchCode);
    if (index == -1) {
        printf("ERROR: Product with ID %d not found.\n", searchCode);
    }
    return index;
}

// Sets product status automatically based on current quantity
void updateStatusByQuantity(Product *p) {
    p->status = (p->quantity > 0);
}

// Prints the status label ("Available" or "Not Available") on its own line
void printStatusLabel(bool status) {
    printf("%s\n", status ? "Available" : "Not Available");
}

// Shorthand: reads a product ID in the valid range
int readProductCode(const char prompt[]) {
    return readRange(prompt, MIN_ID, MAX_ID);
}


// ═══════════════════════════════════════════════════════════════════════════════
//  MENU
// ═══════════════════════════════════════════════════════════════════════════════

// By Mirko Di Natale
void printMenu() {
    printf("\n--- ELECTRONICS STORE MANAGEMENT ---\n");
    printf("1.  Insert new product\n");
    printf("2.  Show all products\n");
    printf("3.  Search product by code\n");
    printf("4.  Update price\n");
    printf("5.  Update available quantity\n");
    printf("6.  Update product status\n");
    printf("7.  Register sale\n");
    printf("8.  Add stock\n");
    printf("9.  Calculate total warehouse value\n");
    printf("10. Count products by category\n");
    printf("11. Find product with longest warranty\n");
    printf("12. Calculate average price\n");
    printf("13. Exit\n");
}


// ═══════════════════════════════════════════════════════════════════════════════
//  FEATURE FUNCTIONS
// ═══════════════════════════════════════════════════════════════════════════════

// N1 - By Mirko Di Natale - Add a new product to the warehouse
int addProduct(Product products[], int position) {

    if (position >= MAX_PRODUCTS) {
        printf("\nERROR: Warehouse is full!\n");
        return position;
    }

    printf("\n--- INSERT NEW PRODUCT ---\n");
    products[position].id = readProductCode("Code ID: ");

    if (searchProduct(products, position, products[position].id) != -1) {
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

    products[position].price    = intToFloat(readRange("Price (in cents - NO DOTS/COMMAS - eg. 1250 for 12.50): ", MIN_PRICE, MAX_PRICE));
    products[position].quantity = readRange("Quantity: ", MIN_QUANTITY, MAX_QUANTITY);
    products[position].warranty = readRange("Warranty (months): ", MIN_WARRANTY, MAX_WARRANTY);

    updateStatusByQuantity(&products[position]);

    printf("\n--- Product '%s' added successfully! ---\n", products[position].name);
    printf("Status set automatically to: ");
    printStatusLabel(products[position].status);

    return position + 1;
}


// N2 - By Pierfrancesco Blancato - Show all products in the warehouse
void printAllProducts(Product products[], int countProduct) {

    if (isWarehouseEmpty(countProduct)) return;

    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");
    printf("| Cod | Name                 | Brand           | Cat          | Price    | Qty Avail. | Warr. (Mo) | Status     |\n");
    printf("+-----+----------------------+-----------------+--------------+----------+------------+------------+------------+\n");

    for (int i = 0; i < countProduct; i++) {
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


// N3 - By Marco Ventimiglia - Search for a product by code (returns index or -1)
int searchProduct(Product products[], int countProduct, int searchCode) {
    for (int i = 0; i < countProduct; i++) {
        if (products[i].id == searchCode) {
            return i;
        }
    }
    return -1;
}


// N3.5 - By Marco Ventimiglia - Print full details of a product given its index
void printProductByCode(Product products[], int countProduct, int index) {

    if (isWarehouseEmpty(countProduct)) return;

    if (index != -1 && index < countProduct) {
        printf("--- Product Found ---\n");
        printf("Code (ID): %d\n",        products[index].id);
        printf("Name:      %s\n",        products[index].name);
        printf("Brand:     %s\n",        products[index].brand);
        printf("Category:  %s\n",        products[index].category);
        printf("Price:     EUR %.2f\n",  products[index].price);
        printf("Quantity:  %d\n",        products[index].quantity);
        printf("Warranty:  %d months\n", products[index].warranty);
        printf("Status:    ");
        printStatusLabel(products[index].status);
        printf("---------------------\n");
    } else {
        printf("Product not found.\n");
    }
}


// N4 - By Matteo Ventimiglia - Update the price of a product
void updatePrice(Product products[], int countProduct, int searchCode) {

    if (isWarehouseEmpty(countProduct)) return;

    int index = findAndValidate(products, countProduct, searchCode);
    if (index == -1) return;

    printf("Product found: %s\n",    products[index].name);
    printf("Current price: EUR %.2f\n", products[index].price);

    products[index].price = intToFloat(readRange("New price (in cents - NO DOTS/COMMAS - eg. 1250 for 12.50): ", MIN_PRICE, MAX_PRICE));
    printf("Price updated successfully!\n");
}


// N5 - By Pierfrancesco Blancato - Set a new quantity for a product
void addQuantity(Product products[], int countProduct, int searchCode) {

    if (isWarehouseEmpty(countProduct)) return;

    int index = findAndValidate(products, countProduct, searchCode);
    if (index == -1) return;

    printf("\nSelected Product -> Code: %d, Name: %s, Current Quantity: %d\n",
        products[index].id, products[index].name, products[index].quantity);

    products[index].quantity = readRange("Enter new quantity: ", MIN_QUANTITY, MAX_QUANTITY);
    updateStatusByQuantity(&products[index]);

    printf("Update Successful -> Code: %d, Name: %s, New Quantity: %d\n\n",
        products[index].id, products[index].name, products[index].quantity);
}


// N6 - By Mirko Di Natale - Toggle the status of a product
void updateProductStatus(Product products[], int countProduct) {

    if (isWarehouseEmpty(countProduct)) return;

    int searchCode, index;

    // Keep asking until a valid product code is entered
    do {
        searchCode = readProductCode("Enter the code of the product: ");
        index = searchProduct(products, countProduct, searchCode);
        if (index == -1) {
            printf("\nERROR: Product not found. Try again.\n");
        }
    } while (index == -1);

    printf("\nSelected Product --> Code: %d, Name: %s\n", products[index].id, products[index].name);
    printf("Current Status: ");
    printStatusLabel(products[index].status);

    int choice = readRange("Enter new status (1 = Available, 0 = Not Available): ", MIN_STATUS, MAX_STATUS);

    if (choice == 1) {
        products[index].status = true;
        addQuantity(products, countProduct, searchCode);
    } else {
        products[index].status = false;
        products[index].quantity = 0;
    }

    printf("--- Update completed successfully! ---\n");
}


// N7 - By Marco Ventimiglia - Register a sale and subtract from stock
void registerSale(Product products[], int countProduct, int searchCode, int quantityToSell) {

    if (isWarehouseEmpty(countProduct)) return;

    int index = findAndValidate(products, countProduct, searchCode);
    if (index == -1) return;

    if (products[index].quantity < quantityToSell) {
        printf("ERROR: Out of stock for '%s'. Available: %d\n", products[index].name, products[index].quantity);
        return;
    }

    products[index].quantity -= quantityToSell;
    updateStatusByQuantity(&products[index]);

    printf("--- SALE REGISTERED ---\n");
    printf("Product:   %s\n",      products[index].name);
    printf("Quantity:  %d\n",      quantityToSell);
    printf("Total:     EUR %.2f\n", products[index].price * (float)quantityToSell);
    printf("Remaining: %d\n",      products[index].quantity);
    printf("-----------------------\n");
}


// N8 - By Gioele Marcinnò - Add stock to an existing product
void addStock(Product products[], int countProduct, int searchCode, int extraQuantity) {

    if (isWarehouseEmpty(countProduct)) return;

    int index = findAndValidate(products, countProduct, searchCode);
    if (index == -1) return;

    printf("Add stock: %s\n",         products[index].name);
    printf("Current quantity: %d\n",  products[index].quantity);

    products[index].quantity += extraQuantity;
    products[index].status = true;

    printf("Update successful! New quantity: %d\n", products[index].quantity);
}


// N9 - By Gioele Marcinnò - Calculate and print the total warehouse value
float calculateTotalValue(Product products[], int countProduct) {

    if (isWarehouseEmpty(countProduct)) return 0.0f;

    float totalValue = 0.0f;
    for (int i = 0; i < countProduct; i++) {
        totalValue += products[i].price * products[i].quantity;
    }

    printf("Total warehouse value: EUR %.2f\n", totalValue);
    return totalValue;
}


// N10 - By Pierfrancesco Blancato - Count how many products belong to a category
void countProductForCategory(Product products[], int countProduct) {

    if (isWarehouseEmpty(countProduct)) return;

    char searchCategory[NAME_LENGTH];
    printf("Enter the category you wish to search: ");
    scanf("%49s", searchCategory);
    clearBuffer();

    int counter = 0;
    for (int i = 0; i < countProduct; i++) {
        if (strcasecmp(products[i].category, searchCategory) == 0) {
            counter++;
        }
    }

    printf("\nCategory '%s' contains %d product(s).\n", searchCategory, counter);
}


// N11 - By Matteo Ventimiglia - Find the product with the longest warranty
void longestWarrantyProduct(Product products[], int countProduct) {

    if (isWarehouseEmpty(countProduct)) return;

    int maxIndex = 0;
    for (int i = 1; i < countProduct; i++) {
        if (products[i].warranty > products[maxIndex].warranty) {
            maxIndex = i;
        }
    }

    printf("\nPRODUCT WITH LONGEST WARRANTY\n");
    printf("Name:              %s\n", products[maxIndex].name);
    printf("Brand:             %s\n", products[maxIndex].brand);
    printf("Warranty (months): %d\n", products[maxIndex].warranty);
}


// N12 - By Mirko Di Natale - Calculate the weighted average price across all stock
void calculateAveragePrice(Product products[], int countProduct) {

    if (isWarehouseEmpty(countProduct)) return;

    int totalItems = 0;
    for (int i = 0; i < countProduct; i++) {
        totalItems += products[i].quantity;
    }

    if (totalItems == 0) {
        printf("\nNo items in stock. Average price cannot be calculated.\n");
        return;
    }

    float totalValue = calculateTotalValue(products, countProduct);
    printf("\nAverage price per item: EUR %.2f\n", totalValue / totalItems);
}


// ═══════════════════════════════════════════════════════════════════════════════
//  MAIN LOOP
// ═══════════════════════════════════════════════════════════════════════════════

void runApplication() {

    system("clear");

    Product products[MAX_PRODUCTS];
    int currentCount = 0;
    int choice;

    do {
        printMenu();
        choice = readRange("Choice: ", MIN_MENU, MAX_MENU);

        switch (choice) {

            case 1:
                currentCount = addProduct(products, currentCount);
                break;

            case 2:
                printAllProducts(products, currentCount);
                break;

            case 3: {
                int code  = readProductCode("Enter the code to search: ");
                int index = searchProduct(products, currentCount, code);
                printProductByCode(products, currentCount, index);
                break;
            }

            case 4: {
                int code = readProductCode("Enter the code to update the price: ");
                updatePrice(products, currentCount, code);
                break;
            }

            case 5: {
                int code = readProductCode("Enter the code to update the quantity: ");
                addQuantity(products, currentCount, code);
                break;
            }

            case 6:
                updateProductStatus(products, currentCount);
                break;

            case 7: {
                int code = readProductCode("Enter the code of the product to sell: ");
                int qty  = readRange("Enter the quantity to sell: ", MIN_SELL, MAX_QUANTITY);
                registerSale(products, currentCount, code, qty);
                break;
            }

            case 8: {
                int code = readProductCode("Enter the code of the product to restock: ");
                int qty  = readRange("Enter the quantity to add: ", MIN_SELL, MAX_QUANTITY);
                addStock(products, currentCount, code, qty);
                break;
            }

            case 9:
                calculateTotalValue(products, currentCount);
                break;

            case 10:
                countProductForCategory(products, currentCount);
                break;

            case 11:
                longestWarrantyProduct(products, currentCount);
                break;

            case 12:
                calculateAveragePrice(products, currentCount);
                break;

            case 13:
                printf("Exiting system. Goodbye!\n");
                break;
        }

        if (choice != 13) pause();

    } while (choice != 13);
}

int main() {
    runApplication();
    return 0;
}
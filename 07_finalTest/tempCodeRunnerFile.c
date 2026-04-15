
    if (searchProduct(products, position, products[position].id) != -1)
    {
        printf("ERROR: ID %d already exists!\n", products[position].id);
        return position;
    }
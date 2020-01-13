//allows user to create a product list with name, price, and weight.
//prints the product list and asks if user would like to sort the list by name, weight, or price
//displays sorted product list
//also allows the user to resize the product list and displays resized list


//library headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure definition of a ProductDescription aggregate data type
typedef struct ProductDescription{
    
    char productName [25];      //character array for name of product up to 24 characters
    float productPrice;         //float variable for price of product
    float  productWeight;       //float variable for weight of product
    
} Product;      //alias is Product

//FUNCTION PROTOTYPES
void CreateProductList(Product **productList, int size);
void ResizeProductList(Product **productList, int newSize);
Product SetProductInfo();
void SortProductList(Product *productList, int size, char sortOption);
void Swap(Product *productList, int i, int j);
void SortProductListQ4(Product *productList, int size, char sortOption);
void AddProductToProductList(Product *productList, int size);
void PrintProductList(Product *productList, int size);

//MAIN FUNCTION
int main() {
    
    printf("\n");
    
    Product *list;      //pointer to list of type Product to be filled with product descriptions
    
    int listSize;       //size of list
    char sortOption;    //user chooses to sort by name, weight, or price
    char resize;        //size user chooses to resize the list to
    
    printf("Please Enter the size of the list: ");
    scanf("%d", &listSize);
    
    CreateProductList(&list, listSize);     //creates the product list of size given by user
    
    AddProductToProductList(list, listSize);    //prompts user for information about product and adds to list
    
    PrintProductList(list, listSize);       //displays product list
    
    printf("\n\nTo sort the product list press: \n'p' to sort by price, or 'w' to sort by weight, or 'n' to sort by name  : ");
    
    scanf(" %c", &sortOption);
    
    //SortProductList(list,listSize, sortOption);     //sorts product list by sortOption chosen by user (Q2)
    SortProductListQ4(list,listSize, sortOption);     

    
    PrintProductList(list,listSize);        //displays the sorted product list
    
    printf("\n\nTo resize the product list press 'y' or any other key to escape: ");
    scanf(" %c", &resize);
    
    if(resize == 'y' || resize == 'Y'){
        printf("Please Enter the new size of the list: ");
        scanf("%d", &listSize);         //newSize of list
        ResizeProductList(&list, listSize);     //resizes product list
        PrintProductList(list, listSize);       //displays resized list
    }
    return 0;
}


//FUNCTION DEFINITIONS

void CreateProductList(Product **productList, int size){
// This function uses dynamic memory allocation to allocate enough memory to store the product list (array of products)
//Input: double pointer to productList of type Product, integer size of list
//Output: no return value
    *productList = (Product *)malloc(sizeof(Product) * 5);
    
}
void ResizeProductList(Product **productList, int newSize){
// This function uses dynamic memory allocation to resize an existing product list (e.g. increase the size or decrease the size)
//Input: double pointer to productList of type Product, integer newSize list needs to be resized to
//Output: no return value
    *productList = (Product *)realloc(*productList, sizeof(Product)*newSize);   //Q1 BUG: input for realloc should be *productList and newSize multiplied bu the previous size of Product
}

Product SetProductInfo(){
// This function allows the user to set the data for a single product. It creates a variable of type product and allow the user to set the data for this product
//Input: no input parameters, asks user for product name, price, and weight and sets it as the data for the product
//Output: product of type Product
    Product product;
    
    printf("\nPlease Enter the Product Name: ");
    scanf(" %[^\n]s", product.productName);
    
    printf("\nPlease Enter the Product Price: ");
    scanf(" %f", &product.productPrice);
    
    printf("\nPlease Enter the Product Weight: ");
    scanf(" %f", &product.productWeight);
    
    return product;
    
}

void SortProductList(Product *productList, int size, char sortOption){      //Q2
//This function allows the user to sort the product list based on a sort option; the sort option could be the product name, price, or weight.
//Input: pointer to productList of type Product, integer size of list, sortOption (by name, weight, or price
//Output: no return value
    Product temp;                   //placeholder for swap temp is of type Product
    for (int i=0; i<size-1; i++){   //loop to go through elements of productList
        for (int j=i+1; j<size; j++)
        {
            if (sortOption == 'p')  //sort based on price
            {
                if (productList[i].productPrice>productList[j].productPrice) //first is bigger than second
                {
                    temp = productList[i];
                    productList[i] = productList[j];
                    productList[j]=temp;
                }
            }
            if (sortOption == 'w')  //sort based on weight
            {
                if (productList[i].productWeight>productList[j].productWeight) //first is bigger than second
                {
                    temp = productList[i];
                    productList[i] = productList[j];
                    productList[j]=temp;
                }
            }
            if (sortOption == 'n')  //sort based on name
            {
                if (strcmp(productList[i].productName,productList[j].productName)>0) //first is bigger than second
                {
                    temp = productList[i];
                    productList[i] = productList[j];
                    productList[j]=temp;
                }
            }
        }
    }
}

void SortProductListQ4(Product *productList, int size, char sortOption){  //Q4) Sorts the product list with no more than 5 lines of code
//This function allows the user to sort the product list based on a sort option; the sort option could be the product name, price, or weight.
//Input: pointer to productList of type Product, integer size of list, sortOption (by name, weight, or price
//Output: no return value
    for (int i=0; i<size-1; i++){       //go through elements of list
        for (int j=i+1; j<size; j++)
        {
            if ((sortOption == 'p' && productList[i].productPrice>productList[j].productPrice) || (sortOption == 'w' && productList[i].productWeight>productList[j].productWeight) || (sortOption == 'n' && strcmp(productList[i].productName,productList[j].productName)>0))       //uses sortOption and checks if second is less than first
            {
                Swap(productList, i, j);    //calls function Swap to swap the products
            }
        }
    }
}

void Swap(Product *productList, int i, int j)
//This function is called in SortProductList and swaps two product descriptions in order to sort the list
//Input: Pointer to productList, int i and j (indexes of product descriptions)
//Output: no return values
{
    Product temp;           //placeholder for swap temp is of type Product
    //swap
    temp = productList[i];
    productList[i] = productList[j];
    productList[j]=temp;
}

void AddProductToProductList(Product *productList, int size){
//This function allows the user to create the product list
//Input: pointer to productList of type Product, size of list
//Output: no return value
    
    for(int i=0; i<size; i++){
        
        printf("\nPlease enter product info for product %d: \n", i);
        *(productList+i) = SetProductInfo();
    }
    
}

void PrintProductList(Product *productList, int size){
//This function print on the screen the product list
//Input: pointer to productList of type Product, size of list
//Output: no return value
    
    for(int i=0; i< size; i++){
        
        printf("\n Product ID: %d Name:  %s", i, (productList+i)->productName);
        printf("\n Product ID: %d Price: %f", i, (productList+i)->productPrice);
        printf("\n Product ID: %d Weight: %f", i, (productList+i)->productWeight);
        printf("\n----------------------------------------------------------------\n");
    }
    
}

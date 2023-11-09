/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Davyd Kuleba
Student ID#: 147894224
Email      : dkuleba@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* int_ptr){
    int valueInt=0;

    do {
        scanf("%d", &valueInt);
        if (valueInt <= 0){
            printf("ERROR: Enter a positive value: ");}
    } while (valueInt <= 0);

    if (int_ptr != NULL){
        *int_ptr = valueInt;}

    return valueInt;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* double_ptr)
{
    double valueDouble = 0.00;
    do {
        scanf("%lf", &valueDouble);
        if (valueDouble <= 0){
            printf("ERROR: Enter a positive value: ");
        }
    } while (valueDouble <= 0);

    if (double_ptr != NULL){
        *double_ptr = valueDouble;}
    return valueDouble;

}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int sequenceNum)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n",max_num_product);
    printf("NOTE: A 'serving' is %dg\n", serving_size);
    printf("\n");
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum)
{
    struct CatFoodInfo catFood;

    printf(
        "Cat Food Product #%d\n"
        "--------------------\n", sequenceNum + 1);

    printf("SKU           : ");
    getIntPositive(&catFood.sku);
    printf("PRICE         : $");
    getDoublePositive(&catFood.price);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&catFood.weight);
    printf("CALORIES/SERV.: ");
    getIntPositive(&catFood.calories);
    printf("\n");
    return catFood;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void){
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, int calories, double* weight){
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);}

// 7. Logic entry point
void start(void){
    int i;
    struct CatFoodInfo catFood[max_num_product] = { {0} };
    openingMessage(max_num_product);
    for (i = 0; i < max_num_product; i++){
        catFood[i] = getCatFoodInfo(i);}

    displayCatFoodHeader();

    for (i = 0; i < max_num_product; i++){
        displayCatFoodData(catFood[i].sku, &catFood[i].price, catFood[i].calories, &catFood[i].weight);}
}

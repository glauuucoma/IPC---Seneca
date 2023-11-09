/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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


// User-Defined Libraries

#include "w8p2.h"



// ----------------------------------------------------------------------------
// PART-1

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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(const double* pounds, double* toKilograms){
    double conversion = (*pounds) / poundToKgFactor;
    
    if (toKilograms != NULL){
        *toKilograms = conversion;}
    
    return conversion;
}

// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(const double* pounds, int* toGrams){
    
    int convert = (*pounds) / poundToKgFactor * 1000;
    if (toGrams != NULL){
        *toGrams = convert;}
    
    return convert;
}

// 10. convert lbs: kg and g

void convertLbs(const double* pounds, double* toKilograms, int* toGrams){
    if (toKilograms != NULL && toGrams != NULL){
        *toKilograms = (*pounds) / poundToKgFactor;
        *toGrams = (*pounds) / poundToKgFactor * 1000;}
    
}

// 11. calculate: servings based on gPerServ

double calculateServings(const int servingSizeGrm, const int totalGrams, double* numOfServs){
    double calculate = ((double)totalGrams) / servingSizeGrm;
    if (numOfServs != NULL){
        *numOfServs = calculate;}
    return calculate;
}

// 12. calculate: cost per serving

double calculateCostPerServing(const double* price, const double* numOfServs, double* servingCost){
    double calculate = (*price) / (*numOfServs);
    if (servingCost != NULL){
        *servingCost = calculate;}
    return calculate;
}

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* price, const double* calories, double* caloriesCost){
    double calculate = (*price) / (*calories);
    if (caloriesCost != NULL){
        *caloriesCost = calculate;}
    return calculate;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(struct CatFoodInfo catFood){
    struct ReportData reportData;
    reportData.sku = catFood.sku;
    reportData.price = catFood.price;
    reportData.weightLbs = catFood.weight;
    reportData.caloriesPerServing = catFood.calories;
    reportData.weightKg = convertLbsKg(&reportData.weightLbs, &reportData.weightKg);
    reportData.weightGrams = convertLbsG(&reportData.weightLbs, &reportData.weightGrams);
    reportData.totalServings = calculateServings(serving_size, reportData.weightGrams, &reportData.totalServings);
    double totalCalo = reportData.caloriesPerServing * reportData.totalServings;
    reportData.costPerServing = calculateCostPerServing(&reportData.price, &reportData.totalServings, &reportData.costPerServing);
    reportData.costOfCaloriesPerServing = calculateCostPerCal(&reportData.price, &totalCalo, &reportData.costOfCaloriesPerServing);
    return reportData;
}

// 15. Display the formatted table header for the analysis results

void displayReportHeader(void){
    printf("Analysis Report (Note: Serving = %dg)\n", serving_size);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData reportData, const int cheapestOptChk){
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", reportData.sku, reportData.price, reportData.weightLbs, reportData.weightKg, reportData.weightGrams, reportData.caloriesPerServing, reportData.totalServings, reportData.costPerServing, reportData.costOfCaloriesPerServing);
}

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo catFood){
    printf(
        "Final Analysis\n"
        "--------------\n"
        "Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%5.2lf\n\n", catFood.sku, catFood.price);
    printf("Happy shopping!\n\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void){
    int i, cheapestIndex = 0;

    struct CatFoodInfo catFood[max_num_product] = { {0} };
    struct ReportData reportData[max_num_product] = { {0} };

    openingMessage(max_num_product);

    for (i = 0; i < max_num_product; i++){
        catFood[i] = getCatFoodInfo(i);
        reportData[i] = calculateReportData(catFood[i]);}

    displayCatFoodHeader();

    for (i = 0; i < max_num_product; i++){
        displayCatFoodData(catFood[i].sku, &catFood[i].price, catFood[i].calories, &catFood[i].weight);}

    double cheapest = reportData[0].costPerServing;
    for (i = 0; i < max_num_product; i++){
        if (reportData[i].costPerServing <= cheapest){
            cheapest = reportData[i].costPerServing;
            cheapestIndex = i;}}
    printf("\n");

    displayReportHeader();

    for (i = 0; i < max_num_product; i++){
        displayReportData(reportData[i], cheapestIndex);

        if (cheapestIndex == i){
            printf(" ***\n");}
        else{
            printf("\n");}}
    printf("\n");

    for (i = 0; i < max_num_product; i++){
        if (i == cheapestIndex){
            displayFinalAnalysis(catFood[i]);}
    }
}

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


// ----------------------------------------------------------------------------
// defines/macros

#define max_num_product 3
#define serving_size 64
#define poundToKgFactor 2.20462

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int sku;
    double price;
    int calories;
    double weight;
};

struct ReportData {
    int sku;                   // Product SKU number (unique identifier)
    double price;              // Product price
    int caloriesPerServing;    // Calories per suggested serving
    double weightLbs;          // Product weight in pounds (lbs)
    double weightKg;           // Product weight in kilograms (kg)
    int weightGrams;           // Product weight in grams (g)
    double totalServings;      // Total servings
    double costPerServing;     // Cost per serving
    double costOfCaloriesPerServing; // Cost of calories per serving
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int*);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double*);

// 3. Opening Message (include the number of products that need entering)

void openingMessage(int);

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(int);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data

void displayCatFoodData(int, double*, int, double*);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg

double convertLbsKg(const double* pounds, double* toKilograms);

// 9. convert lbs: g

int convertLbsG(const double* pounds, int* toGrams);

// 10. convert lbs: kg / g

void convertLbs(const double* pounds, double* toKilograms, int* toGrams);

// 11. calculate: servings based on gPerServ

double calculateServings(const int servingSizeGrm, const int totalGrams, double* numOfServs);

// 12. calculate: cost per serving

double calculateCostPerServing(const double* price, const double* numOfServs, double* servingCost);


// 13. calculate: cost per calorie

double calculateCostPerCal(const double* price, const double* calories, double* caloriesCost);


// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(struct CatFoodInfo catFood);

// 15. Display the formatted table header for the analysis results

void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData reportData, const int cheapestOptChk);


// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo catFood);

// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start(void);

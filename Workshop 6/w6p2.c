///*/////////////////////////////////////////////////////////////////////////
 //                          Workshop - #6 (P2)
 //Full Name  : Davyd Kuleba
 //Student ID#: 147894224
 //Email      : dkuleba@myseneca.ca
 //Section    : ZCC
 //
 //Authenticity Declaration:
 //I declare this submission is the result of my own work and has not been
 //shared with any other student or 3rd party content provider. This submitted
 //piece of work is entirely of my own creation.
 ///////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
    
    #define MAX_NUMBER_OF_ITEMS 10
    #define MIN_NUMBER_OF_ITEMS 1
    #define MIN_PRIORITY 1
    #define MAX_PRIORITY 3
    #define DISPLAY_OPTIONS 3
    #define NUM_OF_MONTHS 12.0
    #define MIN_FILTER 1
    #define MAX_FILTER 3
    
    const double MAX_INCOME = 400000.00;
    const double MIN_INCOME = 500.00;
    const double MIN_COST = 100.00;
    const char YES = 'y';
    const char NO = 'n';
    
    double income;
    double filterValue;
    int i = 0;
    int allMonths;
    int valid = 0;
    int numOfItems;
    int List, filter;
    int months, years;
    int isNote, stop = 0;
    
    double  cost[MAX_NUMBER_OF_ITEMS];
    int priority[MAX_NUMBER_OF_ITEMS];
    char finance[MAX_NUMBER_OF_ITEMS];
    
    double total_cost = 0;
    
    // Start
    
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

    do{
        valid = 1;
        printf("\n");
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);
        
        if (income < MIN_INCOME){
            valid = 0;
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MIN_INCOME);
        }
        
        if (income > MAX_INCOME){
            valid = 0;
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAX_INCOME);
        }
        
    } while (valid == 0);

    do{
        valid = 1;
        printf("\n");
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numOfItems);
        
        if(numOfItems < MIN_NUMBER_OF_ITEMS || numOfItems  > MAX_NUMBER_OF_ITEMS){
            valid = 0;
            printf("ERROR: List is restricted to between %d and %d items.\n", MIN_NUMBER_OF_ITEMS, MAX_NUMBER_OF_ITEMS);
        }
        
    } while (valid == 0);
       
    
    for (i = 0; i < numOfItems; i++){
        printf("\n");
        printf("Item-%d Details:\n", i + 1);
        
        do{
            valid = 1;
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            
            if (cost[i] < MIN_COST){
                valid = 0;
                printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
            }
            
        } while (valid == 0);
        
        do{
            valid = 1;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            
            if (priority[i] < MIN_PRIORITY || priority[i] > MAX_PRIORITY){
                valid = 0;
                printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY, MAX_PRIORITY);
            }
        } while (!valid);
        
        do{
            valid = 1;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);
            
            if (finance[i] != YES && finance[i] != NO)
            {
                valid = 0;
                printf("      ERROR: Must be a lowercase '%c' or '%c'\n", YES, NO);
            }
        } while (!valid);
        
    }
    //report
    
    printf("\n");
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < numOfItems; i++){
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], cost[i]);
        total_cost = total_cost + cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", total_cost);

    do{
        valid = 1;
        isNote = 0;
        printf("\n");
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &List);
        
        if (List == 0){
            printf("\n");
            printf("Best of luck in all your future endeavours!\n\n");
        }
        else if (List == 1){
            valid = 0;
            allMonths = total_cost / income ;
            years = allMonths / 12;
            months = (allMonths - years * 12) + 1;
            
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", total_cost);
            printf("Forecast: %d years, %d months\n", years, months);
            for (i = 0; i < numOfItems && isNote == 0; i++){
                if (finance[i] == 'y'){
                    isNote = 1;
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
            }
            printf("====================================================\n");
        }
        else if (List == 2){
            valid = 0;
            filterValue = 0.00;
            
            do{
                stop = 1;
                printf("\n");
                printf("What priority do you want to filter by? [1-3]: ");
                scanf("%d", &filter);
               
                if ( filter >= MIN_FILTER && filter <= MAX_FILTER ){
                    for (i = 0; i < numOfItems ; i++){
                        if (priority[i] == filter){
                            filterValue = filterValue + cost[i];
                        }
                    }
                    
                    allMonths = filterValue / income ;
                    years = allMonths / 12;
                    months = (allMonths - years * 12) + 1;

                    
                    // Printing
                    
                    printf("\n");
                    printf("====================================================\n");
                    printf("Filter:   by priority (%d)\n", filter);
                    printf("Amount:   $%.2lf\n", filterValue);
                    printf("Forecast: %d years, %d months\n", years, months);
                    for (i = 0; i < numOfItems && isNote == 0; i++){
                            if (priority[i] == filter && finance[i] == 'y'){
                                isNote = 1;
                                printf("NOTE: Financing options are available on some items.\n");
                                printf("      You can likely reduce the estimated months.\n");
                            }
                    }
                    printf("====================================================\n");}
                else{
                    stop = 0;
                    printf("      ERROR: Value must be between %d and %d\n", MIN_FILTER, MAX_FILTER);
                }
            } while (stop == 0);}
        else{
            valid = 0;
            printf("\n");
            printf("ERROR: Invalid menu selection.\n");
        }
    } while (!valid);
    return 0;
}


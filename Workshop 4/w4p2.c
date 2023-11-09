/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Davyd Kuleba
Student ID#: 147894224
Email      : dkuleba@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    // Pick items logic
    int appleQuantity = 0,orangesQuantity = 0,pearsQuantity = 0,cabbagesQuantity = 0,tomatoesQuantity = 0;
    int apples = 0, oranges = 0, pears = 0, tomatoes = 0, cabbages = 0;
    printf("Grocery Shopping\n================\n");
    // APPLES
    do {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if (apples < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (apples < 0);
    // ORANGES
    printf("\n");
    do {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);

            if (oranges < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (oranges < 0);
    // PEARS
    printf("\n");
    do {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);

            if (pears < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pears < 0);
    // TOMATOES
    printf("\n");
    do {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);

            if (tomatoes < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomatoes < 0);
    // CABBAGES
    printf("\n");
    do {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);

            if (cabbages < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbages < 0);
 printf("\n--------------------------\nTime to pick the products!\n--------------------------\n\n");

    // Picking products
    //APPLES
    printf("\n");

    do{
        if(apples > 0) {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &appleQuantity);

            if (appleQuantity <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (appleQuantity > apples) {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
            } else {
                apples -= appleQuantity;
                if (apples > 0) {
                    printf("Looks like we still need some APPLES...\n");
                } else if(apples==0)  {
                    printf("Great, that's the apples done!\n");
                }
            }
        }} while(apples != 0);

    //ORANGES
    printf("\n");

    do{
        if(oranges > 0) {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &orangesQuantity);

            if (orangesQuantity <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (orangesQuantity > oranges) {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
            } else {
                oranges -= orangesQuantity;
                if (oranges > 0) {
                    printf("Looks like we still need some ORANGES...\n");
                } else if(oranges==0)  {
                    printf("Great, that's the oranges done!\n");
                }
            }
        }} while(oranges != 0);

    //PEARS
    printf("\n");

    do{
        if(pears > 0) {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pearsQuantity);

            if (pearsQuantity <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (pearsQuantity > pears) {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
            } else {
                pears -= pearsQuantity;
                if (pears > 0) {
                    printf("Looks like we still need some PEARS...\n");
                } else if(pears==0)  {
                    printf("Great, that's the pears done!\n");
                }
            }
        }} while(pears != 0);

    //TOMATOES
    printf("\n");

    do{
        if(tomatoes > 0) {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &tomatoesQuantity);

            if (tomatoesQuantity <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (tomatoesQuantity > tomatoes) {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
            } else {
                tomatoes -= tomatoesQuantity;
                if (tomatoes > 0) {
                    printf("Looks like we still need some TOMATOES...\n");
                } else if(tomatoes==0)  {
                    printf("Great, that's the tomatoes done!\n");
                }
            }
        }} while(tomatoes != 0);

    //CABBAGES

    do{
        if(cabbages > 0) {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &cabbagesQuantity);

            if (cabbagesQuantity <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (cabbagesQuantity > cabbages) {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
            } else {
                cabbages -= cabbagesQuantity;
                if (cabbages > 0) {
                    printf("Looks like we still need some CABBAGES...\n");
                } else if(cabbages==0)  {
                    printf("Great, that's the cabbages done!\n");
                }
            }
        }} while(cabbages != 0);

    printf("\nAll the items are picked!\n\n");
    
    int choice;
    
    printf("Do another shopping? (0=NO): ");
    scanf("%d", &choice);
    printf("\n");
    
    if (choice != 0) {
        main();
    } else {
        printf("Your tasks are done for today - enjoy your free time!\n");
    }
    
    return 0;
}

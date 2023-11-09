/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Davyd Kuleba
Student ID#: 147894224
Email      : dkuleba@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char loopType; // Types of loops: D = do..while, W = while, and F = for), any other characters will display an error
    int iterationNumber; // Should be between 3 and 20 (inclusive), any other values will display an error
    int i = 0;
    printf("+----------------------+\nLoop application STARTED\n+----------------------+\n\n");
    printf("D = do/while | W = while | F = for | Q = quit\nEnter loop type and the number of times to iterate (Quit=Q0): ");
    scanf(" %c%d", &loopType, &iterationNumber);
    if((loopType == 'D' || loopType == 'W' || loopType == 'F' || loopType == 'Q') && iterationNumber >= 3 && iterationNumber <= 20){
        if(loopType == 'D'){
            printf("DO-WHILE: ");
            do {
                printf("D");
                    i++;
                } while (i < iterationNumber);
        } else if(loopType == 'W'){
            printf("WHILE : ");
            while (iterationNumber > 0) {
                printf("W");
                iterationNumber--;
            }
        } else if (loopType == 'F'){
            printf("FOR : ");
            for (i = 0; i < iterationNumber; i++) {
                printf("F");
            }
        }
    } else if(loopType == 'Q'){
            if(iterationNumber == 0){
                printf("\n+--------------------+\nLoop application ENDED\n+--------------------+"); // Add maybe more \n!!!!!!! Statements
            } else{
                printf("ERROR: To quit, the number of iterations should be 0!");
            }
    } else if(loopType!='Q'){
        printf("ERROR: Invalid entered value(s)!");
    }else if(iterationNumber < 3 || iterationNumber > 20){
        printf("ERROR: The number of iterations must be between 3-20 inclusive!");
    }
    return 0;
}


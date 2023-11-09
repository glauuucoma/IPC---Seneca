/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Davyd kuleba
Student ID#: 147894224
Email      : dkuleba@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "core.h"

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void){
    while (getchar() != '\n'){
        ;
    }
}

void suspend(void){
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void){
    char newLine = 'x';
    int value;

    do {
        scanf("%d%c", &value, &newLine);

        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }} while (newLine != '\n');

    return value;}

int inputIntPositive(void){
    char newLine = 'x';
    int value;

    do {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a number: ");
        }
        if (value <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value <= 0 || newLine != '\n');

    return value;
}

int inputIntRange(int lowerBound, int upperBound){
    char newLine = 'x';
    int value;

    do {
        scanf("%d%c", &value, &newLine);

        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (value > upperBound || value < lowerBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", LOWERBOUND, UPPERBOUND);
        }
    } while (value > upperBound || value < lowerBound || newLine != '\n');

    return value;
}

char inputCharOption(const char str[]){
    int i, chk = 0;
    char valueChar;

    do {
        scanf(" %c", &valueChar);

        for (i = 0; str[i] != '\0'; i++)
        {
            if (valueChar == str[i])
            {
                chk = 1;
            }
        }
        if (chk == 0)
        {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", str);
        }
    } while (chk == 0);

    return valueChar;
}

void inputCString(char* str, int minChar, int maxChar){
    int i, len = 0, chk = 1;
    char string[100];

    while (chk == 1){
        len = 0;
        scanf(" %[^\n]s", string);
        len = strlen(string);

        if (minChar == maxChar){
            if (len != minChar){
                printf("ERROR: String length must be exactly %d chars: ", minChar);
            }
            else{
                chk = 0;
            }
        }
        else{
            if (len > maxChar){
                printf("ERROR: String length must be no more than %d chars: ", maxChar);
            }
            else if (len < minChar){
                printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
            }
            else{
                chk = 0;
            }
        }
    }

    for (i = 0; i < len; i++){
        str[i] = string[i];
    }
}

void displayFormattedPhone(const char* str){
    int i, len = 0;

    for (i = 0; str != NULL && isdigit(str[len]); i++){
        len++;
    }

    if (len == 10){
        printf("(");
        for (i = 0; i < 3; i++){
            printf("%c", str[i]);
        }
        printf(")");

        for (i = 3; i < 6; i++){
            printf("%c", str[i]);
        }
        printf("-");

        for (i = 6; i < 10; i++){
            printf("%c", str[i]);
        }
    }
    else{
        printf("(___)___-____");}
}

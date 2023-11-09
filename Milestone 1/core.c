
// Copy the below commented "header" section to all your source code files!

/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
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

#include <stdio.h>
#include <ctype.h>
#include "core.h"

void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void){
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//
int inputInt(void) {
    char newLine = 'x';
    int value = 0;
    
    while (newLine != '\n') {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    
    return value;
}

//
int inputIntPositive() {
    int value;

    do {
        value = inputInt();
        if (value <= 0) {
            printf("ERROR! Value must be > 0: ");}
    } while (value <= 0);

    return value;
}
//
int inputIntRange(int lowBound, int upBound) {
    int value;

    do {
        value = inputInt();

        if (value < lowBound || value > upBound) {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowBound, upBound);
        }
    } while (value < lowBound || value > upBound);

    return value;
}
char inputCharOption(const char* validChar){
    char value;
    char newLine = 'x';
    int i, isValid = 0;
    while (isValid != 1) {
        scanf("%c%c", &value, &newLine);
        for (i = 0;validChar[i] != '\0';i++) {
            if (value == validChar[i]) {
                isValid = 1;
            }
        }
        if (isValid != 1) {
            printf("ERROR: Character must be one of [%s]: ", validChar);
        }
    }
    return value;
}
void inputCString(char* string, int minimum, int maximum){
    char str[100];
    int i = 0, exitPrompt = 0;
    int length = 0;
    do{
        scanf(" %99[^\n]", str);
        i = 0;
        length = 0;
        while (str[i] != '\0'){
            length++;
            i++;
        }
        if (length >= minimum && length <= maximum){
            exitPrompt = 1;
            for (i = 0; i < length; i++)
                string[i] = str[i];
        }
        else{
            if (minimum == maximum){
                printf("ERROR: String length must be exactly %d chars: ", minimum);
            }
            else if (length > maximum){
                printf("ERROR: String length must be no more than %d chars: ", maximum);
            }
            else{
                printf("ERROR: String length must be between %d and %d chars: ", minimum, maximum);
            }
        }
    } while (exitPrompt != 1);
    exitPrompt = 0;
}

void displayFormattedPhone(const char* string) {
    if (string == NULL) {
        printf("(___)___-____");
        return;
    }
    int i, isNumber = 1, length = 0;
    length = 0;
    for (i = 0; string[i] != '\0'; i++) {
        length++;
        if (string[i] < 48 || string[i] > 57) {
            isNumber = 0;
        }
    }
    if (length == 10 && isNumber) {
        printf("(");
        for (i = 0; i < 3; i++) {
            printf("%c", string[i]);
        }
        printf(")");
        for (i = 3; i < 6; i++) {
            printf("%c", string[i]);
        }
        printf("-");
        for (i = 6; i < 10; i++) {
            printf("%c", string[i]);
        }
    }
    else { printf("(___)___-____"); }
}

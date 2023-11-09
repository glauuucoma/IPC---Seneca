/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void clearInputBuffer(void){ // Clear the standard input buffer
    while (getchar() != '\n'){;}} // Cleaning input buffer

void suspend(void){
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// This function ensures the input and return of an integer value. In case of an incorrect input, an error message will be shown.
int inputInt(void) {
    char character = ' ';
    int value;

    do {
        scanf("%d%c", &value, &character);

        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    while (character != '\n');

    return value;
}

// This function ensures the input and return of a non-negative integer value. Should a zero or negative value be provided, an error message will be shown.
int inputIntPositive(void) {
    char character = ' ';
    int value;
    do {
        scanf("%d%c", &value, &character);
        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a number: ");
        }
        if (value <= 0) {
            printf("ERROR! Value must be > 0: ");
        }}
    while (value <= 0);

    return value;
    // Once the necessary validations are finished, we can proceed to return the value.
}

// This function ensures the input of an integer value within a specified inclusive range, and subsequently returns it. In the event that a value outside this range is entered, an error message is shown, and the function persists in requesting a valid value within the provided range.
int inputIntRange(int lowerBound, int upperBound) {
    char character = ' ';
    int value;

    do {
        scanf("%d%c", &value, &character);

        if (character != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        else if (!(value <= upperBound && value >= lowerBound)) {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    }
    while (!(value <= upperBound && value >= lowerBound)); // Checking the value
    return value;
}

// This function ensures that a single character value is input and subsequently returned, limited to the predefined list of valid characters. If the entered character is not found within the list of valid characters, an error message is displayed, and the function continues to prompt for a valid character entry.
char inputCharOption(char str[]) {
    int i, count = 0;
    char input;

    do {
        scanf(" %c", &input);

        for (i = 0; str[i] != '\0'; i++) {
            if (input == str[i]) {
                count++;}}
        if (count == 0) {
            printf("ERROR: Character must be one of [%s]: ", str);
        }
    } while (count == 0);

    clearInputBuffer();
    // Once all validations are successfully completed, we will proceed to return the input value.
    return input;
}

// This function ensures the input of a C string value containing a quantity of characters within the range defined by the 2nd and 3rd arguments.
void inputCString(char* str, int minChar, int maxChar) {
    int flag = 1;
    char ch = 'a';

    while (flag) {
        int len = 0;
        // Accepts input as a string until a newline character is encountered.
        while (ch != '\n' && len <= maxChar) {
            ch = getchar();
            str[len] = ch;
            len++;
        };

        // If the length of the string is within the limit of maxChars, we will append '\0' at the end to indicate the string's termination.
        if (ch == '\n' && len <= (maxChar + 1)) {
            len--;
            str[len] = '\0';
        }
        // If the length exceeds maxChar, we will append '\0' at the end to signify the string's end and disregard the surplus characters. Additionally, we will eliminate the excess characters from the buffer.
        else {
            str[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && len != minChar) {
            printf("ERROR: String length must be exactly %d chars: ", minChar);
            ch = 'a';
        }
        else if (len < minChar || len > maxChar) {
            if (len > maxChar) {
                printf("ERROR: String length must be no more than %d chars: ", maxChar);
                ch = 'a';
            }
            else if (len < minChar) {
                printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
                ch = 'a';
            }
        }
        else {
            flag = 0;
        }
    }
}

// This function shares similarities with inputCString but is specifically designed for numerical input.
void inputCStringNumbers(char* str, int minChar, int maxChar) {
    int flag = 1;
    char ch = 'a';

    while (flag) {
        int len = 0;
        // Accepts input in the form of a string until a newline character is encountered.
        while (ch != '\n' && len <= maxChar) {
            ch = getchar();
            str[len] = ch;
            len++;
        };

        // If the length of the string is equal to or smaller than maxChars, we will append '\0' to signify the string's termination.
        if (ch == '\n' && len <= (maxChar + 1)) {
            len--;
            str[len] = '\0';
        }
        // In cases where the length exceeds maxChar, we will append '\0' to the end while disregarding any surplus characters. Additionally, we will eliminate these extra characters from the buffer.
        else {
            str[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && len != minChar) {
            printf("Invalid 10-digit number! Number: ");
            ch = 'a';
        }
        else {
            flag = 0;}
    }
}

// This function aims to present a formatted phone number by displaying an array of digits, each consisting of 10 characters.
void displayFormattedPhone(const char* str) {
    int len = 0, i;

    len = strlen(str);

    if (len == 10) {
        i = 0;
        printf("(");
        while (i < 3) {
            printf("%c", str[i]);
            i++;}
        printf(")");
        while (i < 6) {
            printf("%c", str[i]);
            i++;
        }
        printf("-");
        while (i < 10) {
            printf("%c", str[i]);
            i++;}
    }
    else {
        printf("(___)___-____");
    }
    if (str != 0) {
        for (i = 0;str[i] != '\0';i++)
            len++;
    }
}

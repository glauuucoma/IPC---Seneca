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


// SAFE-GUARD:
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
// Copy your work done from Milestone #1 (core.h) into this file
//
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// This function ensures that an integer is input and then returned. If an incorrect value be provided, an error message will be shown.
int inputInt(void);

// This function ensures that a positive integer value is input and subsequently returned. In the event that a zero or a negative value is provided, an error message will be presented.
int inputIntPositive(void);

// This function ensures that an integer value is entered and returned, with inclusivity within a specified range. If a value outside of this range is input, an error message is shown, and the function persists in requesting a valid value within the designated range.
int inputIntRange(int lowerBound, int upperBound);

// This function ensures that a single character value is input and subsequently returned, restricted to a predefined list of valid characters. Should the entered character not be present in the list of valid characters, an error message is shown, and the function continues to prompt for a valid character entry.
char inputCharOption(char str[]);

// This function ensures the input of a C string value that contains a number of characters falling within the range indicated by the 2nd and 3rd arguments.
void inputCString(char* str, int minChar, int maxChar);

// This function is identical to inputCString, but it is specifically intended for numerical values.
void inputCStringNumbers(char* str, int minChar, int maxChar);

// Display array of 10-character numbers as a phone number.
void displayFormattedPhone(const char* str);

// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H

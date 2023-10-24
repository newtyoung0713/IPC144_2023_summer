/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Sheng-Lin Yang
Student ID#: 160443222
Email      : syang153@myseneca.ca
Section    : NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
int inputInt() {
    int getIntInput;
    char newline = 'x';
    do {
        scanf("%d%c", &getIntInput, &newline);
        if (newline != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (newline != '\n');
    return getIntInput;
}

int inputIntPositive() {
    int value;
    // Checking for both options and nonDigit
    do {
        value = inputInt();
        if (value < 1)
            printf("ERROR! Value must be > 0: ");
    } while (value < 1);
    return value;
}

int inputIntRange(int lower, int upper) {
    int value;
    do {
        value = inputInt();
        if (value < lower || value > upper)
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
    } while (value < lower || value > upper);
    return value;
}

char inputCharOption(const char cStrArr[]) {
    int i, flag;
    char newline = 'x';
    do {
        flag = 1;
        scanf("%c%*c", &newline);
        for (i = 0; cStrArr[i] != '\0'; i++)
            if (newline == cStrArr[i])
                flag = 0;
        if (flag) {
            clearInputBuffer();
            printf("ERROR: Character must be one of [%s]: ", cStrArr);
        }
    } while (flag);
    return newline;
}

void inputCString(char *cString, int minNum, int maxNum) {
    int flag = 1;
    char getStr[16] = {'\0'};
    do {
        scanf(" %[^\n]", getStr);
        strcpy(cString, getStr);
        if (strlen(cString) >= minNum && strlen(cString) <= maxNum) {
            cString = getStr;
            flag = 0;
        } else {

            if ((minNum == maxNum) && strlen(cString) != maxNum) {
                // if only i < maxNum, then when we typed chicken, and n will be the last one left
                // and jump to the next line, and n is one character and less than maxNum,
                // so we can type new word after pressed ENTER twice 
                printf("Invalid %d-digit number! Number: ", maxNum);
            } else if (strlen(cString) < minNum) {
                printf("ERROR: String length must be between %d and %d chars: ", minNum, maxNum);
            } else if (strlen(cString) > maxNum) {
                printf("ERROR: String length must be no more than %d chars: ", maxNum);
            }
        }
    } while (flag);
}

void displayFormattedPhone(const char *phone) {
    int i = 0, getIntTrue = 1;
    if (phone == NULL)
        printf("(___)___-____");
    else {
        for (i = 0; phone[i] != '\0'; i++)
            if (!isdigit(phone[i]))
                getIntTrue = 0;
        if (i != 10)
            printf("(___)___-____");
        else if (i == 10 && !getIntTrue)
            printf("(___)___-____");
        else if (i == 10 && getIntTrue)
            printf("(%c%c%c)%c%c%c-%c%c%c%c",
            phone[0], phone[1], phone[2],
            phone[3], phone[4], phone[5],
            phone[6], phone[7], phone[8], phone[9]);
        else {}
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////


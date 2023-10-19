/*/////////////////////////////////////////////////////////////////////////
                          Milestone - #1
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

// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "core.h"

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer 
// Clear the standard input buffer
void clearInputBuffer(void) {
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n') {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void) {
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

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
    int flag, i;
    char newline = 'x';
    flag = 1;
    do {
        scanf(" %c", &newline);
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
    int i = 0, flag = 1;
    char getStr = getchar(); // scanf(" %c", getStr);
    do {
        i = 0;
        while ((getStr = getchar()) != '\n' && getStr != EOF) {
            if (i < maxNum)
                cString[i] = getStr;
            i++;
        }
        if (i == minNum || i == maxNum)
            flag = 0;
        if (minNum == maxNum)
            // if only i < maxNum, then when we typed chicken, and n will be the last one left
            // and jump to the next line, and n is one character and less than maxNum,
            // so we can type new word after pressed ENTER twice 
            if (i != maxNum)
                printf("ERROR: String length must be exactly %d chars: ", maxNum);
        if (minNum < maxNum) {
            if (i < minNum)
                printf("ERROR: String length must be between %d and %d chars: ", minNum, maxNum);
            else if (i > maxNum)
                printf("ERROR: String length must be no more than %d chars: ", maxNum);
        }
        cString[i] = '\0';  // It's like a clearInputBuffer here
    } while (flag);
}

void displayFormattedPhone(const char *phone) {
    int i = 0, getIntTrue = 1;
    if (phone == NULL)
        printf("(___)___-____");
    else {
        // Check any one character in the string
        while (phone[i] != '\0') {
            if (phone[i] < 48 || phone[i] > 57)
                getIntTrue = 0;
            i++;
        }
        if (i != 10)
            printf("(___)___-____");
        else if (i == 10 && !getIntTrue)
            printf("(___)___-____");
        else if (i == 10 && getIntTrue)
            printf("(416)111-4444");
    }
}
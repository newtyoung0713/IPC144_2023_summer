/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Sheng-Lin Yang
Student ID#: 160443222
Email      : syang153@myseneca.ca
Section    : B

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1, DEC = 12;
    int numYr, numMth, day = 1, flag = 1;

    printf("General Well-being Log\n"
           "======================\n");
    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &numYr, &numMth);
        if (numYr < MIN_YEAR || numYr > MAX_YEAR)
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        if (numMth < JAN || numMth > DEC)
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        if ((numYr>= MIN_YEAR && numYr <= MAX_YEAR) && (numMth >= JAN && numMth <= DEC))
            flag = 0;
    } while (flag);
    
    printf("\n");
    printf("*** Log date set! ***\n");
    printf("\n");
    printf("Log starting date: %d-", numYr);

    switch (numMth) {
    case 1:
        printf("JAN");
        break;
    case 2:
        printf("FEB");
        break;
    case 3:
        printf("MAR");
        break;
    case 4:
        printf("APR");
        break;
    case 5:
        printf("MAY");
        break;
    case 6:
        printf("JUN");
        break;
    case 7:
        printf("JUL");
        break;
    case 8:
        printf("AUG");
        break;
    case 9:
        printf("SEP");
        break;
    case 10:
        printf("OCT");
        break;
    case 11:
        printf("NOV");
        break;
    case 12:
        printf("DEC");
        break;
    default:
        break;
    }
    printf("-%02d\n", day);

    return 0;
}
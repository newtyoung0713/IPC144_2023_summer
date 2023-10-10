/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int numYr, numMth, day = 1;
    int flag = 1;
    double morning, evening, sumMorning = 0, sumEvening = 0;

    printf("General Well-being Log\n"
           "======================\n");
    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &numYr, &numMth);
        if (numYr < MIN_YEAR || numYr > MAX_YEAR) {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (numMth < JAN || numMth > DEC) {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        if ((numYr >= MIN_YEAR && numYr <= MAX_YEAR) && (numMth >= JAN && numMth <= DEC)) {
            flag = 0;
        }
    } while (flag);
    
    printf("\n");
    printf("*** Log date set! ***\n");
    printf("\n");

    for (day = 1; day <= LOG_DAYS; day++) {
        printf("%d-", numYr);
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
        
        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morning);
            if (morning < 0.0 || morning > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (morning < 0.0 || morning > 5.0);
        do {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &evening);
            if (evening < 0.0 || evening > 5.0) {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (evening < 0.0 || evening > 5.0);
        printf("\n");
        sumMorning += morning;
        sumEvening += evening;
    }

    printf("Summary\n"
           "=======\n");
    printf("Morning total rating: %6.3lf\n", sumMorning);
    printf("Evening total rating: %6.3lf\n", sumEvening);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3lf\n", sumMorning + sumEvening);
    printf("\n");
    printf("Average morning rating: %4.1lf\n", sumMorning / LOG_DAYS);
    printf("Average evening rating: %4.1lf\n", sumEvening / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n", 
           ((sumMorning / LOG_DAYS) + (sumEvening / LOG_DAYS)) / 2);

    return 0;
}
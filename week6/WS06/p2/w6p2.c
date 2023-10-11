/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
#define MAX_ITEMS 10
#define ST_NUM 1
#define ND_NUM 2
#define RD_NUM 3

int main(void)
{
    const double MIN = 500.00, MAX = 400000.00, minCost = 100.00;
    int items, priority[MAX_ITEMS], itemMax[MAX_ITEMS], itemNum;
    char finance[MAX_ITEMS];
    double mthIncome, cost[MAX_ITEMS], sumCost = 0;

    int flag = 1, q, loopSelection, priFilter, forecastYr = 0, forecastMth = 0;
    double amountPri = 0;

    printf("+--------------------------+\n"
           "+   Wish List Forecaster   |\n"
           "+--------------------------+\n");
    printf("\n");
    
    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf%*c", &mthIncome);
        if (mthIncome < MIN) {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MIN);
            printf("\n");
        }
        else if (mthIncome > MAX) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAX);
            printf("\n");
        }
    } while (mthIncome < MIN || mthIncome > MAX);
    
    printf("\n");
    
    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d%*c", &items);
        if (items < 1 || items > MAX_ITEMS) {
            printf("ERROR: List is restricted to between %d and %d items.\n", ST_NUM, MAX_ITEMS);
            printf("\n");
        }
    } while (items < 1 || items > MAX_ITEMS);
    
    printf("\n");

    for (itemNum = 0; itemNum < items; itemNum++) {
        printf("Item-%d Details:\n", itemNum + 1);
        itemMax[itemNum] = itemNum;
        do {
            printf("   Item cost: $");
            scanf("%lf%*c", &cost[itemNum]);
            if (cost[itemNum] < minCost)
                printf("      ERROR: Cost must be at least $%.2lf\n", minCost);
        } while (cost[itemNum] < minCost);
        do {
            printf("   How important is it to you? [%d=must have, %d=important, %d=want]: ", 
                   ST_NUM, ND_NUM, RD_NUM);
            scanf("%d%*c", &priority[itemNum]);
            if (priority[itemNum] < ST_NUM || priority[itemNum] > RD_NUM)
                printf("      ERROR: Value must be between %d and %d\n", ST_NUM, RD_NUM);
        } while (priority[itemNum] < ST_NUM || priority[itemNum] > RD_NUM);
        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c%*c", &finance[itemNum]);
            if (finance[itemNum] != 'y' && finance[itemNum] != 'n')
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        } while (finance[itemNum] != 'y' && finance[itemNum] != 'n');
        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (itemNum = 0; itemNum < items; itemNum++) {
        printf("%3d  %5d    %5c    %11.2lf\n", 
               itemMax[itemNum] + 1, priority[itemNum], finance[itemNum], cost[itemNum]);
        sumCost += cost[itemNum];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", sumCost);

    do {
        printf("How do you want to forecast your wish list?\n"
               " 1. All items (no filter)\n"
               " 2. By priority\n"
               " 0. Quit/Exit\n"
               "Selection: ");
        scanf("%d%*c", &loopSelection);
        printf("\n");

        switch (loopSelection) {
        case 0:
            flag = 0;
            break;
        case 1:
            forecastYr = (sumCost / mthIncome) / 12;
            forecastMth = (sumCost / mthIncome) > (int)(sumCost / mthIncome) ? 
                          (int)(sumCost / mthIncome) % 12 + 1 : (int)(sumCost / mthIncome);
            printf("====================================================\n"
                   "Filter:   All items\n"
                   "Amount:   $%1.2lf\n"
                   "Forecast: %d years, %d months\n",
                   sumCost, forecastYr, forecastMth);
            q = 0;

            for (itemNum = 0; itemNum < items && q == 0; itemNum++) {
                if (finance[itemNum] == 'y') {
                    printf("NOTE: Financing options are available on some items.\n"
                           "      You can likely reduce the estimated months.\n");
                    q = 1;
                }
            }
            
            printf("====================================================\n\n"); 
            break;
        case 2:
            printf("What priority do you want to filter by? [%d-%d]: ", ST_NUM, RD_NUM);
            scanf("%d", &priFilter);
            printf("\n");

            for (itemNum = 0; itemNum < items; itemNum++)
                if (priority[itemNum] == priFilter)
                    amountPri += cost[itemNum];

            forecastYr = (amountPri / mthIncome) / 12;
            forecastMth = (amountPri / mthIncome) > (int)(amountPri / mthIncome) ? 
                          (int)(amountPri / mthIncome) % 12 + 1 : (int)(amountPri / mthIncome);
            printf("====================================================\n"
                   "Filter:   by priority (%d)\n"
                   "Amount:   $%1.2lf\n"
                    "Forecast: %d years, %d months\n",
                   priFilter, amountPri, forecastYr, forecastMth);
            amountPri = 0;
            q = 0;

            for (itemNum = 0; itemNum < items && q == 0; itemNum++) {
                if (priority[itemNum] == priFilter && finance[itemNum] == 'y') {
                    printf("NOTE: Financing options are available on some items.\n"
                           "      You can likely reduce the estimated months.\n");
                    q = 1;
                }
            }

            printf("====================================================\n\n");
            break;
        default:
            printf("ERROR: Invalid menu selection.\n\n");
            break;
        }
    } while (flag);

    printf("Best of luck in all your future endeavours!\n");
    printf("\n");

    return 0;
}
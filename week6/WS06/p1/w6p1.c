/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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

int main(void)
{
    const double MIN = 500.00, MAX = 400000.00, minCost = 100.00;
    int items, priority[MAX_ITEMS], itemMax[MAX_ITEMS], itemNum;
    char finance[MAX_ITEMS];
    double mthIncome, cost[MAX_ITEMS], sumCost = 0;

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
            printf("ERROR: List is restricted to between 1 and %d items.\n", MAX_ITEMS);
            printf("\n");
        }
    } while (items < 1 || items > MAX_ITEMS);
    printf("\n");
    for (itemNum = 1; itemNum <= items; itemNum++) {
        printf("Item-%d Details:\n", itemNum);
        itemMax[itemNum] = itemNum;
        do {
            printf("   Item cost: $");
            scanf("%lf%*c", &cost[itemNum]);
            if (cost[itemNum] < minCost)
                printf("      ERROR: Cost must be at least $%.2lf\n", minCost);
        } while (cost[itemNum] < minCost);
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d%*c", &priority[itemNum]);
            if (priority[itemNum] < 1 || priority[itemNum] > 3)
                printf("      ERROR: Value must be between 1 and 3\n");
        } while (priority[itemNum] < 1 || priority[itemNum] > 3);
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
    for (itemNum = 1; itemNum <= items; itemNum++) {
        printf("%3d  %5d    %5c    %11.2lf\n", 
               itemMax[itemNum], priority[itemNum], finance[itemNum], cost[itemNum]);
        sumCost += cost[itemNum];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", sumCost);
    printf("Best of luck in all your future endeavours!\n");
    printf("\n");

    return 0;
}
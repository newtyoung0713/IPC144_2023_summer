/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    float smallShirt, mediumShirt, largeShirt;
    int shirtNum;
    int subTotal, taxes, total;

    printf("Set Shirt Prices\n"
           "================\n"
           "Enter the price for a SMALL shirt: $");
    scanf("%f", &smallShirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &mediumShirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &largeShirt);
    printf("\n");
    printf("Shirt Store Price List\n"
           "======================\n");
    printf("SMALL  : $%.2f\n"
           "MEDIUM : $%.2f\n"
           "LARGE  : $%.2f\n", smallShirt, mediumShirt, largeShirt);
    printf("\n");
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirtNum);
    printf("\n");
    printf("Patty's shopping cart...\n"
           "Contains : %d shirts\n", shirtNum);
    
    subTotal = (int)(((smallShirt * shirtNum) + 0.005) * 100);
    printf("Sub-total: $%8.4lf\n", subTotal / 100.0);

    taxes = (int)(((subTotal / 100.0 * TAX) + 0.005) * 100);
    printf("Taxes    : $%8.4lf\n", taxes / 100.0);
    total = subTotal + taxes;
    printf("Total    : $%8.4lf\n", total / 100.0);

    return 0;
/*

Set Shirt Prices
================
Enter the price for a SMALL shirt: $17.96
Enter the price for a MEDIUM shirt: $26.96
Enter the price for a LARGE shirt: $35.97

Shirt Store Price List
======================
SMALL  : $17.96
MEDIUM : $26.96
LARGE  : $35.97

Patty's shirt size is 'S'
Number of shirts Patty is buying: 8

Patty's shopping cart...
Contains : 8 shirts
Sub-total: $143.6800
Taxes    : $ 18.6800
Total    : $162.3600

*/
}
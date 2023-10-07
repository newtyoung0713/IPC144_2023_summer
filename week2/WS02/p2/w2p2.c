/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const double TAX = 0.13, roundUp = 0.005;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    float smallShirt, mediumShirt, largeShirt;
    int patShirtNum, salShirtNum, tomShirtNum, totShirtNum;
    int subTotal, taxes, total;
    int patSubTotal, patTaxes, patTotal;
    int salSubTotal, salTaxes, salTotal;
    int tomSubTotal, tomTaxes, tomTotal;
    int firstAverage, secondAverage;
    int tooniesBalance, looniesBalance, quartersBalance, dimesBalance, nickelsBalance, penniesBalance;
    int tooniesQty, looniesQty, quartersQty, dimesQty, nickelsQty, penniesQty;

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
    printf("Patty's shirt size is '%c'\n"
           "Number of shirts Patty is buying: ", patSize);
    scanf("%d", &patShirtNum);
    printf("\n");
    printf("Tommy's shirt size is '%c'\n"
           "Number of shirts Tommy is buying: ", tomSize);
    scanf("%d", &tomShirtNum);
    printf("\n");
    printf("Sally's shirt size is '%c'\n"
           "Number of shirts Sally is buying: ", salSize);
    scanf("%d", &salShirtNum);
    printf("\n");
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n"
           "-------- ---- ----- --- --------- --------- ---------\n");

    patSubTotal = (int)(((smallShirt * patShirtNum) + roundUp) * 100);
    patTaxes = (int)(((patSubTotal / 100.0 * TAX) + roundUp) * 100);
    patTotal = patSubTotal + patTaxes;
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallShirt, patShirtNum, patSubTotal / 100.0, patTaxes / 100.0, patTotal / 100.0);
    
    salSubTotal = (int)(((mediumShirt * salShirtNum) + roundUp) * 100);
    salTaxes = (int)(((salSubTotal / 100.0 * TAX) + roundUp) * 100);
    salTotal = salSubTotal + salTaxes;
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mediumShirt, salShirtNum, salSubTotal / 100.0, salTaxes / 100.0, salTotal / 100.0);
    
    tomSubTotal = (int)(((largeShirt * tomShirtNum) + roundUp) * 100);
    tomTaxes = (int)(((tomSubTotal / 100.0 * TAX) + roundUp) * 100);
    tomTotal = tomSubTotal + tomTaxes;
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largeShirt, tomShirtNum, tomSubTotal / 100.0, tomTaxes / 100.0, tomTotal / 100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");

    subTotal = patSubTotal + salSubTotal + tomSubTotal;
    taxes = patTaxes + salTaxes + tomTaxes;
    total = patTotal + salTotal + tomTotal;
    printf("%33.4lf %9.4lf %9.4lf\n\n", subTotal / 100.0, taxes / 100.0, total / 100.0);
    printf("Daily retail sales represented by coins\n"
           "=======================================\n"
           "\n");
    printf("Sales EXCLUDING tax\n"
           "Coin     Qty   Balance\n"
           "-------- --- ---------\n");
    printf("%22.4lf\n", (double)subTotal / 100.0);

    tooniesQty = subTotal / 200;
    tooniesBalance = subTotal % 200;
    printf("Toonies  %3d %9.4lf\n", tooniesQty, tooniesBalance / 100.0);

    looniesQty = tooniesBalance / 100;
    looniesBalance = tooniesBalance % 100;
    printf("Loonies  %3d %9.4lf\n", looniesQty, looniesBalance / 100.0);

    quartersQty = looniesBalance / 25;
    quartersBalance = looniesBalance % 25;
    printf("Quarters %3d %9.4lf\n", quartersQty, (double)quartersBalance / 100);

    dimesQty = quartersBalance / 10;
    dimesBalance = quartersBalance % 10;
    printf("Dimes    %3d %9.4lf\n", dimesQty, (double)dimesBalance / 100);

    nickelsQty = dimesBalance / 5;
    nickelsBalance = dimesBalance % 5;
    printf("Nickels  %3d %9.4lf\n", nickelsQty, (double)nickelsBalance / 100);

    penniesQty = nickelsBalance / 1;
    penniesBalance = nickelsBalance % 1;
    printf("Pennies  %3d %9.4lf\n", penniesQty, (double)penniesBalance / 100);
    printf("\n");

    totShirtNum = patShirtNum + salShirtNum + tomShirtNum;
    firstAverage = ((double)subTotal / (double)totShirtNum + 0.005) * 100;
    printf("Average cost/shirt: $%.4lf\n", firstAverage / 10000.0);
    printf("\n");
    printf("Sales INCLUDING tax\n"
           "Coin     Qty   Balance\n"
           "-------- --- ---------\n");
    printf("%22.4lf\n", total / 100.0);

    tooniesQty = subTotal / 200;
    tooniesBalance = subTotal % 200;

    tooniesQty = total / 200;
    tooniesBalance = total % 200;
    printf("Toonies  %3d %9.4lf\n", tooniesQty, (double)tooniesBalance / 100);

    looniesQty = tooniesBalance / 100;
    looniesBalance = tooniesBalance % 100;
    printf("Loonies  %3d %9.4lf\n", looniesQty, (double)looniesBalance / 100);

    quartersQty = looniesBalance / 25;
    quartersBalance = looniesBalance % 25;
    printf("Quarters %3d %9.4lf\n", quartersQty, (double)quartersBalance / 100);

    dimesQty = quartersBalance / 10;
    dimesBalance = quartersBalance % 10;
    printf("Dimes    %3d %9.4lf\n", dimesQty, (double)dimesBalance / 100);

    nickelsQty = dimesBalance / 5;
    nickelsBalance = dimesBalance % 5;
    printf("Nickels  %3d %9.4lf\n", nickelsQty, (double)nickelsBalance / 100);

    penniesQty = nickelsBalance / 1;
    penniesBalance = nickelsBalance % 1;
    printf("Pennies  %3d %9.4lf\n", penniesQty, (double)penniesBalance / 100);
    printf("\n");
    secondAverage = ((double)total / (double)totShirtNum + 0.005) * 100;
    printf("Average cost/shirt: $%.4lf\n", secondAverage / 10000.0);
    
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
Number of shirts Patty is buying: 6

Tommy's shirt size is 'L'
Number of shirts Tommy is buying: 3

Sally's shirt size is 'M'
Number of shirts Sally is buying: 4

Customer Size Price Qty Sub-Total       Tax     Total
-------- ---- ----- --- --------- --------- ---------
Patty    S    17.96   6  107.7600   14.0100  121.7700
Sally    M    26.96   4  107.8400   14.0200  121.8600
Tommy    L    35.97   3  107.9100   14.0300  121.9400
-------- ---- ----- --- --------- --------- ---------
                         323.5100   42.0600  365.5700

Daily retail sales represented by coins
=======================================

Sales EXCLUDING tax
Coin     Qty   Balance
-------- --- ---------
              323.5100
Toonies  161    1.5100
Loonies    1    0.5100
Quarters   2    0.0100
Dimes      0    0.0100
Nickels    0    0.0100
Pennies    1    0.0000

Average cost/shirt: $24.8854

Sales INCLUDING tax
Coin     Qty   Balance
-------- --- ---------
              365.5700
Toonies  182    1.5700
Loonies    1    0.5700
Quarters   2    0.0700
Dimes      0    0.0700
Nickels    1    0.0200
Pennies    2    0.0000

Average cost/shirt: $28.1208

*/
}
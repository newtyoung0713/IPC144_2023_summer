/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Sheng-Lin Yang
Student ID#: 160443222
Email      : syang153myseneca.ca
Section    : B

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const int firstId = 111, secondId = 222, thirdId = 111;
    const char firstTaxStatus = 'Y', secondTaxStatus = 'N', thirdTaxStatus = 'N';
    const double firstPrice = 111.49;
    const double secondPrice = 222.99;
    const double thirdPrice = 334.49;
    double averagePrice, diffPrice;

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n"
           "  Taxed: %c\n"
           "  Price: $%.4lf\n", firstId, firstTaxStatus, firstPrice);
    printf("\n");
    printf("Product-2 (ID:%d)\n"
           "  Taxed: %c\n"
           "  Price: $%.4lf\n", secondId, secondTaxStatus, secondPrice);
    printf("\n");
    printf("Product-3 (ID:%d)\n"
           "  Taxed: %c\n"
           "  Price: $%.4lf\n", thirdId, thirdTaxStatus, thirdPrice);
    printf("\n");
    averagePrice = (firstPrice + secondPrice + thirdPrice) / 3;
    printf("The average of all prices is: $%.4lf\n", averagePrice);
    printf("\n");
    printf("About Relational and Logical Expressions!\n"
           "========================================\n"
           "1. These expressions evaluate to TRUE or FALSE\n"
           "2. FALSE: is always represented by integer value 0\n"
           "3. TRUE : is represented by any integer value other than 0\n"
           "\n");
    printf("Some Data Analysis...\n"
           "=====================\n");
    printf("1. Is product 1 taxable? -> %d\n", firstTaxStatus == 'Y');
    printf("\n");
    printf("2. Are products 2 and 3 both NOT taxable (N)?"
           " -> %d\n", (secondTaxStatus == 'N' && thirdTaxStatus == 'N'));
    printf("\n");
    printf("3. Is product 3 less than testValue ($%.2lf)?"
           " -> %d\n", testValue, thirdPrice < testValue);
    printf("\n");
    printf("4. Is the price of product 3 more than "
           "both product 1 and 2 combined?"
           " -> %d\n", thirdPrice > (firstPrice + secondPrice));
    printf("\n");
    diffPrice = thirdPrice - secondPrice;
    printf("5. Is the price of product 1 equal to or more than the price difference\n"
           "   of product 3 LESS product 2? ->  %d"
           " (price difference: $%.2lf)\n",
            (firstPrice == diffPrice) || (firstPrice > diffPrice), diffPrice);
    printf("\n");
    printf("6. Is the price of product 2 equal to or more than"
           " the average price? -> %d\n",
            (secondPrice == averagePrice) || (secondPrice > averagePrice));
    printf("\n");
    printf("7. Based on product ID, product 1 is unique -> %d\n",
            (firstId != secondId) && (firstId != thirdId));
    printf("\n");
    printf("8. Based on product ID, product 2 is unique -> %d\n",
            (secondId != firstId) && (secondId != thirdId));
    printf("\n");
    printf("9. Based on product ID, product 3 is unique -> %d\n",
          (thirdId != firstId) && (thirdId != secondId));

    return 0;
}
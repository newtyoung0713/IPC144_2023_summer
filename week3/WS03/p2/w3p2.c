/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : Sheng-Lin Yang
Student ID#: 160443222
Email      : syang153myseneca.ca
Section    : B

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void){
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    // for the first table
    char id1typeCoffee, id2typeCoffee, id3typeCoffee;
    int weight1, weight2, weight3;
    char coffeeCream1, coffeeCream2, coffeeCream3;
    // for the second and third table
    char coffeePrefer, cream;
    int servingCream;

    printf("Take a Break - Coffee Shop\n"
           "==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c%*c", &id1typeCoffee);
    printf("Bag weight (g): ");
    scanf("%d%*c", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c%*c", &coffeeCream1);
    printf("\n");
    
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c%*c", &id2typeCoffee);
    printf("Bag weight (g): ");
    scanf("%d%*c", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c%*c", &coffeeCream2);
    printf("\n");

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c%*c", &id3typeCoffee);
    printf("Bag weight (g): ");
    scanf("%d%*c", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c%*c", &coffeeCream3);
    printf("\n");

    printf("---+------------------------+---------------+-------+\n"
           "   |    Coffee              |   Packaged    | Best  |\n"
           "   |     Type               |  Bag Weight   | Served|\n"
           "   +------------------------+---------------+ With  |\n"
           "ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n"
           "---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
           id1typeCoffee == 'l' || id1typeCoffee == 'L',
           id1typeCoffee == 'm' || id1typeCoffee == 'M', 
           id1typeCoffee == 'r' || id1typeCoffee == 'R', weight1, weight1 / GRAMS_IN_LBS, 
           coffeeCream1 == 'y' || coffeeCream1 == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
           id2typeCoffee == 'l' || id2typeCoffee == 'L',
           id2typeCoffee == 'm' || id2typeCoffee == 'M', 
           id2typeCoffee == 'r' || id2typeCoffee == 'R', weight2, weight2 / GRAMS_IN_LBS,
           coffeeCream2 == 'y' || coffeeCream2 == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
           id3typeCoffee == 'l' || id3typeCoffee == 'L',
           id3typeCoffee == 'm' || id3typeCoffee == 'M', 
           id3typeCoffee == 'r' || id3typeCoffee == 'R', weight3, weight3 / GRAMS_IN_LBS,
           coffeeCream3 == 'y' || coffeeCream3 == 'Y');
    printf("\n");
    printf("Enter how you like your coffee...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c%*c", &coffeePrefer);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c%*c", &cream);
    printf("Typical number of daily servings: ");
    scanf(" %d%*c", &servingCream);
    printf("\n");
    printf("The below table shows how your preferences align"
           " to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n"
           "  |     Coffee      |  Packaged   | With  |\n"
           "ID|      Type       | Bag Weight  | Cream |\n"
           "--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", 
           ((coffeePrefer == 'l' || coffeePrefer == 'L') && (id1typeCoffee == 'l' || id1typeCoffee == 'L')) ||
           ((coffeePrefer == 'r' || coffeePrefer == 'R') && (id1typeCoffee == 'r' || id1typeCoffee == 'R')) ||
           ((coffeePrefer == 'm' || coffeePrefer == 'M') && (id1typeCoffee == 'm' || id1typeCoffee == 'M')), 
           ((weight1 == 250) && (servingCream >= 1 && servingCream <= 4)) ||
           ((weight1 == 500) && (servingCream >= 5 && servingCream <= 9)) ||
           ((weight1 == 1000) && (servingCream >= 10)), 
           ((cream == 'y' || cream == 'Y') == (coffeeCream1 == 'y' || coffeeCream1 == 'Y')));
    printf(" 2|       %d         |      %d      |   %d   |\n", 
           ((coffeePrefer == 'l' || coffeePrefer == 'L') && (id2typeCoffee == 'l' || id2typeCoffee == 'L')) ||
           ((coffeePrefer == 'r' || coffeePrefer == 'R') && (id2typeCoffee == 'r' || id2typeCoffee == 'R')) ||
           ((coffeePrefer == 'm' || coffeePrefer == 'M') && (id2typeCoffee == 'm' || id2typeCoffee == 'M')), 
           ((weight2 == 250) && (servingCream >= 1 && servingCream <= 4)) ||
           ((weight2 == 500) && (servingCream >= 5 && servingCream <= 9)) ||
           ((weight2 == 1000) && (servingCream >= 10)), 
           ((cream == 'y' || cream == 'Y') == (coffeeCream2 == 'y' || coffeeCream2 == 'Y')));
    printf(" 3|       %d         |      %d      |   %d   |\n", 
           ((coffeePrefer == 'l' || coffeePrefer == 'L') && (id3typeCoffee == 'l' || id3typeCoffee == 'L')) ||
           ((coffeePrefer == 'r' || coffeePrefer == 'R') && (id3typeCoffee == 'r' || id3typeCoffee == 'R')) ||
           ((coffeePrefer == 'm' || coffeePrefer == 'M') && (id3typeCoffee == 'm' || id3typeCoffee == 'M')), 
           ((weight3 == 250) && (servingCream >= 1 && servingCream <= 4)) ||
           ((weight3 == 500) && (servingCream >= 5 && servingCream <= 9)) ||
           ((weight3 == 1000) && (servingCream >= 10)), 
           ((cream == 'y' || cream == 'Y') == (coffeeCream3 == 'y' || coffeeCream3 == 'Y')));
    printf("\n");
    printf("Enter how you like your coffee...\n");
    printf("\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c%*c", &coffeePrefer);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c%*c", &cream);
    printf("Typical number of daily servings: ");
    scanf(" %d%*c", &servingCream);
    printf("\n");
    printf("The below table shows how your preferences align "
           "to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n"
           "  |     Coffee      |  Packaged   | With  |\n"
           "ID|      Type       | Bag Weight  | Cream |\n"
           "--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", 
           ((coffeePrefer == 'l' || coffeePrefer == 'L') && (id1typeCoffee == 'l' || id1typeCoffee == 'L')) ||
           ((coffeePrefer == 'r' || coffeePrefer == 'R') && (id1typeCoffee == 'r' || id1typeCoffee == 'R')) ||
           ((coffeePrefer == 'm' || coffeePrefer == 'M') && (id1typeCoffee == 'm' || id1typeCoffee == 'M')), 
           ((weight1 == 250) && (servingCream >= 1 && servingCream <= 4)) ||
           ((weight1 == 500) && (servingCream >= 5 && servingCream <= 9)) ||
           ((weight1 == 1000) && (servingCream >= 10)), 
           ((cream == 'y' || cream == 'Y') == (coffeeCream1 == 'y' || coffeeCream1 == 'Y')) ||
           ((cream == 'n' || cream == 'N') == (coffeeCream1 == 'n' || coffeeCream1 == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n", 
           ((coffeePrefer == 'l' || coffeePrefer == 'L') && (id2typeCoffee == 'l' || id2typeCoffee == 'L')) ||
           ((coffeePrefer == 'r' || coffeePrefer == 'R') && (id2typeCoffee == 'r' || id2typeCoffee == 'R')) ||
           ((coffeePrefer == 'm' || coffeePrefer == 'M') && (id2typeCoffee == 'm' || id2typeCoffee == 'M')), 
           ((weight2 == 250) && (servingCream >= 1 && servingCream <= 4)) ||
           ((weight2 == 500) && (servingCream >= 5 && servingCream <= 9)) ||
           ((weight2 == 1000) && (servingCream >= 10)), 
           ((cream == 'y' || cream == 'Y') == (coffeeCream2 == 'y' || coffeeCream2 == 'Y')) ||
           ((cream == 'n' || cream == 'N') == (coffeeCream2 == 'n' || coffeeCream2 == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n", 
           ((coffeePrefer == 'l' || coffeePrefer == 'L') && (id3typeCoffee == 'l' || id3typeCoffee == 'L')) ||
           ((coffeePrefer == 'r' || coffeePrefer == 'R') && (id3typeCoffee == 'r' || id3typeCoffee == 'R')) ||
           ((coffeePrefer == 'm' || coffeePrefer == 'M') && (id3typeCoffee == 'm' || id3typeCoffee == 'M')), 
           ((weight3 == 250) && (servingCream >= 1 && servingCream <= 4)) ||
           ((weight3 == 500) && (servingCream >= 5 && servingCream <= 9)) ||
           ((weight3 == 1000) && (servingCream >= 10)), 
           ((cream == 'y' || cream == 'Y') == (coffeeCream3 == 'y' || coffeeCream3 == 'Y')) ||
           ((cream == 'n' || cream == 'N') == (coffeeCream3 == 'n' || coffeeCream3 == 'N')));
    printf("\n");
    printf("Hope you found a product that suits your likes!\n");
    printf("\n");

    return 0;
}
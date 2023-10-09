/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Sheng-Lin Yang
Student ID#: 160443222
Email      : syang153@myseneca.ca
Section    : B

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apples, oranges, pears, tomatoes, cabbages;
    int portion, newShopping;

    do {
        printf("Grocery Shopping\n"
               "================\n");
        do {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);

            if (apples < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (apples < 0);
        printf("\n");

        do {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);

            if (oranges < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (oranges < 0);
        printf("\n");

        do {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
    
            if (pears < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pears < 0);
        printf("\n");

        do {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
    
            if (tomatoes < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomatoes < 0);
        printf("\n");

        do {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);

            if (cabbages < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbages < 0);
    
        printf("\n");
        printf("--------------------------\n"
               "Time to pick the products!\n"
               "--------------------------\n");
        printf("\n");

        while (apples > 0) {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &portion);

            if (portion > apples) {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
            } else if (portion <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (portion <= apples) {
                apples -= portion;
                if (apples > 0) {
                    printf("Looks like we still need some APPLES...\n");
                } else {
                    printf("Great, that's the apples done!\n");
                    printf("\n");
                }
            } else {}
        }

        while (oranges > 0) {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &portion);

            if (portion > oranges) {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
            } else if (portion <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (portion <= oranges) {
                oranges -= portion;
                if (oranges > 0) {
                    printf("Looks like we still need some ORANGES...\n");
                } else {
                    printf("Great, that's the oranges done!\n");
                    printf("\n");
                }
            } else {}
        }
        
        while (pears > 0) {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &portion);

            if (portion > pears) {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
            } else if (portion <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (portion <= pears) {
                pears -= portion;
                if (pears > 0) {
                    printf("Looks like we still need some PEARS...\n");
                } else {
                    printf("Great, that's the pears done!\n");
                    printf("\n");
                }
            } else {}
        }
        
        while (tomatoes > 0) {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &portion);

            if (portion > tomatoes) {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
            } else if (portion <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (portion <= tomatoes) {
                tomatoes -= portion;
                if (tomatoes > 0) {
                    printf("Looks like we still need some TOMATOES...\n");
                } else {
                    printf("Great, that's the tomatoes done!\n");
                    printf("\n");
                }
            } else {}
        }

        while (cabbages > 0) {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &portion);

            if (portion > cabbages) {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
            } else if (portion <= 0) {
                printf("ERROR: You must pick at least 1!\n");
            } else if (portion <= cabbages) {
                cabbages -= portion;
                if (cabbages > 0) {
                    printf("Looks like we still need some CABBAGES...\n");
                } else {
                    printf("Great, that's the cabbages done!\n");
                    printf("\n");
                }
            } else {}
        }
        
        printf("All the items are picked!\n");
        printf("\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &newShopping);
        printf("\n");
    } while (newShopping == 1);
    
    printf("Your tasks are done for today - enjoy your free time!\n");
    printf("\n");

    return 0;
}
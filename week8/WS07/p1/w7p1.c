/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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

#include <stdio.h>
#define MIN_LIVE 1
#define MAX_LIVE 10
#define MV_FORMULA 0.75
#define SET 5
#define MIN_LTH 10
#define MAX_LTH 70

struct PlayerInfo {
    // PlayerInfo
    char plrName;
    int lives, tsToal;
};
struct GameInfo {
    // GameInfo
    int pathLth, mvLimit;
    int gmBomb[MAX_LTH], gmTs[MAX_LTH];
};

int main(void) {
    int i, flag = 1;
    struct PlayerInfo plrInfo;
    struct GameInfo gmInfo;

    printf("================================\n"
           "         Treasure Hunt!\n"
           "================================\n");
    printf("\n");
    printf("PLAYER Configuration\n"
           "--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &plrInfo.plrName);
    do {
        flag = 1;
        printf("Set the number of lives: ");
        scanf("%d", &plrInfo.lives);
        if (plrInfo.lives < MIN_LIVE || plrInfo.lives > MAX_LIVE) {
            printf("     Must be between %d and %d!\n", MIN_LIVE, MAX_LIVE);
            flag = 0;
        }
    } while (!flag);

    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n"
           "------------------\n");
    do {
        flag = 1;
        printf("Set the path length (a multiple of %d between %d-%d): ", 
               SET, MIN_LTH, MAX_LTH);
        scanf("%d", &gmInfo.pathLth);
        if ((gmInfo.pathLth < MIN_LTH || 
             gmInfo.pathLth > MAX_LTH) || 
             (gmInfo.pathLth % SET)) {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", 
            SET, MIN_LTH, MAX_LTH);
            flag = 0;
        }
    } while (!flag);
    
    do {
        flag = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &gmInfo.mvLimit);
        if (gmInfo.mvLimit < plrInfo.lives || 
            gmInfo.mvLimit > (int)(gmInfo.pathLth * MV_FORMULA)) {
            printf("    Value must be between %d and %d\n", 
            plrInfo.lives, (int)(gmInfo.pathLth * MV_FORMULA));
            flag = 0;
        }
    } while (!flag);

    printf("\n");
    printf("BOMB Placement\n"
           "--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n"
           "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", SET, gmInfo.pathLth);
    for (i = 0; i < gmInfo.pathLth / SET; i++) {
        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i + 1) * 5);
        scanf("%d %d %d %d %d", &gmInfo.gmBomb[i * 5], &gmInfo.gmBomb[(i * 5) + 1], 
              &gmInfo.gmBomb[(i * 5) + 2], &gmInfo.gmBomb[(i * 5) + 3], 
              &gmInfo.gmBomb[(i * 5) + 4]);
    }
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n"
           "------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n"
           "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", SET, gmInfo.pathLth);
    for (i = 0; i < gmInfo.pathLth / SET; i++) {
        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i + 1) * 5);
        scanf("%d %d %d %d %d", &gmInfo.gmTs[i * 5], &gmInfo.gmTs[(i * 5) + 1], 
              &gmInfo.gmTs[(i * 5) + 2], &gmInfo.gmTs[(i * 5) + 3], 
              &gmInfo.gmTs[(i * 5) + 4]);
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n"
           "TREASURE HUNT Configuration Settings\n"
           "------------------------------------\n");
    printf("Player:\n"
           "   Symbol     : %c\n"
           "   Lives      : %d\n"
           "   Treasure   : [ready for gameplay]\n"
           "   History    : [ready for gameplay]\n", plrInfo.plrName, plrInfo.lives);
    printf("\n");
    printf("Game:\n"
           "   Path Length: %d\n", gmInfo.pathLth);
    printf("   Bombs      : ");
    for (i = 0; i < gmInfo.pathLth; i++) {
        printf("%d", gmInfo.gmBomb[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < gmInfo.pathLth; i++) {
        printf("%d", gmInfo.gmTs[i]);
    }
    printf("\n\n");
    printf("====================================\n"
           "~ Get ready to play TREASURE HUNT! ~\n"
           "====================================\n\n");
    return 0;
}
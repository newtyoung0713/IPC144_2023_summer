/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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
#define MIN_LIVE   1
#define MAX_LIVE   10
#define MV_FORMULA 0.75
#define MIN_RANGE  1
#define SET        5
#define MIN_LTH    10
#define MAX_LTH    70
#define EMPTY      '.'
#define BOMB       '!'
#define TS         '$'
#define BOTHBT     '&'

struct PlayerInfo {
    // PlayerInfo
    char plrName;
    int lives, tsToal;
    int bombHistory[MAX_LTH];
};
struct GameInfo {
    // GameInfo
    int pathLth, mvLimit;
    int gmBomb[MAX_LTH], gmTs[MAX_LTH];
};

int main(void) {
    int i, j, k, l, x;
    int flag = 1, mvRange;
    struct PlayerInfo plrInfo;
    struct GameInfo gmInfo;
    char tb2NdLine[MAX_LTH];
    char tb3RdLine[MAX_LTH];
    char tb4ThLine[MAX_LTH];
    for (i = 0; i < MAX_LTH; i++)
        plrInfo.bombHistory[i] = 0; // Initialization the bomb history to all 0
    
    printf("================================\n"
           "         Treasure Hunt!\n"
           "================================\n\n");
    printf("PLAYER Configuration\n"
           "--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf("%c%*c", &plrInfo.plrName);
    do {
        flag = 1;
        printf("Set the number of lives: ");
        scanf("%d%*c", &plrInfo.lives);
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
        scanf("%d%*c", &gmInfo.pathLth);
        if ((gmInfo.pathLth < MIN_LTH || gmInfo.pathLth > MAX_LTH) || (gmInfo.pathLth % SET)) {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", SET, MIN_LTH, MAX_LTH);
            flag = 0;
        }
    } while (!flag);
    
    do {
        flag = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d%*c", &gmInfo.mvLimit);
        if (gmInfo.mvLimit < plrInfo.lives || gmInfo.mvLimit > (int)(gmInfo.pathLth * MV_FORMULA)) {
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
        scanf("%d %d %d %d %d%*c", &gmInfo.gmBomb[i * 5], &gmInfo.gmBomb[(i * 5) + 1], 
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
        scanf("%d %d %d %d %d%*c", &gmInfo.gmTs[i * 5], &gmInfo.gmTs[(i * 5) + 1], 
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
           "   History    : [ready for gameplay]\n\n", plrInfo.plrName, plrInfo.lives);
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

    // Default all the game board are not discover yet
    for (i = 0; i < gmInfo.pathLth; i++)
        tb2NdLine[i] = '-';

    // The for loop for play the game until either lives or limit equals to 0
    for (i = 0, plrInfo.tsToal = 0; (plrInfo.lives > 0 && gmInfo.mvLimit > 0);) {
        // Print the space in front of the player's name & the player's name
        if (mvRange >= MIN_RANGE && mvRange <= gmInfo.pathLth && plrInfo.bombHistory[mvRange - 1]) {
            for (i = 0; i < mvRange + 1; i++)
                printf(" ");
            printf("%c\n", plrInfo.plrName);            
        }

        // Print the 2nd line
        printf("  ");
        for (k = 0; k < gmInfo.pathLth; k++)
            printf("%c", tb2NdLine[k]);
        printf("\n");

        // Print the 3rd line - Method 3
        printf("  ");
        for (l = 0, j = 0; l < gmInfo.pathLth; l++) {
            tb3RdLine[l] = (l + 1) % 10 != 0 ? '|' : ++j;   // Making the game board like |||||||||1|||||||||2
            (l + 1) % 10 != 0 ? printf("%c", tb3RdLine[l]) : printf("%d", tb3RdLine[l]);
        }
        printf("\n");

        // Print the 4th line - Method 3
        printf("  ");
        for (x = 0; x < gmInfo.pathLth; x++) {
            tb4ThLine[x] = (x + 1) % 10 != 0 ? (x + 1) % 10 : 0;    // Making the game board like 1234567890
            printf("%d", tb4ThLine[x]);
        }
        printf("\n");

        printf("+---------------------------------------------------+\n"
               "  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n"
               "+---------------------------------------------------+\n",
               plrInfo.lives, plrInfo.tsToal, gmInfo.mvLimit);

        do {
            flag = 1;
            printf("Next Move [%d-%d]: ", MIN_RANGE, gmInfo.pathLth);
            scanf("%d%*c", &mvRange);
            
            if (mvRange < MIN_RANGE || mvRange > gmInfo.pathLth) 
                printf("  Out of Range!!!\n");
            if (mvRange >= MIN_RANGE && mvRange <= gmInfo.pathLth) {
                plrInfo.bombHistory[mvRange - 1] = 1;
                flag = 0;
            }
        } while (flag);

        printf("\n");
        if (tb2NdLine[mvRange - 1] != '-') {
            printf("===============> Dope! You've been here before!\n\n");
        } else if (plrInfo.bombHistory[mvRange - 1] && !(gmInfo.gmBomb[mvRange - 1]) && !(gmInfo.gmTs[mvRange - 1])) {
            printf("===============> [%c] ...Nothing found here... [%c]\n\n", EMPTY, EMPTY);
            gmInfo.mvLimit--;
            tb2NdLine[mvRange - 1] = EMPTY;
        } else if (plrInfo.bombHistory[mvRange - 1] && (gmInfo.gmBomb[mvRange - 1]) && (gmInfo.gmTs[mvRange - 1])) {
            printf("===============> [%c] !!! BOOOOOM !!! [%c]\n", BOTHBT, BOTHBT);
            printf("===============> [%c] $$$ Life Insurance Payout!!! [%c]\n\n", BOTHBT, BOTHBT);
            gmInfo.mvLimit--;
            plrInfo.lives--;
            plrInfo.tsToal++;
            tb2NdLine[mvRange - 1] = BOTHBT;
        } else if (plrInfo.bombHistory[mvRange - 1] && gmInfo.gmBomb[mvRange - 1]) {
            printf("===============> [%c] !!! BOOOOOM !!! [%c]\n\n", BOMB, BOMB);
            gmInfo.mvLimit--;
            plrInfo.lives--;
            tb2NdLine[mvRange - 1] = BOMB;
        } else if (plrInfo.bombHistory[mvRange - 1] && gmInfo.gmTs[mvRange - 1]) {
            printf("===============> [%c] $$$ Found Treasure! $$$ [%c]\n\n", TS, TS);
            gmInfo.mvLimit--;
            plrInfo.tsToal++;
            tb2NdLine[mvRange - 1] = TS;
        } else { tb2NdLine[mvRange - 1] = 'e'; }

        if (plrInfo.lives == 0)
            printf("No more LIVES remaining!\n\n");
        if (gmInfo.mvLimit == 0)
            printf("No more MOVES remaining!\n\n");
    }

    // Print the result of the game board after game over
    // Print the space in front of the player's name & the player's name
    if (mvRange >= MIN_RANGE && mvRange <= gmInfo.pathLth) {
        for (i = 0; i < mvRange + 1; i++)
            printf(" ");
        printf("%c\n", plrInfo.plrName);            
    }

    // Print the 2nd line
    printf("  ");
    for (k = 0; k < gmInfo.pathLth; k++)
        printf("%c", tb2NdLine[k]);
    printf("\n");

    // Print the 3rd line - Method 3
    printf("  ");
    for (l = 0, j = 0; l < gmInfo.pathLth; l++) {
        tb3RdLine[l] = (l + 1) % 10 != 0 ? '|' : ++j;
        (l + 1) % 10 != 0 ? printf("%c", tb3RdLine[l]) : printf("%d", tb3RdLine[l]);
    }
    printf("\n");

    // Print the 4th line - Method 3
    printf("  ");
    for (x = 0; x < gmInfo.pathLth; x++) {
        tb4ThLine[x] = (x + 1) % 10 != 0 ? (x + 1) % 10 : 0;
        printf("%d", tb4ThLine[x]);
    }
    printf("\n");

    printf("+---------------------------------------------------+\n"
           "  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n"
           "+---------------------------------------------------+\n",
           plrInfo.lives, plrInfo.tsToal, gmInfo.mvLimit);

    printf("\n");
    printf("##################\n"
           "#   Game over!   #\n"
           "##################\n\n"
           "You should play again and try to beat your score!\n\n");

    return 0;
}
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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
    int num, totNum;
    char loopType;
    printf("+----------------------+\n"
           "Loop application STARTED\n"
           "+----------------------+\n");
    printf("\n");
    
    do{
        printf("D = do/while | W = while | F = for | Q = quit\n"
               "Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d%*c", &loopType, &totNum);

        if (loopType != 'D' && loopType != 'W' && loopType != 'F' && loopType != 'Q'){
            printf("ERROR: Invalid entered value(s)!\n");
            printf("\n");
        }
        else if ((loopType == 'D' || loopType == 'W' || loopType == 'F') && (totNum < 3 || totNum > 20)){
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            printf("\n");
        }
        else if (loopType == 'Q' && (totNum < 0 || totNum > 0)){
            printf("ERROR: To quit, the number of iterations should be 0!\n");
            printf("\n");
        } else {}
        
        if ((loopType == 'D') && (totNum >= 3 && totNum <= 20)){
            printf("DO-WHILE: ");
            do {
                printf("%c", loopType);
                totNum--;
            } while (totNum > 0);
            printf("\n");
            printf("\n");
        }
        else if ((loopType == 'W') && (totNum >= 3 && totNum <= 20)){
            printf("WHILE   : ");
            while (totNum > 0) {
                printf("%c", loopType);
                totNum--;
            };
            printf("\n");
            printf("\n");
        }
        else if ((loopType == 'F') && (totNum >= 3 && totNum <= 20)){
            printf("FOR     : ");
            for (num = 0; num < totNum; num++){
                printf("%c", loopType);
            }
            printf("\n");
            printf("\n");
        } else {}
    } while (loopType != 'Q' || totNum != 0);

    printf("\n");
    printf("+--------------------+\n"
           "Loop application ENDED\n"
           "+--------------------+\n");
    printf("\n");
    return 0;
}
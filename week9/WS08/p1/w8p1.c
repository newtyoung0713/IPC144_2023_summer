/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *wNum) {
	int num = 0;
	// Method - 4
	do {
		scanf("%d", &num);
		if (num <= 0) 
			printf("ERROR: Enter a positive value: ");
	} while (num <= 0);
	if (wNum != NULL)
		*wNum = num;

	return num;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *dblNum) {
	double dNum = 0.0;
	// Method - 4
	do {
		scanf("%lf", &dNum);
		if (dNum <= 0) 
			printf("ERROR: Enter a positive value: ");
	} while (dNum <= 0);
	if (dblNum != NULL)
		*dblNum = dNum;
	
	return dNum;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int dryFood) {
	printf("Cat Food Cost Analysis\n"
		   "======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n"
		   "NOTE: A 'serving' is %dg\n\n", dryFood, GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sz) {
	struct CatFoodInfo foodInfo = {0};
	printf("Cat Food Product #%d\n"
		   "--------------------\n", sz + 1);
	printf("SKU           : ");
	getIntPositive(&foodInfo.sku);
	printf("PRICE         : $");
	getDoublePositive(&foodInfo.price);
	printf("WEIGHT (LBS)  : ");
	foodInfo.lbs = getDoublePositive(NULL);
	printf("CALORIES/SERV.: ");
	foodInfo.calories = getIntPositive(NULL);
	printf("\n");

	return foodInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void) {
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double *price, double *lbs, int calories) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *lbs, calories);
}

// 7. Logic entry point
void start() {
	struct CatFoodInfo foodInfo[MAX] = { {0, 0.0, 0.0, 0}, {0, 0.0, 0.0, 0}, {0, 0.0, 0.0, 0} };
	int i;

	openingMessage(MAX);

	for (i = 0; i < MAX; i++) {
		foodInfo[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX; i++)
		displayCatFoodData(foodInfo[i].sku, &foodInfo[i].price, &foodInfo[i].lbs, foodInfo[i].calories);
}
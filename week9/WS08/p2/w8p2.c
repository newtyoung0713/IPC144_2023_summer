/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
	foodInfo.caloPerServing = getIntPositive(NULL);
	printf("\n");

	return foodInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void) {
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double *price, double *lbs, int caloPerServing) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *lbs, caloPerServing);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *pounds, double *dblNum) {
	// dblNum should be pounds
	double cvtDblNum = 0;
	cvtDblNum = *pounds / CVT_LBSKG;
	if (dblNum != NULL)
		*dblNum = cvtDblNum;
	return cvtDblNum;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *pounds, int *intNum) {
	// intNum should be grams
	int cvtIntNum = 0;
	cvtIntNum = convertLbsKg(pounds, NULL) * 1000;
	if (intNum != NULL)
		*intNum = cvtIntNum;
	return cvtIntNum;
}

// 10. convert lbs: kg and g
void convertLbs(const double *pounds, double *dblNum, int *intNum) {
		double cvtKg = *pounds / CVT_LBSKG;
		int cvtGram = (*pounds / CVT_LBSKG) * 1000;
	if (intNum != NULL && dblNum != NULL) {
		*dblNum = cvtKg;
		*intNum = cvtGram;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int portion, const int totalGram, double *resPortion) {
	double testRes = 0;
	if (resPortion == NULL)
		resPortion = &testRes;
	*resPortion = (double)totalGram / (double)portion;
	return *resPortion;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double price, const double *totalServe, double *costPerServe) {
	double testServe = 0;
	if (costPerServe == NULL)
		costPerServe = &testServe;
	*costPerServe = price / *totalServe;
	return *costPerServe;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double price, const double *totalCalo, double *costPerCalo) {
	double testCalo = 0;
	if (costPerCalo == NULL)
		costPerCalo = &testCalo;
	*costPerCalo = price / *totalCalo;
	return *costPerCalo;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo) {
	struct ReportData getRptData;

	getRptData.sku = catFoodInfo.sku;
	getRptData.price = catFoodInfo.price;
	getRptData.lbs = catFoodInfo.lbs;
	getRptData.caloPerServing = catFoodInfo.caloPerServing;
	convertLbsKg(&getRptData.lbs, &getRptData.kilograms);
	convertLbsG(&getRptData.lbs, &getRptData.grams);
	calculateServings(GRAMS, getRptData.grams, &getRptData.totServing);
	calculateCostPerServing(catFoodInfo.price, &getRptData.totServing, &getRptData.costPerServing);
	const double totCalories = getRptData.totServing * getRptData.caloPerServing;
	calculateCostPerCal(getRptData.price, &totCalories, &getRptData.costPerCalories);
	return getRptData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void) {
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS);
	printf("---------------\n"
	       "SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n"
	       "------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData RptData, const int chpest) {
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
			 RptData.sku, RptData.price, RptData.lbs, 
			 RptData.kilograms, RptData.grams, RptData.caloPerServing, 
			 RptData.totServing, RptData.costPerServing, RptData.costPerCalories);
	if (chpest == (int)RptData.costPerServing) printf(" ***");
	printf("\n");
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo info) {
	printf("Final Analysis\n"
          "--------------\n"
          "Based on the comparison data, the PURRR-fect economical option is:\n"
          "SKU:%07d Price: $%.2lf\n\n"
          "Happy shopping!\n\n", info.sku, info.price);
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start() {
	struct CatFoodInfo foodInfo[MAX] = { {0} };
	struct ReportData rptData[MAX];
	int i = 0, cprPrice, chpestIdx;

	openingMessage(MAX);
	for (i = 0; i < MAX; i++)
		foodInfo[i] = getCatFoodInfo(i);
	displayCatFoodHeader();
	for (i = 0; i < MAX; i++)
		displayCatFoodData(foodInfo[i].sku, &foodInfo[i].price, &foodInfo[i].lbs, foodInfo[i].caloPerServing);
	printf("\n");
	for (i = 0; i < MAX; i++)
		rptData[i] = calculateReportData(foodInfo[i]);

	displayReportHeader();
	cprPrice = rptData[0].costPerServing;
	for (i = 0; i < MAX; i++) {
		displayReportData(rptData[i], cprPrice);
		if (cprPrice > rptData[i].costPerServing) {
			cprPrice = rptData[i].costPerServing;
			chpestIdx = i;
		}
	}

	printf("\n");
	displayFinalAnalysis(foodInfo[chpestIdx]);
}
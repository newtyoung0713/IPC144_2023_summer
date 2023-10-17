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


// ----------------------------------------------------------------------------
// defines/macros
#define CVT_LBSKG  2.20462
#define MAX        3
#define DRYFOOD	   3
#define GRAMS      64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int sku;
	double price;
	double lbs;
	int caloPerServing;
};

struct ReportData {
    int sku;
    double price;
    double lbs;
    double kilograms;
    int grams;
    int caloPerServing;
    double totServing;
    double costPerServing;
    double costPerCalories;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sz);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double *price, double *lbs, int caloPerServing);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *cvtLbsKg, double *);


// 9. convert lbs: g
int convertLbsG(const double *cvtLbsG, int *);


// 10. convert lbs: kg / g
void convertLbs(const double *lbs, double *, int *);


// 11. calculate: servings based on gPerServ
double calculateServings(const int portion, const int totalGram, double *resPortion);

// 12. calculate: cost per serving
double calculateCostPerServing(const double price, const double *totalServe, double *costPerServe);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double price, const double *totalCalo, double *costPerCalo);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData RptData, const int chpest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo info);

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start();

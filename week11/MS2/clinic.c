/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
   // max = 7;
   int i = 0, noRecord = 0;
   displayPatientTableHeader();
   for (i = 0; i < max; i++)
      if (patient[i].patientNumber) {
         displayPatientData(&patient[i], fmt);
         noRecord = 1;
      }
   if (!patient->patientNumber && !noRecord)
      printf("\n*** No records found ***\n");
   printf("\n");
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) {
   int choose, flag = 1;
   do {
      flag = 1;
      printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
      choose = inputIntRange(0, 2);
      switch (choose) {
      case 0:
         printf("\n");
         flag = 0;
         break;
      case 1:
         searchPatientByPatientNumber(patient, max);
         break;
      case 2:
         searchPatientByPhoneNumber(patient, max);
         break;
      default:
         break;
      }
   } while (flag);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {
   int i = 0, fullList = 0;
   int index = 0;
   do {
      if (patient[i].patientNumber != '\0') {
         fullList = 1;
      } else {
         fullList = 0;
         index = i;
      }
      i++;
   } while (fullList);
   patient[index].patientNumber = nextPatientNumber(patient, max);
   // put the number value inside of struct
   if (i == max + 1) {
      printf("ERROR: Patient listing is FULL!");
   } else if (!fullList) {
      inputPatient(&patient[index]);
      printf("*** New patient record added ***");
   }
   printf("\n\n");
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) {
   int index = 0, patNum = 0;
   printf("Enter the patient number: ");
   patNum = inputIntPositive();
   index = findPatientIndexByPatientNum(patNum, patient, max);

   if (index < 0) {
      printf("ERROR: Patient record not found!\n");
   } else {
      printf("\n");
      menuPatientEdit(&patient[index]);
   }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) {
   int i = 0, index = 0, patNum = 0;
   char quitOption = '\0';
   printf("Enter the patient number: ");
   patNum = inputIntPositive();
   index = findPatientIndexByPatientNum(patNum, patient, max);

   if (index < 0) {
      printf("\n");
      printf("ERROR: Patient record not found!\n");
   } else {
      printf("\n");
      displayPatientData(&patient[index], FMT_FORM);
      printf("\n");
      printf("Are you sure you want to remove this patient record? (y/n): ");
      quitOption = inputCharOption("YyNn");
      if (quitOption == 'y' || quitOption == 'Y') {
         printf("Patient record has been removed!\n");
         for (i = 0; i < max; i++)
            patient[index].patientNumber = '\0';
         for (i = 0; i < NAME_LEN; i++)
            patient[index].name[i] = '\0';
         for (i = 0; i < PHONE_LEN; i++)
            patient[index].phone.number[i] = '\0';
      } else if (quitOption == 'n' || quitOption == 'N') {
         printf("Operation aborted.\n");
      }
   }
   printf("\n");
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
   int patientNum, noRecords = 0;
   printf("\n");
   printf("Search by patient number: ");
   patientNum = inputIntPositive();
   printf("\n");
   noRecords = findPatientIndexByPatientNum(patientNum, &patient[noRecords], max);
   if (noRecords != -1)
      displayPatientData(&patient[noRecords], 1);
   else
      printf("*** No records found ***\n");
   printf("\n");
   suspend();
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
   int i = 0, noRecords = 0, matchPhoneNum;
   char patientPhone[PHONE_LEN + 1];
   printf("\n");
   printf("Search by phone number: ");
   inputCString(patientPhone, PHONE_LEN, PHONE_LEN + 1);
   printf("\n");
   displayPatientTableHeader();
   for (i = 0; i < max; i++) {
      matchPhoneNum = strcmp(patient[i].phone.number, patientPhone);
      if (matchPhoneNum == 0) {
         displayPatientData(&patient[i], matchPhoneNum);
         noRecords = 1;
      }
   }
   if (i == max && noRecords == 0)
      printf("\n*** No records found ***\n");
   printf("\n");
   clearInputBuffer();
   suspend();
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {
   int i = 0, foundLrgest = 0;
   for (i = 0; i < max; i++){
      if (foundLrgest < patient[i].patientNumber)
         foundLrgest = patient[i].patientNumber;
   }
   return foundLrgest + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
   int i = 0, index = -1;
   for (i = 0; i < max; i++)
      if (patientNumber == patient[i].patientNumber)
         index = i;
   return index;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {
   int flag = 1;
   printf("Patient Data Input\n"
          "------------------\n"
          "Number: %05d\n"
          "Name  : ", patient->patientNumber);
   do {
      if (*patient->name) {
         flag = 1;
      } else {
         inputCString(patient->name, 3, NAME_LEN);
         printf("\n");
         flag = 0;
      }
   } while (flag);
   if (!flag) {
      inputPhoneData(&patient->phone);
   }
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone) {
   int choose = 0;
   printf("Phone Information\n"
          "-----------------\n"
          "How will the patient like to be contacted?\n"
          "1. Cell\n"
          "2. Home\n"
          "3. Work\n"
          "4. TBD\n"
          "Selection: ");
   choose = inputIntRange(1, 4);
   printf("\n");

   if (choose == 1) {
      strcpy(phone->description, "CELL");
   } else if (choose == 2) {
      strcpy(phone->description, "HOME");
   } else if (choose == 3) {
      strcpy(phone->description, "WORK");
   } else if (choose == 4) {
      strcpy(phone->description, "TBD");
   }
   if (choose != 4) {
      printf("Contact: %s\n", phone->description);
      printf("Number : ");
      inputCString(phone->number, PHONE_LEN, PHONE_LEN);
      printf("\n");
      clearInputBuffer();
   }
}
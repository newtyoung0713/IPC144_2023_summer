/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
   // max = 7;
   int i = 0, noRecord = 0;
   displayPatientTableHeader();
   for (i = 0; i < max; i++)
      // Checking does the patientNumber exist
      if (patient[i].patientNumber) {
         displayPatientData(&patient[i], fmt);
         noRecord = 1;
      }
   if (!patient->patientNumber && !noRecord)
      printf("\n*** No records found ***\n");
   printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) {
   int i = 0, fullList;
   int index = 0;
   do {
      fullList = 0;
      // To search and get the index of the last patientNumber
      if (patient[i].patientNumber == '\0') {
         fullList = 1;
         index = i;
      }
      i++;
   } while (i < max && fullList == 0);
   if (fullList == 0){
      printf("ERROR: Patient listing is FULL!");
   } else {
      // To assign the new Patient Number into the new index of patientNumber
      patient[index].patientNumber = nextPatientNumber(patient, max);
      // To store the number value inside of struct
      inputPatient(&patient[index]);
      printf("*** New patient record added ***");
   }
   printf("\n\n");
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max) {
   int index = 0, patientNum = 0;
   printf("Enter the patient number: ");
   patientNum = inputIntPositive();
   index = findPatientIndexByPatientNum(patientNum, patient, max);

   if (index < 0) {
      printf("ERROR: Patient record not found!\n");
   } else {
      printf("\n");
      menuPatientEdit(&patient[index]);
   }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max) {
   int i = 0, index = 0, patientNum = 0, flag = 1;
   char quitOption = '\0', invalidChar;
   printf("Enter the patient number: ");
   patientNum = inputIntPositive();
   index = findPatientIndexByPatientNum(patientNum, patient, max);

   if (index < 0) {
      printf("\n");
      printf("ERROR: Patient record not found!\n");
   } else {
      printf("\n");
      displayPatientData(&patient[index], FMT_FORM);
      printf("\n");
      printf("Are you sure you want to remove this patient record? (y/n): ");
      do {
         // Only y or n is acceptable
         // So use another char variable to store extra character
         scanf(" %c%c", &quitOption, &invalidChar);
         // Even the first character is correct, the second one if not a NULL teminetor
         // It will NOT clean the patient data
         if (quitOption == 'y' && invalidChar == '\n') {
            printf("Patient record has been removed!\n");
            for (i = 0; i < max; i++)
               patient[index].patientNumber = '\0';
            for (i = 0; i < NAME_LEN; i++)
               patient[index].name[i] = '\0';
            for (i = 0; i < PHONE_LEN; i++)
               patient[index].phone.number[i] = '\0';
            flag = 0;
         // Even the first character is correct, the second one if not a NULL teminetor
         // It will NOT accept the user's denial
         } else if (quitOption == 'n' && invalidChar == '\n') {
            printf("Operation aborted.\n");
            flag = 1;
         } else {
            clearInputBuffer();
            printf("ERROR: Character must be one of [yn]: ");
            flag = 1;
         }
      } while (flag);
   }
   printf("\n");
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) {
   // maxPatient = 20, maxAppointments = 50
   int i, j;
   // To sort appointments order
   bubbleSort(data->appointments, data->maxAppointments);
   displayScheduleTableHeader(NULL, FMT_TABLE);  
   
   for (i = 0; i < data->maxAppointments; i++)
      for (j = 0; j < data->maxPatient; j++)
         // To get more appointment information from patient data
         if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
            displayScheduleData(&data->patients[j], &data->appointments[i], FMT_FORM);
   printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) {
   int i, j;
   struct Date date;
   // Customer function for user date
   inputDate(&date, NULL, 1, 0);
   printf("\n");
   // To sort appointments order
   bubbleSort(data->appointments, data->maxAppointments);
   displayScheduleTableHeader(&date, 0);
   for (i = 0; i < data->maxAppointments; i++)
      for (j = 0; j < data->maxPatient; j++)
         // To get more appointment information from patient data
         if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
            // To determine user input equals to database information
            if (date.year == data->appointments[i].date.year && 
                date.month == data->appointments[i].date.month && 
                date.day == data->appointments[i].date.day) 
               displayScheduleData(&data->patients[j], &data->appointments[i], 0);
   printf("\n");
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appoints, int maxAppointments, 
                    struct Patient* patients, int maxPatient) {
   // maxPatient = 20, maxAppointments = 50
   struct Date date;
   struct Time time;
   int patientNum, i, flag = 0, index = 0, getIndex, valid = 1;
   printf("Patient Number: ");
   patientNum = inputIntPositive();
   getIndex = findPatientIndexByPatientNum(patientNum, patients, maxAppointments);
   if (getIndex > -1) {
      do {
         if (!flag) {
            inputDate(&date, &time, 1, 1);
         } else {
         // To check is the user appointment time in the available range
            inputDate(&date, &time, 1, 1);
            while ((time.hour < 10 || time.hour > 14) ||
                  (time.hour == 14 && time.min > 0) ||
                  (time.min % (TIME_SIXTY / 2) != 0)) {
               printf("ERROR: Time must be between %d:%02d and %d:%02d in %d minute intervals.\n\n",
                     TIME_SIXTY / 6, TIME_ZERO, TIME_SIXTY / 4 - 1, TIME_ZERO, TIME_SIXTY / 2);
               inputDate(NULL, &time, 0, 1);
            };
            valid = 1;
            flag = 1;
         }

         i = 0;
         while (valid) {
            if (date.year != appoints[i].date.year ||
                  date.month != appoints[i].date.month ||
                  date.day != appoints[i].date.day) {
               i++;
               valid = 1;
               flag = 1;
            // printf("compare i=%d, valid=%d, flag=%d\n", i + 1, valid, flag);
            } else {
               valid = 0;
               flag = 1;
            }
         }
            if (time.hour != appoints[i].time.hour ||
                time.min != appoints[i].time.min) {
               valid = 0;
               flag = 0;
            // printf("compare i=%d, valid=%d, flag=%d\n", i + 1, valid, flag);
            } else {
               valid = 1;
               flag = 1;
            }

         // for (i = 0; date.year != appoints[i].date.year ||
         //          date.month != appoints[i].date.month ||
         //          date.day != appoints[i].date.day; i++) {
         //    for (j = i; time.hour != appoints[j].time.hour ||
         //                time.min != appoints[j].time.min; j++) {
         //    printf("compare i=%d, valid=%d, flag=%d\n", i + 1, valid, flag);
         //       // valid = 0;
         //       // flag = 1;
         //    }
         // } 
                  
         printf("1st valid=%d, flag=%d\n", valid, flag);
         printf("date.year=%d,\ndate.month=%d,\ndate.day=%d\n", date.year, date.month, date.day);
         printf("time.hour=%d, time.min=%d\n", time.hour, time.min);
         printf("appoints[%d].date.year=%d, date.month=%d, date.day=%d\n", 
               i + 1, appoints[i].date.year, appoints[i].date.month, appoints[i].date.day);
         printf("appoints[%d].time.hour=%d, time.min=%d\n", 
               i + 1, appoints[i].time.hour, appoints[i].time.min);

         printf("2nd valid=%d, flag=%d\n", valid, flag);
         i = 0;
         while (!valid && i < maxAppointments) {
            // To search and get the index of the last patientNumber
            if (appoints[i].patientNumber < 1)
               valid = 0;
               flag = 0;
            i++;
         }

         printf("3rd valid=%d, flag=%d\n", valid, flag);
         if (!valid && !flag) {
            // To get the index and assign user-type date, time and patient number into database 
            index = i;
            appoints[index].date = date;
            appoints[index].time = time;
            appoints[index].patientNumber = patientNum;
            printf("\n*** Appointment scheduled! ***\n\n");
            flag = 0;
            valid = 0;
         // } else if (valid == 1 && flag == 1) {
         } else {
            printf("\nERROR: Appointment timeslot is not available!\n\n");
            flag = 1;
            valid = 1;
         }
      } while (flag || valid);
   } else {
      printf("ERROR: Patient record not found!\n\n");
   }
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appoints, int maxAppointments, 
                       struct Patient* patients, int maxPatient) {
   struct Date date;
   int patientNum, getIndex, i = 0, valid = 0, patientIndex;
   printf("Patient Number: ");
   patientNum = inputIntPositive();
   getIndex = findPatientIndexByPatientNum(patientNum, patients, maxAppointments);
   if (getIndex > -1) {
      inputDate(&date, NULL, 1, 0);
      // To compare is the appointment time exist
      for (i = 0; i < maxAppointments && !valid; i++) {
         if (patientNum == appoints[i].patientNumber &&
             date.year == appoints[i].date.year &&
             date.month == appoints[i].date.month &&
             date.day == appoints[i].date.day)
            valid = 1;
      }
      // The index from the order in appointmentData.txt
      // i - 1(include 0 to be 1)
      patientIndex = i - 1;
      printf("\n");
      if (patientIndex > -1) {
         displayPatientData(&patients[getIndex], FMT_FORM);
         printf("Are you sure you want to remove this appointment (y,n): ");
         if (inputCharOption("yn") == 'y')
            appoints[patientIndex].patientNumber = '\0';
         printf("\nAppointment record has been removed!\n\n");
      }
   } else {
      printf("ERROR: Patient record not found!\n\n");
   }
}

void bubbleSort(struct Appointment appoints[], int max) {
    int i, j;
    struct Appointment temp;
    // Storing all the date and time values in minutes for comparison
    for (i = 0; i < max; i++)
        appoints[i].time.min = (appoints[i].date.year * 12 * 30 * 24 * 60) + 
                               (appoints[i].date.month * 30 * 24 * 60) + 
                               (appoints[i].date.day * 24 * 60) + 
                               (appoints[i].time.hour * 60) + 
                                appoints[i].time.min;

    // Using bubble sort to compare minutes and then swap the structs
    for (i = max - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (appoints[j].time.min > appoints[j + 1].time.min) {
                temp = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = temp;
            }
        }
    }

    // Converting total minutes back to minutes
    for (i = 0; i < max; i++)
        appoints[i].time.min = appoints[i].time.min - 
                              (appoints[i].date.year * 12 * 30 * 24 * 60) - 
                              (appoints[i].date.month * 30 * 24 * 60) - 
                              (appoints[i].date.day * 24 * 60) - 
                              (appoints[i].time.hour * 60);

}

void inputDate(struct Date *date, struct Time *time, int withDate, int withTime) {
   // int hour, mins;
   int lastDay = DATE_BIG;
   if (withDate) {
      printf("Year        : ");
      date->year = inputIntPositive();
      printf("Month (%d-%d): ", DATE_FIRST, MONTH_DEC);
      date->month = inputIntRange(DATE_FIRST, MONTH_DEC);
      printf("Day (%d-", DATE_FIRST);
      if (date->month == 4 || date->month == 9 || date->month == 11)
         lastDay = DATE_SML;
      if (date->month == 2)
         lastDay = FEB_REG;
      if (date->year % 4 == 0 && date->month == 2)
         lastDay = FEB_SPCL;
      printf("%d)  : ", lastDay);
      date->day = inputIntRange(DATE_FIRST, lastDay);
   }
   if (withTime) {
      printf("Hour (%d-%d)  : ", TIME_ZERO, TIME_HOUR);
      time->hour = inputIntRange(TIME_ZERO, TIME_HOUR);
      printf("Minute (%d-%d): ", TIME_ZERO, TIME_MINS);
      time->min = inputIntRange(TIME_ZERO, TIME_MINS);
   }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
   int patientNum, noRecords = 0;
   printf("\n");
   printf("Search by patient number: ");
   patientNum = inputIntPositive();
   printf("\n");
   noRecords = findPatientIndexByPatientNum(patientNum, &patient[noRecords], max);
   if (noRecords != -1)
      displayPatientData(&patient[noRecords], FMT_FORM);
   else
      printf("*** No records found ***\n");
   printf("\n");
   suspend();
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max) {
   int i = 0, foundLrgest = 0;
   for (i = 0; i < max; i++){
      if (foundLrgest < patient[i].patientNumber)
         foundLrgest = patient[i].patientNumber;
   }
   return foundLrgest + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) {
   // max = 20;
   FILE *fp = NULL;
   int i = 0;
   fp = fopen(datafile, "r");
   if (fp != NULL) {
      for (i = 0; i < max; i++) {
         fscanf(fp, "%d|%15[^|]|%4[^|]|%10[^\n]\n", &patients[i].patientNumber, patients[i].name, 
                                          patients[i].phone.description, patients[i].phone.number);
      }
      fclose(fp);
   }
   return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {
   // max = 20;
   int i = 0, count = 0;
   FILE *fp = NULL;
   fp = fopen(datafile, "r");
   if (fp != NULL) {
      for (i = 0; i < max; i++) {
         fscanf(fp, "%d,%d,%d,%d,%d,%d\n", 
         &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, 
                        &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);
         // To get the last patient number, and count the total patient
         if (appoints[i].patientNumber != 0)
            count++;
      }
      fclose(fp);
   }
   return count;
}
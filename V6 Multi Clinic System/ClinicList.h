/**
  ***********************************************************************************************
  * @file           : ClinicList.h                                                              *
  * @author         : Omar Shrif Mohamed                                                        *
  * @details        : Contains the Declaration of the listed functions provided in each mode    *
  * @date           : 15/12/2023                                                                *
  ***********************************************************************************************
  */

#ifndef CLINICLIST_H
#define CLINICLIST_H

/** ************************* Includes Section Start **************************************** **/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>

#include"Platform_Types.h"

/** ************************* Includes Section End ****************************************** **/

//----------------------------------------------------------------------------------------------

/** ************************* Processor Section Start *************************************** **/

#pragma pack (1)

/** ************************* Processor Section End ***************************************** **/

//----------------------------------------------------------------------------------------------

/** ************************* Macro Section Start ******************************************* **/

#define Not_Exist      0
#define Not_available  0
#define Max_Name_Size  20

/** ************************* Macro Section End ********************************************* **/

//----------------------------------------------------------------------------------------------

/** ************************* Global Declaration Section Start ****************************** **/

typedef struct patient_t
{
    struct patient_t *next;
    s8 name[Max_Name_Size];
    s8 age;
    s8 id;
    s8 slot;
    s8 gender;

}patient;

typedef struct
{
    patient *ListHead;
    patient *ListTail;

}clinic;


/** ************************* Global Declaration Section End ******************************** **/

//----------------------------------------------------------------------------------------------

/** ************************* Sub-Program Declaration Section Start ************************* **/

/**
  * @brief Adds new empty object to the list
           from patient type and it is allocated
           in the dynamic memory
  */
void admin_AddPatient(clinic *my_clinic,FILE *my_file);


/**
  * @brief Removes object form the list of
           patient type and deallocate it form the dynamic memory
  */
void admin_RemovePatient(clinic *my_clinic,FILE *my_file);


/**
  * @brief Change anything from the patient informations
  */
void admin_EditPatient(clinic *my_clinic,FILE *my_file);


/**
  * @brief Reserve a slot in the clinic form the available slots
  */
void admin_ReserveSlot(clinic *my_clinic,FILE *my_file);


/**
  * @brief Cancel patient reserved slot in the clinic
  */
void admin_CancelReservation(clinic *my_clinic,FILE *my_file);


/**
  * @brief Display all Patients information found in the Clinic List
  */
void admin_Display_PatientList(clinic *my_clinic,FILE *my_file);


/**
  * @brief View existing patient record
  */
void user_ViewPatientRecord(clinic *my_clinic,FILE *my_file);


/**
  * @brief View clinic reservations for today
  */
void user_ViewTodayReservations(clinic *my_clinic,FILE *my_file);


/**
  * @brief Clears Clinic Patients information
  */
void DestroyAllData(clinic *my_clinic);

/** ************************* Sub-Program Declaration Section End *************************** **/


 #endif //CLINICLIST_H

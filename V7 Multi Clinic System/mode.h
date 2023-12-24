/**
  ***********************************************************************************************
  * @file           : mode.h                                                                    *
  * @author         : Omar Shrif Mohamed                                                        *
  * @details        : Contains the system modes functions Declaration                           *
  * @date           : 15/12/2023                                                                *
  ***********************************************************************************************
  */

#ifndef MODE_H
#define MODE_H

/** ************************* Includes Section Start **************************************** **/

#include"ClinicList.h"

/** ************************* Includes Section End ****************************************** **/

//----------------------------------------------------------------------------------------------

/** ************************* Macro Section Start ******************************************* **/

#define default_password 1234

/** ************************* Macro Section End ********************************************* **/

//----------------------------------------------------------------------------------------------

/** ************************* Sub-Program Declaration Section Start ************************* **/


/**
  * @brief Mode for a worker/doctor in the clinic
  */
void adminMode(clinic *my_clinic,FILE *my_file);


/**
  * @brief Mode for a patient/one want to know information
  */
void userMode(clinic *my_clinic,FILE *my_file);


/**
  * @brief Clears all informations
  */
void ClearTheClinic(clinic *my_clinic);


/** ************************* Sub-Program Declaration Section End *************************** **/

#endif //MODE_H

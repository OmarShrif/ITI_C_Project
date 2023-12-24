#ifndef CLINICLIST_H
#define CLINICLIST_H
#include<stdio.h>
#include<stdlib.h>
#pragma pack (1)
#define Not_Exist  0
#define Not_available  0

 typedef struct N
 {
	 char name[20];
	 int age;
	 char gender;
	 int id;
	 int slot;
	 struct N *next;
 }patient;
 
static int CheckId(int num);
static patient *GetPatient(int num);
static void Patient(int num);
static void NewName(char oldName[],char newName[]);
void AddPatient();
void EditPatient();
void ReserveSlot();
void CancelReservation();
void ViewPatientRecord();
void ViewTodayReservations();

 #endif //CLINICLIST_H
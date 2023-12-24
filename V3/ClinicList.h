#ifndef CLINICLIST_H
#define CLINICLIST_H

#define Not_Exist  0
#define Not_available  0

#pragma pack (1)
typedef struct N
{
    struct N *next;
    char name[20];
    int age;
    int id;
    int slot;
    char gender;
}patient;
#pragma pack (1)

extern patient *head;
extern patient *tail;

void AddPatient(void);
void RemovePatient(void);
void EditPatient(void);
void ReserveSlot(void);
void CancelReservation(void);
void ViewPatientRecord(void);
void ViewTodayReservations(void);

 #endif //CLINICLIST_H

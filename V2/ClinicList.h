#ifndef CLINICLIST_H
#define CLINICLIST_H

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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"ClinicList.h"

patient *head = NULL;
patient *tail = NULL;
int slots[5] = {0};

static int CheckId(int num)
{
	patient *current = head;
	int i=0;
	while(current != NULL)
	{
		i++;
		if(current->id == num)
			return i;
		current=current->next;
	}
	return 0;
}

static patient* GetPatient(int num)
{
	patient *current = head;
	while(1)
	{
		if(current->id == num)
			return current;
		current=current->next;
	}
}

static void Patient(int num)
{
	patient *current = head;
	while(1)
	{
		if(current->id == num)
		{
			printf("Name : %s\n",current->name);
			printf("Age : %d\n",current->age);
			if('m' == (current->gender))
				printf("Gender : male\n");
			else if('f' == (current->gender))
				printf("Gender : female\n");
			if(current->slot == 1)
				printf("Slot : 2pm to 2:30pm\n\n");
			else if(current->slot == 2)
				printf("Slot : 2:30pm to 3pm\n\n");
			else if(current->slot == 3)
				printf("Slot : 3pm to 3:30pm\n\n");
			else if(current->slot == 4)
				printf("Slot : 4pm to 4:30pm\n\n");
			else if(current->slot == 5)
				printf("Slot : 4:30pm to 5pm\n\n");
			else
				printf("Slot : has no reservation\n\n");
			break;
		}
		current=current->next;
	}
}

static void NewName(char oldName[],char newName[])
{
    int count=0;
    while(newName[count]!='\0')
    {
		oldName[count]=newName[count];
		count++;
    }
    oldName[count]='\0';
}

void AddPatient(void)
{
	int Id = 0;
	printf("Enter patient id : ");
	scanf("%d",&Id);
	if(Not_Exist == CheckId(Id))
	{
		patient *NewPatient = (patient *)malloc(sizeof(patient));
		NewPatient->id=Id;
		NewPatient->slot=0;
	    fflush(stdin); /* Clear the Buffer to get string */
		printf("Enter patient name : ");
		gets(NewPatient->name);
		printf("Enter patient age : ");
		scanf("%d",&(NewPatient->age));
		printf("Enter patient gender (m) for male , (f) for female: ");
		scanf(" %c",&(NewPatient->gender));
		printf("\n");

		if(head == NULL)
			head = NewPatient;
		else
			tail->next=NewPatient;
		tail = NewPatient;
		tail->next=NULL;
		printf("Patient Added !!\n\n");
	}
	else
		printf("This id is already exists ,reject entry !!\n\n");
}

void RemovePatient(void)
{
	int Id = 0;
	printf("Enter patient id : ");
	scanf("%d",&Id);
	if(Not_Exist != CheckId(Id))
	{
		Patient(Id);
		printf("\n");
		patient *NewPatient=GetPatient(Id);
        if(Not_Exist != NewPatient->slot)
        {
            slots[(NewPatient->slot)-1]--;
            NewPatient->slot=0;
        }

		if(head == NewPatient)
			head = NewPatient->next;
		else if(tail == NewPatient)
            tail->next=NULL;
        else
        {
            //needs to be completed
        }
        free(NewPatient);
		printf("Patient Removed !!\n\n");
	}
	else
		printf("This id doesn't exist ,reject entry !!\n\n");
}

void EditPatient(void)
{
	int Id;
	printf("Enter patient id : ");
	scanf("%d",&Id);
	if(Not_Exist != CheckId(Id))
	{
		Patient(Id);
		patient *NewPatient=GetPatient(Id);
        int selected = 0;
		while(1)
		{
			printf("To Edit Patient Name        Choose --> 1\n");
			printf("To Edit Patient age         Choose --> 2\n");
			printf("To Edit Patient Gender      Choose --> 3\n");
			printf("To Edit Patient id          Choose --> 4\n");
			printf("To stop Editing             Choose --> 0 or any input\n");
			scanf("%d",&selected);
			if(selected == 1)
			{
				char Name[20]={0};
                fflush(stdin); /* Clear the Buffer to get string */
				printf("Enter patient name : ");
				gets(Name);
				NewName(NewPatient->name,Name);
				printf("Name changed !!\n\n");
			}
			else if(selected == 2)
			{
				printf("Enter patient age : ");
				scanf("%d",&(NewPatient->age));
				printf("Age changed !!\n\n");
			}
			else if(selected == 3)
			{
				printf("Enter patient gender (m) for male , (f) for female: ");
				scanf(" %c",&(NewPatient->gender));
				printf("Gender changed !!\n\n");
			}
			else if(selected == 4)
			{
				int ID;
				printf("Enter patient id : ");
				scanf("%d",&ID);
				if(CheckId(ID) == Not_Exist)
				{
					NewPatient->id=ID;
					printf("Id changed !!\n\n");
				}
				else
					printf("This id is already exists ,reject entry !!\n\n");
			}
			else
				break;

            selected = 0;
		}
	}
	else
		printf("This id dosn't exist ,reject entry !!\n\n");
}

void ReserveSlot(void)
{
    int Id,Slot;
    printf("Enter patient id : ");
    scanf("%d",&Id);
    if(Not_Exist != CheckId(Id))
    {
        patient *NewPatient=GetPatient(Id);
        if(Not_Exist == NewPatient->slot)
        {
            if(slots[0]!=Not_available && slots[1]!=Not_available && slots[2]!=Not_available && slots[3]!=Not_available && slots[4]!=Not_available)
                printf("There is no empty slot !!\n\n");
            else
            {
                printf("\n");
                printf("Available slots :\n");
                if(slots[0]==Not_available)
                    printf("For from 2pm to 2:30pm     choose --> 1\n");
                if(slots[1]==Not_available)
                    printf("For from 2:30pm to 3pm     choose --> 2\n");
                if(slots[2]==Not_available)
                    printf("For from 3pm to 3:30pm     choose --> 3\n");
                if(slots[3]==Not_available)
                    printf("For from 4pm to 4:30pm     choose --> 4\n");
                if(slots[4]==Not_available)
                    printf("For from 4:30pm to 5pm     choose --> 5\n");


                printf("\n");
                printf("Enter chosen slot : ");
                scanf("%d",&Slot);
                if(Slot>0 && Slot<6)
                {
                    NewPatient->slot=Slot;
                    slots[Slot-1]++;
                    printf("Slot Reserved !!\n\n");
                }
                else
                {
                    printf("wrong choice ,reject entry !!\n\n");
                }
            }
        }
        else
        {
            printf("patient already has a reservation !!\n\n");
        }
    }
    else
    {
        printf("This id dosn't exist ,reject entry !!\n\n");
    }
}

void CancelReservation(void)
{
	int Id;
	printf("Enter patient id : ");
	scanf("%d",&Id);
	if(Not_Exist != CheckId(Id))
	{
        patient *NewPatient=GetPatient(Id);
        if(Not_Exist == NewPatient->slot)
        {
            printf("patient has no reservation !!\n\n");
        }
        else
        {
            slots[(NewPatient->slot)-1]--;
            NewPatient->slot=0;
            printf("Reservation Canceled !!\n\n");
        }
	}
	else
		printf("This id dosn't exist ,reject entry !!\n\n");
}

void ViewPatientRecord(void)
{
	int Id;
	printf("Enter patient id : ");
	scanf("%d",&Id);
	if(Not_Exist != CheckId(Id))
		Patient(Id);
	else
		printf("This id dosn't exist ,reject entry !!\n\n");
}

void ViewTodayReservations(void)
{
	patient *current = head;
	if(head == NULL)
		printf("There are no reservations today!!\n");
	else if(slots[0]==Not_available && slots[1]==Not_available && slots[2]==Not_available && slots[3]==Not_available && slots[4]==Not_available)
		printf("There are no reservations today!!\n\n");
	else
	{
		while(current != NULL)
		{
			if((current->slot)>0)
			{
				printf("Patient id : %d \t reservation ",current->id);
				if(current->slot == 1)
					printf("slot  2pm to 2:30pm\n\n");
				else if(current->slot == 2)
					printf("slot  2:30pm to 3pm\n\n");
				else if(current->slot == 3)
					printf("slot  3pm to 3:30pm\n\n");
				else if(current->slot == 4)
					printf("slot  4pm to 4:30pm\n\n");
				else if(current->slot == 5)
					printf("slot  4:30pm to 5pm\n\n");
			}
			current=current->next;
		}
	}
}

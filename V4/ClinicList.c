/**
  ***********************************************************************************************
  * @file           : ClinicList.c                                                              *
  * @author         : Omar Shrif Mohamed                                                        *
  * @details        : Contains the list of functions provided in each mode                      *
  * @date           : 15/12/2023                                                                *
  ***********************************************************************************************
  */

/** ************************* Includes Section Start **************************************** **/

#include"ClinicList.h"

/** ************************* Includes Section End ****************************************** **/

//----------------------------------------------------------------------------------------------

/** ************************* Global Variables Section Start ******************************** **/

patient *head = NULL;
patient *tail = NULL;
int slots[5] = {0};

/** ************************* Global Variables Section End ********************************** **/

//----------------------------------------------------------------------------------------------

/** ************************* Sub-Program Declaration Section Start ************************* **/

static int CheckId(int num);
static patient* GetPatient(int num);
static void Patient_Info(int num,FILE *my_file);
static void ChangeName(char oldName[],char newName[]);

/** ************************* Sub-Program Declaration Section End *************************** **/

/**
  * @brief Adds new empty object to the list
           from patient type and it is allocated in the dynamic memory
  */
void admin_AddPatient(FILE *my_file)
{
	int Id = 0;
	printf("Enter patient id : ");
	scanf("%d",&Id);
	fprintf(my_file,"Enter patient id : %i\n",Id);
	if(Not_Exist == CheckId(Id))
	{
		patient *NewPatient = (patient *)malloc(sizeof(patient));
		NewPatient->id=Id;
		NewPatient->slot=0;
	    fflush(stdin); /* Clear the Buffer to get string */
		printf("Enter patient name : ");
		gets(NewPatient->name);
		fprintf(my_file,"Enter patient name : %s\n",NewPatient->name);
		printf("Enter patient age : ");
		scanf("%d",&(NewPatient->age));
		fprintf(my_file,"Enter patient age : %i\n",NewPatient->age);
		printf("Enter patient gender (m) for male , (f) for female: ");
		scanf(" %c",&(NewPatient->gender));
		fprintf(my_file,"Enter patient gender (m) for male , (f) for female: %c\n\n",NewPatient->gender);
		printf("\n");

		if(head == NULL)
			head = NewPatient;
		else
			tail->next=NewPatient;
		tail = NewPatient;
		tail->next=NULL;
		printf("Patient Added !!\n\n");
		fprintf(my_file,"Patient Added !!\n\n");
	}
	else
    {
		printf("This id is already exists ,reject entry !!\n\n");
		fprintf(my_file,"This id is already exists ,reject entry !!\n\n");
    }
}

void admin_RemovePatient(FILE *my_file)
{
	int Id = 0;
	printf("Enter patient id : ");
	scanf("%d",&Id);
    fprintf(my_file,"Enter patient id : %i\n",Id);
	if(Not_Exist != CheckId(Id))
	{
		Patient_Info(Id,my_file);
		printf("\n");
		fprintf(my_file,"\n");
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
		fprintf(my_file,"Patient Removed !!\n\n");
	}
	else
    {
		printf("This id doesn't exist ,reject entry !!\n\n");
		fprintf(my_file,"This id doesn't exist ,reject entry !!\n\n");
    }
}

void admin_EditPatient(FILE *my_file)
{
	int Id;
	printf("Enter patient id : ");
	scanf("%d",&Id);
    fprintf(my_file,"Enter patient id : %i\n",Id);
	if(Not_Exist != CheckId(Id))
	{
		Patient_Info(Id,my_file);
		patient *NewPatient=GetPatient(Id);
        int Selection = 0;
		while(1)
		{
			printf("To Edit Patient Name        Choose --> 1\n");
			printf("To Edit Patient age         Choose --> 2\n");
			printf("To Edit Patient Gender      Choose --> 3\n");
			printf("To Edit Patient id          Choose --> 4\n");
			printf("To stop Editing             Choose --> 0 or any input\n");

			fprintf(my_file,"To Edit Patient Name        Choose --> 1\n");
			fprintf(my_file,"To Edit Patient age         Choose --> 2\n");
			fprintf(my_file,"To Edit Patient Gender      Choose --> 3\n");
			fprintf(my_file,"To Edit Patient id          Choose --> 4\n");
			fprintf(my_file,"To stop Editing             Choose --> 0 or any input\n");
			scanf("%d",&Selection);
            fprintf(my_file,"\nSelection --> %i\n\n",Selection);
			if(Selection == 1)
			{
				char Name[20]={0};
                fflush(stdin); /* Clear the Buffer to get string */
				printf("Enter patient name : ");
				fprintf(my_file,"Enter patient name : ");
				gets(Name);
				ChangeName(NewPatient->name,Name);
				printf("Name changed !!\n\n");
				fprintf(my_file,"Name changed !!\n\n");
			}
			else if(Selection == 2)
			{
				printf("Enter patient age : ");
				scanf("%d",&(NewPatient->age));
				fprintf(my_file,"Enter patient age : %i\n",NewPatient->age);
				printf("Age changed !!\n\n");
				fprintf(my_file,"Age changed !!\n\n");
			}
			else if(Selection == 3)
			{
				printf("Enter patient gender (m) for male , (f) for female: ");
				scanf(" %c",&(NewPatient->gender));
				fprintf(my_file,"Enter patient gender (m) for male , (f) for female: %c\n",NewPatient->gender);
				printf("Gender changed !!\n\n");
				fprintf(my_file,"Gender changed !!\n\n");
			}
			else if(Selection == 4)
			{
				int ID;
				printf("Enter patient id : ");
				scanf("%d",&ID);
				fprintf(my_file,"Enter patient id : %i\n",ID);
				if(CheckId(ID) == Not_Exist)
				{
					NewPatient->id=ID;
					printf("Id changed !!\n\n");
					fprintf(my_file,"Id changed !!\n\n");
				}
				else
                {
					printf("This id is already exists ,reject entry !!\n\n");
					fprintf(my_file,"This id is already exists ,reject entry !!\n\n");
                }
			}
			else
				break;

            Selection = 0;
		}
	}
	else
    {
		fprintf(my_file,"This id dosn't exist ,reject entry !!\n\n");
    }
}

void admin_ReserveSlot(FILE *my_file)
{
    int Id,Slot;
    printf("Enter patient id : ");
    scanf("%d",&Id);
    fprintf(my_file,"Enter patient id : %i\n",Id);
    if(Not_Exist != CheckId(Id))
    {
        patient *NewPatient=GetPatient(Id);
        if(Not_Exist == NewPatient->slot)
        {
            if(slots[0]!=Not_available && slots[1]!=Not_available &&
               slots[2]!=Not_available && slots[3]!=Not_available && slots[4]!=Not_available)
            {
                printf("There is no empty slot !!\n\n");
                fprintf(my_file,"There is no empty slot !!\n\n");
            }
            else
            {
                printf("\nAvailable slots :\n");
                fprintf(my_file,"\nAvailable slots :\n");
                if(slots[0]==Not_available)
                {
                    printf("For from 2pm to 2:30pm     choose --> 1\n");
                    fprintf(my_file,"For from 2pm to 2:30pm     choose --> 1\n");
                }
                if(slots[1]==Not_available)
                {
                    printf("For from 2:30pm to 3pm     choose --> 2\n");
                    fprintf(my_file,"For from 2:30pm to 3pm     choose --> 2\n");
                }
                if(slots[2]==Not_available)
                {
                    printf("For from 3pm to 3:30pm     choose --> 3\n");
                    fprintf(my_file,"For from 3pm to 3:30pm     choose --> 3\n");
                }
                if(slots[3]==Not_available)
                {
                    printf("For from 4pm to 4:30pm     choose --> 4\n");
                    fprintf(my_file,"For from 4pm to 4:30pm     choose --> 4\n");
                }
                if(slots[4]==Not_available)
                {
                    printf("For from 4:30pm to 5pm     choose --> 5\n");
                    fprintf(my_file,"For from 4:30pm to 5pm     choose --> 5\n");
                }


                printf("\nEnter chosen slot : ");
                scanf("%d",&Slot);
                fprintf(my_file,"\nEnter chosen slot : %i\n\n",Slot);
                if(Slot>0 && Slot<6)
                {
                    NewPatient->slot=Slot;
                    slots[Slot-1]++;
                    printf("Slot Reserved !!\n\n");
                    fprintf(my_file,"Slot Reserved !!\n\n");
                }
                else
                {
                    printf("wrong choice ,reject entry !!\n\n");
                    fprintf(my_file,"wrong choice ,reject entry !!\n\n");
                }
            }
        }
        else
        {
            printf("patient already has a reservation !!\n\n");
            fprintf(my_file,"patient already has a reservation !!\n\n");
        }
    }
    else
    {
        printf("This id dosn't exist ,reject entry !!\n\n");
        fprintf(my_file,"This id dosn't exist ,reject entry !!\n\n");
    }
}

void admin_CancelReservation(FILE *my_file)
{
	int Id;
	printf("Enter patient id : ");
	scanf("%d",&Id);
	fprintf(my_file,"Enter patient id : %\n",Id);
	if(Not_Exist != CheckId(Id))
	{
        patient *NewPatient=GetPatient(Id);
        if(Not_Exist == NewPatient->slot)
        {
            printf("patient has no reservation !!\n\n");
            fprintf(my_file,"patient has no reservation !!\n\n");
        }
        else
        {
            slots[(NewPatient->slot)-1]--;
            NewPatient->slot=0;
            printf("Reservation Canceled !!\n\n");
            fprintf(my_file,"Reservation Canceled !!\n\n");
        }
	}
	else
    {
		printf("This id dosn't exist ,reject entry !!\n\n");
		fprintf(my_file,"This id dosn't exist ,reject entry !!\n\n");
    }
}

void user_ViewPatientRecord(FILE *my_file)
{
	int Id;
	printf("Enter patient id : ");
	scanf("%d",&Id);
	fprintf(my_file,"Enter patient id : %i\n",Id);
	if(Not_Exist != CheckId(Id))
		Patient_Info(Id,my_file);
	else
    {
		printf("This id dosn't exist ,reject entry !!\n\n");
		fprintf(my_file,"This id dosn't exist ,reject entry !!\n\n");
    }
}

void user_ViewTodayReservations(FILE *my_file)
{
	patient *current = head;
	if(head == NULL)
    {
		printf("There are no reservations today!!\n");
		fprintf(my_file,"There are no reservations today!!\n");
    }
	else if(slots[0]==Not_available && slots[1]==Not_available &&
         slots[2]==Not_available && slots[3]==Not_available && slots[4]==Not_available)
    {
		printf("There are no reservations today!!\n\n");
		fprintf(my_file,"There are no reservations today!!\n\n");
    }
	else
	{
		while(current != NULL)
		{
			if((current->slot)>0)
			{
				printf("Patient id : %d \t reservation ",current->id);
				fprintf(my_file,"Patient id : %d \t reservation ",current->id);
				if(current->slot == 1)
                {
					printf("slot  2pm to 2:30pm\n\n");
					fprintf(my_file,"slot  2pm to 2:30pm\n\n");
                }
				else if(current->slot == 2)
                {
					printf("slot  2:30pm to 3pm\n\n");
					fprintf(my_file,"slot  2:30pm to 3pm\n\n");
                }
				else if(current->slot == 3)
                {
					printf("slot  3pm to 3:30pm\n\n");
					fprintf(my_file,"slot  3pm to 3:30pm\n\n");
                }
				else if(current->slot == 4)
                {
					printf("slot  4pm to 4:30pm\n\n");
					fprintf(my_file,"slot  4pm to 4:30pm\n\n");
                }
				else if(current->slot == 5)
                {
					printf("slot  4:30pm to 5pm\n\n");
					fprintf(my_file,"slot  4:30pm to 5pm\n\n");
                }
			}
			current=current->next;
		}
	}
}

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

static void Patient_Info(int num,FILE *my_file)
{
	patient *current = head;
	while(1)
	{
		if(current->id == num)
		{
			printf("Name : %s\n",current->name);
			printf("Age : %d\n",current->age);

			fprintf(my_file,"Name : %s\n",current->name);
			fprintf(my_file,"Age : %d\n",current->age);
			if('m' == (current->gender))
            {
				printf("Gender : male\n");
				fprintf(my_file,"Gender : male\n");
            }
			else if('f' == (current->gender))
            {
				printf("Gender : female\n");
				fprintf(my_file,"Gender : female\n");
            }
			if(current->slot == 1)
            {
				printf("Slot : 2pm to 2:30pm\n\n");
				fprintf(my_file,"Slot : 2pm to 2:30pm\n\n");
            }
			else if(current->slot == 2)
            {
				printf("Slot : 2:30pm to 3pm\n\n");
				fprintf(my_file,"Slot : 2:30pm to 3pm\n\n");
            }
			else if(current->slot == 3)
            {
				printf("Slot : 3pm to 3:30pm\n\n");
				fprintf(my_file,"Slot : 3pm to 3:30pm\n\n");
            }
			else if(current->slot == 4)
            {
				printf("Slot : 4pm to 4:30pm\n\n");
				fprintf(my_file,"Slot : 4pm to 4:30pm\n\n");
            }
			else if(current->slot == 5)
            {
				printf("Slot : 4:30pm to 5pm\n\n");
				fprintf(my_file,"Slot : 4:30pm to 5pm\n\n");
            }
			else
			{
				printf("Slot : has no reservation\n\n");
				fprintf(my_file,"Slot : has no reservation\n\n");
			}
			break;
		}
		current=current->next;
	}
}

static void ChangeName(char oldName[],char newName[])
{
    int count=0;
    while(newName[count]!='\0')
    {
		oldName[count]=newName[count];
		count++;
    }
    oldName[count]='\0';
}

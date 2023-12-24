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

u8 slots[5] = {0};

/** ************************* Global Variables Section End ********************************** **/

//----------------------------------------------------------------------------------------------

/** ************************* Sub-Program Declaration Section Start ************************* **/

static int CheckId(clinic *my_clinic,int num);
static patient* GetPatient(clinic *my_clinic,int num);
static void Patient_Info(clinic *my_clinic,int num,FILE *my_file);
static s32 Age_Entry_validation(FILE *my_file);
static u8 gender_Entry_validation(FILE *my_file);

/** ************************* Sub-Program Declaration Section End *************************** **/

void admin_AddPatient(clinic *my_clinic,FILE *my_file)
{
	s32 Id = 0;
	printf("Enter patient id : ");
	scanf("%d",&Id);
	fprintf(my_file,"Enter patient id : %i\n",Id);
	if(Not_Exist == CheckId(my_clinic,Id))
	{
		patient *NewPatient = (patient *)malloc(sizeof(patient));
		if(NewPatient)
        {
            NewPatient->id=Id;
            NewPatient->slot=0;

            fflush(stdin); /* Clear the Buffer to get string */
            s8 name_buffer[Max_Name_Size];
            printf("Enter patient name (Not More than 40 character): ");
            gets(NewPatient->name);
            fprintf(my_file,"Enter patient name (Not More than 40 character): %s\n",NewPatient->name);
            while(NewPatient->name[0] == '\0')
            {
                printf("\nInvalid Name !!\n\n");
                fprintf(my_file,"\nInvalid Name !!\n\n");
                printf("Enter patient name (Not More than 40 character): ");
                gets(NewPatient->name);
                fprintf(my_file,"Enter patient name (Not More than 40 character): %s\n",NewPatient->name);
            }
            NewPatient->name[Max_Name_Size-1] = '\0';

            NewPatient->age = Age_Entry_validation(my_file);

            NewPatient->gender = gender_Entry_validation(my_file);

            if(NULL == my_clinic->ListHead)
            {
                my_clinic->ListHead = NewPatient;
            }
            else
            {
                my_clinic->ListTail->next = NewPatient;
            }
            my_clinic->ListTail = NewPatient;
            my_clinic->ListTail->next=NULL;
            printf("Patient Added !!\n\n");
            fprintf(my_file,"Patient Added !!\n\n");
        }
        else
        {
            printf("Failed to add patient due to the heap !!\n\n");
            fprintf(my_file,"Failed to add patient due to the heap !!\n\n");
        }
	}
	else
    {
		printf("This id is already exists ,reject entry !!\n\n");
		fprintf(my_file,"This id is already exists ,reject entry !!\n\n");
    }
}

void admin_RemovePatient(clinic *my_clinic,FILE *my_file)
{
	int Id = 0;
	printf("Enter patient id : ");
	scanf("%d",&Id);
    fprintf(my_file,"Enter patient id : %i\n",Id);
	if(Not_Exist != CheckId(my_clinic,Id))
	{
		Patient_Info(my_clinic,Id,my_file);
		patient *NewPatient = GetPatient(my_clinic,Id);
        if(Not_Exist != NewPatient->slot)
        {
            slots[(NewPatient->slot)-1]--;
            NewPatient->slot=0;
        }
        if(my_clinic->ListHead == my_clinic->ListTail)
        {
			my_clinic->ListHead = NULL;
			my_clinic->ListTail = NULL;
        }
		else if(my_clinic->ListHead == NewPatient)
        {
			my_clinic->ListHead = NewPatient->next;
        }
		else if(my_clinic->ListTail == NewPatient)
        {
            patient *current = my_clinic->ListHead;
            while(current != NULL)
            {
                if(current->next == my_clinic->ListTail)
                {
                    break;
                }
                current=current->next;
            }
            current->next = NULL;
            my_clinic->ListTail = current;
        }
        else
        {
            patient *current = my_clinic->ListHead;
            while(current != NULL)
            {
                if(current->next == NewPatient)
                {
                    break;
                }
                current=current->next;
            }
            current->next = NewPatient->next;
            NewPatient->next = NULL ;
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

void admin_EditPatient(clinic *my_clinic,FILE *my_file)
{
	s32 Id;
	printf("Enter patient id : ");
	scanf("%d",&Id);
    fprintf(my_file,"Enter patient id : %i\n",Id);
	if(Not_Exist != CheckId(my_clinic,Id))
	{
		Patient_Info(my_clinic,Id,my_file);
		patient *NewPatient = GetPatient(my_clinic,Id);
        int Selection = 0;
		while(1)
		{
            printf("Editing Patient with id (%d) :\n",NewPatient->id);
			printf("=> 1) Edit Patient Name\n");
			printf("=> 2) Edit Patient age\n");
			printf("=> 3) Edit Patient Gender\n");
			printf("=> 4) Edit Patient id\n");
			printf("=> 0) stop Editing\n\n");

            fprintf(my_file,"Editing Patient with id (%d) :\n",NewPatient->id);
			fprintf(my_file,"=> 1) Edit Patient Name\n");
			fprintf(my_file,"=> 2) Edit Patient age\n");
			fprintf(my_file,"=> 3) Edit Patient Gender\n");
			fprintf(my_file,"=> 4) Edit Patient id\n");
			fprintf(my_file,"=> 0) stop Editing\n\n");

            printf("Selection --> ");
			scanf("%d",&Selection);
			printf("\n");
            fprintf(my_file,"Selection --> %i\n\n",Selection);
			if(1 == Selection)
			{
                fflush(stdin); // Clear the Buffer to get string
                printf("Enter patient name (Not More than 40 character): ");
                gets(NewPatient->name);
                fprintf(my_file,"Enter patient name (Not More than 40 character): %s\n",NewPatient->name);
                while(NewPatient->name[0] == '\0')
                {
                    printf("\nInvalid Name !!\n\n");
                    fprintf(my_file,"\nInvalid Name !!\n\n");
                    printf("Enter patient name (Not More than 40 character): ");
                    gets(NewPatient->name);
                    fprintf(my_file,"Enter patient name (Not More than 40 character): %s\n",NewPatient->name);
                }
                NewPatient->name[Max_Name_Size-1] = '\0';
                printf("\n");
				printf("Name changed !!\n\n");
				fprintf(my_file,"\nName changed !!\n\n");
			}
			else if(2 == Selection)
			{
			    NewPatient->age = Age_Entry_validation(my_file);
                printf("\n");
				printf("Age changed !!\n\n");
				fprintf(my_file,"\nAge changed !!\n\n");
			}
			else if(3 == Selection)
			{

                NewPatient->gender = gender_Entry_validation(my_file);
				printf("Gender changed !!\n\n");
				fprintf(my_file,"Gender changed !!\n\n");
			}
			else if(4 == Selection)
			{
				int ID;
				printf("Enter patient id : ");
				scanf("%d",&ID);
				fprintf(my_file,"Enter patient id : %i\n",ID);
				if(CheckId(my_clinic,ID) == Not_Exist)
				{
					NewPatient->id=ID;
                    printf("\n");
					printf("Id changed !!\n\n");
					fprintf(my_file,"\nId changed !!\n\n");
				}
				else
                {
					printf("This id is already exists ,reject entry !!\n\n");
					fprintf(my_file,"This id is already exists ,reject entry !!\n\n");
                }
			}
			else if (0 == Selection)
            {
				break;
            }
            else
            {
                printf("Invalid Selection !!\n\n");
                fprintf(my_file,"Invalid Selection !!\n\n");
            }

            Selection = 0;
		}
	}
	else
    {
		printf("This id dosn't exist ,reject entry !!\n\n");
		fprintf(my_file,"This id dosn't exist ,reject entry !!\n\n");
    }
}

void admin_ReserveSlot(clinic *my_clinic,FILE *my_file)
{
    int Id,Slot;
    printf("Enter patient id : ");
    scanf("%d",&Id);
    fprintf(my_file,"Enter patient id : %i\n",Id);
    if(Not_Exist != CheckId(my_clinic,Id))
    {
        patient *NewPatient = GetPatient(my_clinic,Id);
        if(Not_Exist == NewPatient->slot)
        {
            if(slots[0]!=Available && slots[1]!=Available &&
               slots[2]!=Available && slots[3]!=Available && slots[4]!=Available)
            {
                printf("There is no empty slot !!\n\n");
                fprintf(my_file,"There is no empty slot !!\n\n");
            }
            else
            {
                printf("\nAvailable slots :\n");
                fprintf(my_file,"\nAvailable slots :\n");
                if(slots[0] == Available)
                {
                    printf("=> 1) from 2pm to 2:30pm\n");
                    fprintf(my_file,"=> 1) from 2pm to 2:30pm\n");
                }
                if(slots[1] == Available)
                {
                    printf("=> 2) from 2:30pm to 3pm\n");
                    fprintf(my_file,"=> 2) from 2:30pm to 3pm\n");
                }
                if(slots[2] == Available)
                {
                    printf("=> 3) from 3pm to 3:30pm\n");
                    fprintf(my_file,"=> 3) from 3pm to 3:30pm\n");
                }
                if(slots[3] == Available)
                {
                    printf("=> 4) from 4pm to 4:30pm\n");
                    fprintf(my_file,"=> 4) from 4pm to 4:30pm\n");
                }
                if(slots[4]==Available)
                {
                    printf("=> 5) from 4:30pm to 5pm\n");
                    fprintf(my_file,"=> 5) from 4:30pm to 5pm\n");
                }

                SLOT :
                printf("\n");
                printf("Selection --> ");
                scanf("%d",&Slot);
                printf("\n");
                fprintf(my_file,"Selection --> %i\n\n",Slot);
                if(Slot>0 && Slot<6)
                {
                    if(slots[Slot-1] == Available)
                    {
                        NewPatient->slot=Slot;
                        slots[Slot-1]++;
                        printf("Slot Reserved !!\n\n");
                        fprintf(my_file,"Slot Reserved !!\n\n");
                    }
                    else
                    {
                        printf("Not available slot !!\n");
                        fprintf(my_file,"Not available slot !!\n");
                        goto SLOT;
                    }
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

void admin_CancelReservation(clinic *my_clinic,FILE *my_file)
{
	int Id;
	printf("Enter patient id : ");
	scanf("%d",&Id);
	fprintf(my_file,"Enter patient id : %d\n",Id);
	if(Not_Exist != CheckId(my_clinic,Id))
	{
        patient *NewPatient=GetPatient(my_clinic,Id);
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

void admin_Display_PatientList(clinic *my_clinic,FILE *my_file)
{
    if(my_clinic->ListHead)
    {
        patient *current = my_clinic->ListHead;
        int patient_number = 0 ;
        while(current)
        {
            patient_number++;
            printf("Patient (%i)\n",patient_number);
            printf("Id : %i\n",current->id);
			printf("Name : %s\n",current->name);
			printf("Age : %d\n",current->age);

            fprintf(my_file,"Patient (%i)\n",patient_number);
            fprintf(my_file,"Id : %i\n",current->id);
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

            current = current->next;
        }
    }
    else
    {
        printf("There are no patients, Clinic is empty !!\n\n");
        fprintf(my_file,"There are no patients !!\n\n");
    }
}

void admin_ViewTodayReservations(clinic *my_clinic,FILE *my_file)
{
	patient *current = my_clinic->ListHead;
	if(my_clinic->ListHead == NULL)
    {
		printf("There are no reservations today!!\n");
		fprintf(my_file,"There are no reservations today!!\n");
    }
	else if(slots[0]==Available && slots[1]==Available &&
         slots[2]==Available && slots[3]==Available && slots[4]==Available)
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

void user_ViewPatientRecord(clinic *my_clinic,FILE *my_file)
{
	int Id;
	printf("Enter patient id : ");
	scanf("%d",&Id);
	fprintf(my_file,"Enter patient id : %i\n",Id);
	if(Not_Exist != CheckId(my_clinic,Id))
		Patient_Info(my_clinic,Id,my_file);
	else
    {
		printf("This id dosn't exist ,reject entry !!\n\n");
		fprintf(my_file,"This id dosn't exist ,reject entry !!\n\n");
    }
}

void user_ViewAvailableSlots(clinic *my_clinic,FILE *my_file)
{
	if(slots[0]!=Available && slots[1]!=Available &&
       slots[2]!=Available && slots[3]!=Available &&
       slots[4]!=Available)
    {
        printf("There is no empty slot !!\n\n");
        fprintf(my_file,"There is no empty slot !!\n\n");
    }
    else
    {
        printf("\nAll available slots are :\n");
        fprintf(my_file,"\nAll available slots are :\n");

        if(slots[0] == Available)
        {
            printf("-from 2pm to 2:30pm\n");
            fprintf(my_file,"-from 2pm to 2:30pm\n");
        }
        else{/*Nothing*/}

        if(slots[1] == Available)
        {
            printf("-from 2:30pm to 3pm\n");
            fprintf(my_file,"-from 2:30pm to 3pm\n");
        }
        else{/*Nothing*/}

        if(slots[2] == Available)
        {
            printf("-from 3pm to 3:30pm\n");
            fprintf(my_file,"-from 3pm to 3:30pm\n");
        }
        else{/*Nothing*/}

        if(slots[3] == Available)
        {
            printf("-from 4pm to 4:30pm\n");
            fprintf(my_file,"-from 4pm to 4:30pm\n");
        }
        else{/*Nothing*/}

        if(slots[4]==Available)
        {
            printf("-from 4:30pm to 5pm\n");
            fprintf(my_file,"-from 4:30pm to 5pm\n");
        }
        else{/*Nothing*/}
        printf("\n");
    }
}

void DestroyAllData(clinic *my_clinic)
{
    patient *current = my_clinic->ListHead;
    while(current)
    {
        //current = my_clinic->ListHead;
        char l_index = 0;
        for(l_index = 0 ; l_index < Max_Name_Size ; l_index++)
        {
            current->name[l_index] = 0;
        }
        current->id = 0;
        current->age = 0;
        current->slot = 0;
        current->gender = 0;
        current= current->next;
        free(my_clinic->ListHead);
        my_clinic->ListHead = current;
        if(!my_clinic->ListHead)
        {
            my_clinic->ListTail = NULL;
        }
    }
}

static int CheckId(clinic *my_clinic,int num)
{
	patient *current = my_clinic->ListHead;
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

static patient* GetPatient(clinic *my_clinic,int num)
{
	patient *current = my_clinic->ListHead;
	while(1)
	{
		if(current->id == num)
			return current;
		current=current->next;
	}
}

static void Patient_Info(clinic *my_clinic,int num,FILE *my_file)
{
	patient *current = my_clinic->ListHead;
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

static s32 Age_Entry_validation(FILE *my_file)
{
    s32 age = 0 ;

    Age:

    fflush(stdin);
    printf("Enter patient age from (1 to 80): ");
    scanf("%d",&age);
    fprintf(my_file,"Enter patient age from (1 to 80): %i\n",age);
    if(age < 1 || age > 80)
    {
        printf("\nUnaccepted age !!\n\n");
        fprintf(my_file,"\nUnaccepted age !!\n\n");
        goto Age;
    }
    else
    {/* Nothing */}
    return age;

}

static u8 gender_Entry_validation(FILE *my_file)
{
    u8 gender = 0 ;

    Gender:

    fflush(stdin);
    printf("Enter patient gender (m) for male , (f) for female: ");
    scanf("%c",&gender);
    printf("\n");
    fprintf(my_file,"Enter patient gender (m) for male , (f) for female: %c\n\n",gender);
    if(gender != 'm' && gender != 'f')
    {
        printf("Unaccepted gender !!\n\n");
        fprintf(my_file,"Unaccepted gender !!\n\n");
        goto Gender;
    }
    else
    {/* Nothing */}
    return gender;
}

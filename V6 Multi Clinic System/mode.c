/**
  ***********************************************************************************************
  * @file           : mode.c                                                                    *
  * @author         : Omar Shrif Mohamed                                                        *
  * @details        : Contains the system modes provided                                        *
  * @date           : 15/12/2023                                                                *
  ***********************************************************************************************
  */

/** ************************* Includes Section Start **************************************** **/

#include "mode.h"

/** ************************* Includes Section End ****************************************** **/

void adminMode(clinic *my_clinic,FILE *my_file)
{
	u8 trail = 0;
	u16 password;
	do
	{
		printf("Please enter password : ");
        fprintf(my_file,"Please enter password : ");

		scanf("%d",&password);
        fprintf(my_file,"%i\n\n",password);
        printf("\n");
		if(password != default_password)
        {
			trail++;
			if(trail<3)
			{
				printf("Incorrect password try again !!\n");
				printf("You still have %d trail\n\n",3-trail);

				fprintf(my_file,"Incorrect password try again !!\n");
				fprintf(my_file,"You still have %d trail\n\n",3-trail);
			}
			else
            {
				printf("Your trails are over, you will return to the main page\n\n");
				fprintf(my_file,"Your trails are over, you will return to the main page\n\n");
            }
        }
		else
		{
			break;
		}
	}while(trail<3);

	if(trail<3)
	{
        printf("..........Welcome to Admin Mode..........\n\n");
        fprintf(my_file,"..........Welcome to Admin Mode..........\n\n");
		while(1)
		{
            u8 Selection = 0;
            if(NULL == my_clinic->ListHead)
            {
                printf("Choose Operation :\n");
                printf("=> 1) Add Patient\n");
                printf("=> 0) Quit from Admin Mode\n\n");

                fprintf(my_file,"Choose Operation :\n");
                fprintf(my_file,"=> 1) Add Patient\n");
                fprintf(my_file,"=> 0) Quit from Admin Mode\n\n");


                printf("Selection --> ");
                scanf("%d",&Selection);
                printf("\n");
                fprintf(my_file,"Selection --> %i\n\n",Selection);

                if(1 == Selection)
                {
                    admin_AddPatient(my_clinic,my_file);
                }
                else if(0 == Selection)
                {
                    break;
                }
                else
                {
                    printf("Invalid Selection !!\n\n");
                    fprintf(my_file,"Invalid Selection !!\n\n");
                }
            }
            else
            {
                printf("Choose Operation :\n");
                printf("=> 1) Display Patient List\n");
                printf("=> 2) Add Patient\n");
                printf("=> 3) Remove Patient\n");
                printf("=> 4) Edit Patient informations\n");
                printf("=> 5) Reserve Slot for patient\n");
                printf("=> 6) Cancel Reservation\n");
                printf("=> 0) Quit from Admin Mode\n\n");

                fprintf(my_file,"=> 1) Display Patient List\n");
                fprintf(my_file,"=> 2) Add Patient\n");
                fprintf(my_file,"=> 3) Remove Patient\n");
                fprintf(my_file,"=> 4) Edit Patient informations\n");
                fprintf(my_file,"=> 5) Reserve Slot for patient\n");
                fprintf(my_file,"=> 6) Cancel Reservation\n");
                fprintf(my_file,"=> 0) Quit from Admin Mode\n\n");

                printf("Selection --> ");
                scanf("%d",&Selection);
                printf("\n");
                fprintf(my_file,"Selection --> %i\n\n",Selection);
                if(1 == Selection)
                {
                    admin_Display_PatientList(my_clinic,my_file);
                }
                else if(2 == Selection)
                {
                    admin_AddPatient(my_clinic,my_file);
                }
                else if(3 == Selection)
                {
                    admin_RemovePatient(my_clinic,my_file);
                }
                else if(4 == Selection)
                {
                    admin_EditPatient(my_clinic,my_file);
                }
                else if(5 == Selection)
                {
                    admin_ReserveSlot(my_clinic,my_file);
                }
                else if(6 == Selection)
                {
                    admin_CancelReservation(my_clinic,my_file);
                }
                else if(0 == Selection)
                {
                    break;
                }
                else
                {
                    printf("Invalid Selection !!\n\n");
                    fprintf(my_file,"Invalid Selection !!\n\n");
                }
            }
		}
	}
}
void userMode(clinic *my_clinic,FILE *my_file)
{
	printf("..........Welcome to User Mode..........\n\n");
	fprintf(my_file,"..........Welcome to User Mode..........\n\n");
	while(1)
	{
		int Selection = 0;
        if(NULL == my_clinic->ListHead)
        {
            u8 counter = 0;
            printf("There is no patients today !! \n");
            printf("We will return to the main page ");
            fprintf(my_file,"There is no patients today !! \n");
            fprintf(my_file,"We will return to the main page ");
            for(counter = 0 ; counter < 20 ; counter++)
            {
                printf(".");
                fprintf(my_file,".");
                Sleep(200);
            }
            printf("\n\n");
            fprintf(my_file,"\n\n");

            break;
        }
        else
        {
            printf("Choose Operation :\n");
            printf("=> 1) View Patient Record\n");
            printf("=> 2) View Today Reservations\n");
            printf("=> 0) Quit from User Mode\n\n");

            fprintf(my_file,"=> 1) View Patient Record\n");
            fprintf(my_file,"=> 2) View Today Reservations\n");
            fprintf(my_file,"=> 0) Quit from User Mode\n\n");

            printf("Selection --> ");
            scanf("%d",&Selection);
            printf("\n");
            fprintf(my_file,"Selection --> %i\n\n",Selection);
            if(1 == Selection)
            {
                user_ViewPatientRecord(my_clinic,my_file);
            }
            else if(2 == Selection)
            {
                user_ViewTodayReservations(my_clinic,my_file);
            }
            else if(0 == Selection)
            {
                break;
            }
            else
            {
                printf("Invalid Selection !!\n\n");
                fprintf(my_file,"Invalid Selection !!\n\n");
            }
        }
	}
}

void ClearTheClinic(clinic *my_clinic)
{
    DestroyAllData(my_clinic);
}

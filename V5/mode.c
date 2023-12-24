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

void adminMode(FILE *my_file)
{
	printf("..........Welcome to Admin Mode..........\n");
	fprintf(my_file,"..........Welcome to Admin Mode..........\n");
	int password,trail=0;
	do
	{
		printf("\nPlease enter password : ");
        fprintf(my_file,"\nPlease enter password : ");

		scanf("%d",&password);
        fprintf(my_file,"%i\n\n",password);
        printf("\n");
		if(password == default_password)
			break;
		else
		{
			trail++;
			if(trail<3)
			{
				printf("Incorrect password try again !!\n");
				printf("You still have %d trail\n",3-trail);

				fprintf(my_file,"Incorrect password try again !!\n");
				fprintf(my_file,"You still have %d trail\n",3-trail);
			}
			else
            {
				printf("Your trails are over, you will return to the main page\n\n");
				fprintf(my_file,"Your trails are over, you will return to the main page\n\n");
            }
		}
	}while(trail<3);

	if(trail<3)
	{
		int Selection;
		while(1)
		{
            if(NULL == head)
            {
                printf("To Add Patient                  Choose --> 1\n");
                printf("To exit from Admin Mode         Choose --> 0 or any input\n\n");

                fprintf(my_file,"To Add Patient                  Choose --> 1\n");
                fprintf(my_file,"To exit from Admin Mode         Choose --> 0 or any input\n\n");

                printf("Selection --> ");
                scanf("%d",&Selection);
                printf("\n");
                fprintf(my_file,"Selection --> %i\n\n",Selection);
                if(1 == Selection)
                    admin_AddPatient(my_file);
                else
                    break;
            }
            else
            {
                printf("To Display Patient List         Choose --> 1\n");
                printf("To Add Patient                  Choose --> 2\n");
                printf("To Remove Patient               Choose --> 3\n");
                printf("To Edit Patient informations    Choose --> 4\n");
                printf("To Reserve Slot for patient     Choose --> 5\n");
                printf("To Cancel Reservation           Choose --> 6\n");
                printf("To exit from Admin Mode         Choose --> 0 or any input\n\n");

                fprintf(my_file,"To Display Patient List         Choose --> 1\n");
                fprintf(my_file,"To Add Patient                  Choose --> 2\n");
                fprintf(my_file,"To Remove Patient               Choose --> 3\n");
                fprintf(my_file,"To Edit Patient informations    Choose --> 4\n");
                fprintf(my_file,"To Reserve Slot for patient     Choose --> 5\n");
                fprintf(my_file,"To Cancel Reservation           Choose --> 6\n");
                fprintf(my_file,"To exit from Admin Mode         Choose --> 0 or any input\n\n");

                printf("Selection --> ");
                scanf("%d",&Selection);
                printf("\n");
                fprintf(my_file,"Selection --> %i\n\n",Selection);
                if(Selection == 1)
                {
                    admin_Display_PatientList(my_file);
                }
                else if(Selection == 2)
                {
                    admin_AddPatient(my_file);
                }
                else if(Selection == 3)
                {
                    admin_RemovePatient(my_file);
                }
                else if(Selection == 4)
                {
                    admin_EditPatient(my_file);
                }
                else if(Selection == 5)
                {
                    admin_ReserveSlot(my_file);
                }
                else if(Selection == 6)
                {
                    admin_CancelReservation(my_file);
                }
                else
                {
                    break;
                }
            }
		}
	}
}
void userMode(FILE *my_file)
{
	printf("..........Welcome to User Mode..........\n\n");
	fprintf(my_file,"..........Welcome to User Mode..........\n\n");
	int Selection;
	while(1)
	{
        if(NULL == head)
        {
            char i = 0;
            printf("There is no patients today !! \n");
            printf("We will return to the main page ");
            fprintf(my_file,"There is no patients today !! \n");
            fprintf(my_file,"We will return to the main page ");
            for(i = 0 ; i<20 ; i++)
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
            printf("To View Patient Record             Choose --> 1\n");
            printf("To View Today Reservations         Choose --> 2\n");
            printf("To exit from User Mode             Choose --> 0 or any input\n");

            fprintf(my_file,"To View Patient Record             Choose --> 1\n");
            fprintf(my_file,"To View Today Reservations         Choose --> 2\n");
            fprintf(my_file,"To exit from User Mode             Choose --> 0 or any input\n");

            scanf("%d",&Selection);
            fprintf(my_file,"\nSelection --> %i\n\n",Selection);
            if(Selection == 1)
                user_ViewPatientRecord(my_file);
            else if(Selection == 2)
                user_ViewTodayReservations(my_file);
            else
                break;
        }
	}
}

void ClearTheClinic(void)
{
    DestroyAllData();
}

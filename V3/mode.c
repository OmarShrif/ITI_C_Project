#include<stdio.h>
#include<stdlib.h>
#include <windows.h>

#include"ClinicList.h"
#include "mode.h"

void adminMode()
{
	printf("..........Welcome to Admin Mode..........\n");
	int password,trail=0;
	do
	{
        printf("\n");
		printf("Please enter password : ");
		scanf("%d",&password);
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
			}
			else
				printf("Your trails are over, you will return to the main page\n\n");
		}
	}while(trail<3);

	if(trail<3)
	{
		int selected;
		while(1)
		{
            if(NULL == head)
            {
                printf("To Add Patient                  Choose --> 1\n");
                printf("To exit from Admin Mode         Choose --> 0 or any input\n");
                scanf("%d",&selected);
                if(1 == selected)
                    AddPatient();
                else
                    break;
            }
            else
            {
                printf("To Add Patient                  Choose --> 1\n");
                printf("To Remove Patient               Choose --> 2\n");
                printf("To Edit Patient informations    Choose --> 3\n");
                printf("To Reserve Slot for patient     Choose --> 4\n");
                printf("To Cancel Reservation           Choose --> 5\n");
                printf("To exit from Admin Mode         Choose --> 0 or any input\n");
                scanf("%d",&selected);
                if(selected == 1)
                    AddPatient();
                else if(selected == 2)
                    RemovePatient();
                else if(selected == 3)
                    EditPatient();
                else if(selected == 4)
                    ReserveSlot();
                else if(selected == 5)
                    CancelReservation();
                else
                    break;
            }
		}
	}
}
void userMode()
{
	printf("..........Welcome to User Mode..........\n\n");
	int selected;
	while(1)
	{
        if(NULL == head)
        {
            char i = 0;
            printf("There is no patients today !! \n");
            printf("We will return to the main page ");
            for(i = 0 ; i<20 ; i++)
            {
                printf(".");
                Sleep(200);
            }
            printf("\n\n");

            break;
        }
        else
        {
            printf("To View Patient Record             Choose --> 1\n");
            printf("To View Today Reservations         Choose --> 2\n");
            printf("To exit from User Mode             Choose --> 0 or any input\n");
            scanf("%d",&selected);
            if(selected == 1)
                ViewPatientRecord();
            else if(selected == 2)
                ViewTodayReservations();
            else
                break;
        }
	}
}

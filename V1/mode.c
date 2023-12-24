#include "mode.h"

void adminMode()
{
	printf("..........Welcome to Admin Mode..........\n");
	int password,trail=0;
	do
	{
		printf("Please enter password : ");
		scanf("%d",&password);
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
			printf("To Add Patient                  Choose --> 1\n");
			printf("To Edit Patient informations    Choose --> 2\n");
			printf("To Reserve Slot for patient     Choose --> 3\n");
			printf("To Cancel Reservation           Choose --> 4\n");
			printf("To exit from Admin Mode         Choose --> 0 or any input\n");
			scanf("%d",&selected);
			if(selected == 1)
				AddPatient();
			else if(selected == 2)
				EditPatient();
			else if(selected == 3)
				ReserveSlot();
			else if(selected == 4)
				CancelReservation();
			else
				break;
		}
	}
}
void userMode()
{
	printf("..........Welcome to User Mode..........\n");
	int selected;
	while(1)
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
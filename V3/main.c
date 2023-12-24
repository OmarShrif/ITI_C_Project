#include<stdio.h>
#include<stdlib.h>

#include "mode.h"

int main()
{
	printf("..........Welcome to Clinic Management System..........\n");
	int selected;
	while(1)
	{
		printf("Choose Mode :\n");
		printf("For Admin-Mode                  Choose --> 1\n");
		printf("For User-Mode                   Choose --> 2\n");
		printf("To exit from the system        Choose --> 0 or any input\n");
		scanf("%d",&selected);
		if(selected == 1)
			adminMode();
		else if(selected == 2)
			userMode();
		else
			exit (0);
	}
	return 0 ;
}

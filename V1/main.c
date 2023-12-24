#include "mode.h"

void main()
{
	printf("..........Welcome to Clinic Management System..........\n");
	int selected;
	while(1)
	{
		printf("Choose Mode :\n");
		printf("For adminMode                  Choose --> 1\n");
		printf("For userMode                   Choose --> 2\n");
		printf("To exit from the system        Choose --> 0 or any input\n");
		scanf("%d",&selected);
		if(selected == 1)
			adminMode();
		else if(selected == 2)
			userMode();
		else
			exit (0);
	}
}
/**
  ***********************************************************************************************
  * @file           : main.c                                                                    *
  * @author         : Omar Shrif Mohamed                                                        *
  * @details        : Contains the functionality of my application                              *
  * @date           : 15/12/2023                                                                *
  ***********************************************************************************************
  */

/** ************************* Includes Section Start **************************************** **/

#include "mode.h"

/** ************************* Includes Section End ****************************************** **/

//----------------------------------------------------------------------------------------------

/** ************************* Global Variables Section Start ******************************** **/

FILE *my_file = NULL;

/** ************************* Global Variables Section End ********************************** **/

int main()
{
    my_file = fopen("Run_Time_History.txt","w");
    if(my_file)
    {
        printf("..........Welcome to Clinic Management System..........\n");
        fprintf(my_file,"..........Welcome to Clinic Management System..........\n");

        int Selection;
        while(1)
        {
            printf("Choose Mode :\n");
            printf("For Admin-Mode                  Choose --> 1\n");
            printf("For User-Mode                   Choose --> 2\n");
            printf("To exit from the system        Choose --> 0 or any input\n");

            fprintf(my_file,"Choose Mode :\n");
            fprintf(my_file,"For Admin-Mode                  Choose --> 1\n");
            fprintf(my_file,"For User-Mode                   Choose --> 2\n");
            fprintf(my_file,"To exit from the system        Choose --> 0 or any input\n\n");

            scanf("%d",&Selection);

            fprintf(my_file,"Selection --> %i\n\n",Selection);

            if(Selection == 1)
                adminMode(my_file);
            else if(Selection == 2)
                userMode(my_file);
            else
                exit (0);
        }
    }
    else
    {
        printf("Error, Can't Write in the file !!\n");
    }
	return 0 ;
}

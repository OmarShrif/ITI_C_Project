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
clinic Clinic1 = {NULL,NULL};

/** ************************* Global Variables Section End ********************************** **/

int main()
{
    my_file = fopen("Run_Time_History.txt","w");
    if(my_file)
    {
        printf("..........Welcome to Clinic Management System..........\n\n");
        fprintf(my_file,"..........Welcome to Clinic Management System..........\n\n");

        while(1)
        {
            u8 Selection = 0;
            printf("Choose Mode :\n");
            printf("=> 1) Admin-Mode\n");
            printf("=> 2) User-Mode\n");
            printf("=> 0) Quit the system\n\n");

            fprintf(my_file,"Choose Mode :\n");
            fprintf(my_file,"=> 1) Admin-Mode\n");
            fprintf(my_file,"=> 2) User-Mode\n");
            fprintf(my_file,"=> 0) Quit the system\n\n");

            printf("Selection --> ");
            scanf("%i",&Selection);
            printf("\n");

            fprintf(my_file,"Selection --> %i\n\n",Selection);

            switch (Selection)
            {
            case 1 :
                adminMode(&Clinic1,my_file);
                break;
            case 2 :
                userMode(&Clinic1,my_file);
                break;
            case 0 :
                ClearTheClinic(&Clinic1);
                printf("System Quit !!\n");
                fprintf(my_file,"System Quit !!\n");
                exit (0);
                break;
            default :
                printf("Invalid Selection !!\n\n");
                fprintf(my_file,"Invalid Selection !!\n\n");
                break;
            }
        }
    }
    else
    {
        printf("Error, Can't Write in the file !!\n");
    }
	return 0 ;
}

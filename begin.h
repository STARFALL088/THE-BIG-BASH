
#include "function.h"

void begin()
{
    int choice;

    do
    {
        if(end_of_match==1)break;
        puts(WHITE "\n1. LOGIN" RESET);
        puts(WHITE "2. SIGNUP" RESET);
        puts(WHITE "3. MANAGE TEAM" RESET);
        puts(WHITE "4. SIMULATE MATCH" RESET);
        puts(WHITE "5. EXIT\n\n" RESET);
        printf(WHITE"ENTER YOUR CHOICE: "RESET);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Login
            if (login(user_Count, &logged_In_Team_Index))
            {
                printf(WHITE"\nLOGIN SUCCESSFUL :)\nYOU ARE MANAGING %s.\n"RESET, teams[logged_In_Team_Index].name);
            }
            else
            {
                printf(WHITE"\nLOGIN FAILED. INVALID PROCESS :(\n"RESET);
            }
            break;
        case 2: // Signup
            if (signup(&user_Count))
            {
                save_Users_to_File(user_Count);
                printf(WHITE"\nSIGNUP SUCCESSFUL :)\nYOU CAN NOW LOGIN.\n"RESET);
            }
            else
            {
                printf(WHITE"\nSIGNUP FAILED. USERNAME MAY ALREADY EXIST OR PASSWORD IS WEAK :(\n"RESET);
            }
            break;
        case 3: // Manage Team
            if (logged_In_Team_Index != -1)
            {
                manageTeam(&teams[logged_In_Team_Index]);
                saveTeamToFile(&teams[logged_In_Team_Index], logged_In_Team_Index == 0 ? "team1.txt" : "team2.txt");
            }
            else
            {
                printf(WHITE"\nPLEASE LOGIN FIRST\n"RESET);
            }
            break;
        case 4: // Simulate Match

            option();
            if(end_of_match==1)break;
            break;
        case 5: // Exit
            printf(WHITE"\nEXITING FROM THE CODE.. :)\n"RESET);
            break;
        default:
            printf(WHITE"\nINVALID CHOICE. TRY AGAIN.\n"RESET);
        }
    } while (choice != 5);
}
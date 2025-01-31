#include "function.h"

void option()
{
    if (logged_In_Team_Index != -1)
    {
        if (first_team_batting)
            simulate_Match(teams);
        // puts("ok");
        int subChoice;
        do
        {
            if(end_of_match==1)break;
            puts("");
            puts(WHITE"\n1. VIEW NEXT BALL"RESET);
            puts(WHITE"2. VIEW CURRENT STATUS"RESET);
            puts(WHITE"3. SAVE MATCH STATS"RESET);
            puts(WHITE"4. BACK\n"RESET);
            printf(WHITE"ENTER YOUR CHOICE: "RESET);

            scanf("%d", &subChoice);

            switch (subChoice)
            {
            case 1:
                view_Next_Ball(teams, "team1_stats.txt", "team2_stats.txt");
                if(end_of_match==1)break;
                
                break;
            case 2:
                view_Current_Status(teams);
                break;
            case 3:
                save_Match_Stats_To_File(&teams[logged_In_Team_Index], logged_In_Team_Index == 0 ? "team1_stats.txt" : "team2_stats.txt");
                printf(WHITE"MATCH STATS SAVED TO FILE\n"RESET);
                break;
            case 4:

                simulate_Match(teams);
                break;
            default:
                printf(WHITE"INVALID CHOICE. TRY AGAIN :(\n"RESET);
            }
        } while (subChoice != 4);
    }
    else
    {
        printf(WHITE"PLEASE LOGIN FIRST\n"RESET);
    }

}
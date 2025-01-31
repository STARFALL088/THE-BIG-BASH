#include "function.h"

void view_Current_Status(Team teams[])
{
    if (logged_In_Team_Index == -1)
    {
        printf("PLEASE LOGIN FIRST\n");
        return;
    }

    int subChoice1;
    do
    {
        printf("\n\t\t\t___ CURRENT MATCH STATUS ___\n");
        if (end_of_match == 0)
            printf("1. DISPLAY SCOREBOARD\n");
        else
            printf("1. DISPLAY MAN OF THE MATCH\n");
        printf("2. DISPLAY TEAM1 STATS\n");
        printf("3. DISPLAY TEAM2 STATS\n");
        if (end_of_match == 0)
            printf("4. BACK\n");
        else
            printf("4.EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &subChoice1);

        switch (subChoice1)
        {
        case 1: // Display Scoreboard
            if (end_of_match == 0)
            {
                printf("\n\t\t\t___ SCOREBOARD ___\n");
                printf("BATSMANS:\n");
                printf("NAME\tRUNS\tBALLS\tFOURS\tSIXES\tSR\n\n");
                for (int i = 0; i < teams[currently_batting].batsman_Count; i++)
                {
                    printf("%s\t%d\t%d\t%d\t%d\t%.2f\n",
                           teams[currently_batting].batsmen[i].name,
                           teams[currently_batting].batsmen[i].runs,
                           teams[currently_batting].batsmen[i].balls,
                           teams[currently_batting].batsmen[i].fours,
                           teams[currently_batting].batsmen[i].sixes,
                           teams[currently_batting].batsmen[i].strike_rate);
                }
                printf("BOWLERS:\n");
                printf("NAME\tOVERS\tRUNS\tWICKETS\tECONOMY\n\n");
                for (int i = 0; i < teams[currently_batting].bowler_Count; i++)
                {
                    printf("%s\t%.1f\t%d\t%d\t%.2f\n\n",
                           teams[1 - currently_batting].bowlers[i].name,
                           teams[1 - currently_batting].bowlers[i].overs,
                           teams[1 - currently_batting].bowlers[i].runs_conceded,
                           teams[1 - currently_batting].bowlers[i].wickets,
                           teams[1 - currently_batting].bowlers[i].economy);
                }
            }
            else
                ManOfTheMatch(teams);
            break;

        case 2: // Display Team1 Stats
            printf("\n\t\t\t___ OEH STATS ___\n");
            displayBattingView(&teams[0]);
            displayBowlingView(&teams[0]);
            break;
        case 3: // Display Team2 Stats
            printf("\n\t\t\t___ LSH STATS ___\n");
            displayBattingView(&teams[1]);
            displayBowlingView(&teams[1]);
            break;
        case 4: // Back
            break;
        default:
            printf("INVALID CHOICE.TRY AGAIN :(\n");
        }
    } while (subChoice1 != 4);
}

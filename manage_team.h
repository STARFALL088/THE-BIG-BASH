#include "function.h"

void manageTeam(Team *team)
{
    int choice;
    do
    {
        printf(WHITE "\nIN PROGRESS %s\n" RESET, team->name);
        printf(WHITE "1. ADD BATSMAN\n2. ADD BOWLER\n3. VIEW SQUAD\n4. REMOVE BATSMAN\n5. REMOVE BOWLER\n6.BACK\n\nENTER YOUR CHOICE: " RESET);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Add Batsman
            if (team->batsman_Count < MAX_PLAYERS)
            {
                printf(WHITE "ENTER BATSMAN NAME: " RESET);
                scanf("%s", team->batsmen[team->batsman_Count].name);
                team->batsmen[team->batsman_Count].runs = 0;
                team->batsmen[team->batsman_Count].balls = 0;
                team->batsmen[team->batsman_Count].sixes = 0;
                team->batsmen[team->batsman_Count].fours = 0;
                team->batsmen[team->batsman_Count].is_out = 0;
                team->batsmen[team->batsman_Count].strike_rate = 0.0;
                team->batsman_Count++;
                printf(WHITE "BATSMAN ADDED SUCCESSFULLY :)\n" RESET);
            }
            else
            {
                printf(WHITE "TEAM IS FULL. CANNOT ADD MORE BATSMAN :(\n" RESET);
            }
            break;
        //case 2: // Add Bowler
        case 2: // Add Bowler
            if (team->bowler_Count < MAX_PLAYERS)
            {
                char new_player[20];
                printf(WHITE "ENTER BOWLER NAME: " RESET);
                scanf("%s", new_player);

                // Check if player already exists as batsman
                int exists_as_batsman = 0;
                for (int i = 0; i < team->batsman_Count; i++)
                {
                    if (strcmp(team->batsmen[i].name, new_player) == 0)
                    {
                        exists_as_batsman = 1;
                        break;
                    }
                }

                // Check if already exists as bowler
                int exists_as_bowler = 0;
                for (int i = 0; i < team->bowler_Count; i++)
                {
                    if (strcmp(team->bowlers[i].name, new_player) == 0)
                    {
                        exists_as_bowler = 1;
                        printf(WHITE "BOWLER ALREADY EXISTS IN THE TEAM :(\n" RESET);
                        break;
                    }
                }

                if (!exists_as_bowler)
                {
                    // Add as bowler
                    strcpy(team->bowlers[team->bowler_Count].name, new_player);
                    team->bowlers[team->bowler_Count].overs = 0.0;
                    team->bowlers[team->bowler_Count].runs_conceded = 0;
                    team->bowlers[team->bowler_Count].wickets = 0;
                    team->bowlers[team->bowler_Count].economy = 0.0;
                    team->bowler_Count++;

                    // If player doesn't exist as batsman, add them as batsman too
                    if (!exists_as_batsman)
                    {
                        if (team->batsman_Count < MAX_PLAYERS)
                        {
                            strcpy(team->batsmen[team->batsman_Count].name, new_player);
                            team->batsmen[team->batsman_Count].runs = 0;
                            team->batsmen[team->batsman_Count].balls = 0;
                            team->batsmen[team->batsman_Count].sixes = 0;
                            team->batsmen[team->batsman_Count].fours = 0;
                            team->batsmen[team->batsman_Count].is_out = 0;
                            team->batsmen[team->batsman_Count].strike_rate = 0.0;
                            team->batsman_Count++;
                            printf(WHITE "PLAYER ADDED AS BOTH BOWLER AND BATSMAN SUCCESSFULLY :)\n" RESET);
                        }
                        else
                        {
                            // If can't add as batsman, remove the bowler that was just added
                            team->bowler_Count--;
                            printf(WHITE "CANNOT ADD PLAYER - BATSMAN LIMIT REACHED\n" RESET);
                        }
                    }
                    else
                    {
                        printf(WHITE "PLAYER ADDED AS BOWLER SUCCESSFULLY (ALREADY EXISTS AS BATSMAN) :)\n" RESET);
                    }
                }
            }
            else
            {
                printf(WHITE "TEAM IS FULL. CANNOT ADD MORE BOWLERS\n" RESET);
            }

            // Check if minimum 2 bowlers requirement is met
            if (team->bowler_Count < 2)
            {
                printf(WHITE "WARNING: Team needs at least 2 bowlers. Please add more bowlers.\n" RESET);
            }
            break;
        case 3: // View Squad
            printf("\n\t\t\t___ %s SQUAD ___\n", team->name);
            printf(YELLOW "\nBATSMAN:\n" RESET);
            for (int i = 0; i < team->batsman_Count; i++)
            {
                printf("%s\n", team->batsmen[i].name);
            }
            printf(YELLOW "\n\nBOWLERS:\n" RESET);
            for (int i = 0; i < team->bowler_Count; i++)
            {
                printf("%s\n", team->bowlers[i].name);
            }
            printf(WHITE "______________\n" RESET);
            break;
        case 4: // Remove Batsman
            if (team->batsman_Count > 0)
            {
                printf(WHITE "\n\nENTER BATSMAN NAME TO REMOVE: " RESET);
                char name[20];
                scanf("%s", name);
                int found = 0;
                for (int i = 0; i < team->batsman_Count; i++)
                {
                    if (strcmp(team->batsmen[i].name, name) == 0)
                    {
                        for (int j = i; j < team->batsman_Count - 1; j++)
                        {
                            team->batsmen[j] = team->batsmen[j + 1];
                        }
                        team->batsman_Count--;
                        found = 1;
                        printf(WHITE "\n\nBATSMAN REMOVED SUCCESSFULLY :)\n" RESET);
                        break;
                    }
                }
                if (!found)
                {
                    printf(WHITE "\n\nBATSMAN NOT FOUND\n" RESET);
                }
            }
            else
            {
                printf(WHITE "\n\nNO BATSMAN TO REMOVE\n" RESET);
            }
            break;
        case 5: // Remove Bowler
            if (team->bowler_Count > 0)
            {
                printf(WHITE "\n\nENTER BOWLER TO REMOVE " RESET);
                char name[20];
                scanf("%s", name);
                int found = 0;
                for (int i = 0; i < team->bowler_Count; i++)
                {
                    if (strcmp(team->bowlers[i].name, name) == 0)
                    {
                        for (int j = i; j < team->bowler_Count - 1; j++)
                        {
                            team->bowlers[j] = team->bowlers[j + 1];
                        }
                        team->bowler_Count--;
                        found = 1;
                        printf(WHITE "\n\nBOWLER REMOVED SUCCESSFULLY\n" RESET);
                        break;
                    }
                }
                if (!found)
                {
                    printf("\n\nBOWLER NOT FOUND\n");
                }
            }
            else
            {
                printf("\n\nNO BOWLERS TO REMOVE\n");
            }
            break;
        case 6: // Back
            break;
        default:
            printf("INVALID CHOICE.TRY AGAIN :(\n");
        }
    } while (choice != 6);
}

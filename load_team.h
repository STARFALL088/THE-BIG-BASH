#include "function.h"


void loadTeamFromFile(Team *team, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return; // No team file exists yet
    }

    char type[10];
    char name[20];
    
    while (fscanf(file, "%s %s", type, name) != EOF)
    {
        if (strcmp(type, "BAT") == 0)
        {
            strcpy(team->batsmen[team->batsman_Count].name, name);
            team->batsman_Count++;
        }
        else if (strcmp(type, "BOWL") == 0)
        {
            strcpy(team->bowlers[team->bowler_Count].name, name);
            team->bowler_Count++;
        }
    }

    fclose(file);
}


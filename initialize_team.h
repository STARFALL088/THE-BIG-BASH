#include "function.h"

void initialize_Teams(Team teams[])
{
    strcpy(teams[0].name, "OMOR EKUSHEY HALL");
    strcpy(teams[1].name, "SHAHID SMRITY HALL");
    teams[0].batsman_Count = 0;
    teams[0].bowler_Count = 0;
    teams[1].batsman_Count = 0;
    teams[1].bowler_Count = 0;

    loadTeamFromFile(&teams[0], "team1.txt");
    loadTeamFromFile(&teams[1], "team2.txt");
}

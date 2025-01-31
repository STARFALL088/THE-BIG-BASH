#include "function.h"

void ManOfTheMatch(Team teams[])
{
    
    int performance_point = 0;

    // Process batsmen
    for (int t = 0; t < 2; t++)
    {
        for (int i = 0; i < teams[t].batsman_Count; i++)
        {
            strcpy(performances[performance_point].name, teams[t].batsmen[i].name);
            strcpy(performances[performance_point].team, teams[t].name);
            strcpy(performances[performance_point].role, "BATSMAN");

            // Points calculation for batsmen
            // Basic formula: runs + (strike_rate/10) + (fours*2) + (sixes*3)
            performances[performance_point].points = teams[t].batsmen[i].runs +(int)(teams[t].batsmen[i].strike_rate / 10) +(teams[t].batsmen[i].fours * 2) +(teams[t].batsmen[i].sixes * 3);
            performances[performance_point].stats.bat.runs = teams[t].batsmen[i].runs;
            performances[performance_point].stats.bat.strike_rate = teams[t].batsmen[i].strike_rate;
            performance_point++;
        }
    }
    for (int t = 0; t < 2; t++)
    {
        for (int i = 0; i < teams[t].bowler_Count; i++)
        {
            strcpy(performances[performance_point].name, teams[t].bowlers[i].name);
            strcpy(performances[performance_point].team, teams[t].name);
            strcpy(performances[performance_point].role, "BOWLER");

            // Points calculation for bowlers
            // Basic formula: (wickets*20) + (50 - economy*5)
            performances[performance_point].points = (teams[t].bowlers[i].wickets * 20) + (int)(50 - teams[t].bowlers[i].economy * 5);
            performances[performance_point].stats.bowl.wickets = teams[t].bowlers[i].wickets;
            performances[performance_point].stats.bowl.economy = teams[t].bowlers[i].economy;
            performance_point++;
        }
    }

    // Find best performance
    int best_Index = 0;
    for (int i = 1; i < performance_point; i++)
    {
        if (performances[i].points > performances[best_Index].points)
        {
            best_Index = i;
        }
    }

    // Display Man of the Match
    puts(CYAN"\n=========================================="RESET);
    puts(CYAN"               MAN OF THE MATCH                "RESET);
    puts(CYAN"=========================================="RESET);
    printf(RED"\n%s (%s FROM %s)\n"RESET,
           performances[best_Index].name,
           performances[best_Index].role,
           performances[best_Index].team);

    if (strcmp(performances[best_Index].role,"BATSMAN") == 0)
    {
        printf(RED"RUNS: %d\nSTRIKE RATE: %.2f\n"RESET,
               performances[best_Index].stats.bat.runs,
               performances[best_Index].stats.bat.strike_rate);
    }
    else
    {
        printf(RED"WICKETS: %d\nECONOMY: %.2f\n"RESET,
               performances[best_Index].stats.bowl.wickets,
               performances[best_Index].stats.bowl.economy);
    }
    

    
}


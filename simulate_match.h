#include "function.h"


void simulate_Match(Team teams[])
{
    printf("\n\t\t\t___ MATCH SIMULATION ___\n");
    printf("\t\t  %s VS %s\n", teams[0].name, teams[1].name);
    teams[currently_batting].totalRuns = 0;
    teams[1 - currently_batting].totalRuns = 0;
    teams[currently_batting].total_balls = 0;
    teams[1 - currently_batting].total_balls = 0;

    teams[currently_batting].current_rr = 0.0;
    teams[1 - currently_batting].current_rr = 0.0;

    teams[currently_batting].required_rr = 0.0;
    teams[1 - currently_batting].required_rr = 0.0;

    // Simulate batting for Team1
    printf("\n%s BATTING:\n", teams[0].name);
    for (int i = 0; i < teams[currently_batting].batsman_Count; i++)
    {
        teams[currently_batting].batsmen[i].runs = 0;
        teams[currently_batting].batsmen[i].balls = 0;
        teams[currently_batting].batsmen[i].sixes = 0;
        teams[currently_batting].batsmen[i].fours = 0;
        teams[currently_batting].batsmen[i].is_out = 0;
        teams[currently_batting].batsmen[i].strike_rate = 0.0;

        teams[1 - currently_batting].batsmen[i].runs = 0;
        teams[1 - currently_batting].batsmen[i].balls = 0;
        teams[1 - currently_batting].batsmen[i].sixes = 0;
        teams[1 - currently_batting].batsmen[i].fours = 0;
        teams[1 - currently_batting].batsmen[i].is_out = 0;
        teams[1 - currently_batting].batsmen[i].strike_rate = 0.0;
    }
    displayBattingView(&teams[currently_batting]);

    // Simulate bowling for Team2
    printf("\n%s BOWLING:\n", teams[1 - currently_batting].name);
    for (int i = 0; i < teams[1].bowler_Count; i++)
    {
        teams[currently_batting].bowlers[i].overs = 0;
        teams[currently_batting].bowlers[i].runs_conceded = 0;
        teams[currently_batting].bowlers[i].wickets = 0;
        teams[currently_batting].bowlers[i].economy = 0;

        teams[1 - currently_batting].bowlers[i].overs = 0;
        teams[1 - currently_batting].bowlers[i].runs_conceded = 0;
        teams[1 - currently_batting].bowlers[i].wickets = 0;
        teams[1 - currently_batting].bowlers[i].economy = 0;
    }
    displayBowlingView(&teams[1 - currently_batting]);

    printf("MATCH SIMULATED SUCCESSFULLY :)\n");
}

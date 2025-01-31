#include "function.h"

void view_Next_Ball(Team team[], const char *filename1, const char *filename2)
{
    printf(YELLOW "\n\t\t\t___ NEXT BALL ___\n" RESET);
    static int currentBatsmanIndex = 0; // Track the current batsman
    static int currentBowlerIndex = 0;  // Track the current bowler
    static int secondary_batsman_index = 1;

    Batsman *currentBatsman = &team[currently_batting].batsmen[currentBatsmanIndex];
    Bowler *currentBowler = &team[1 - currently_batting].bowlers[currentBowlerIndex];
    int runs = rand() % 7;         // 0-6 runs
    int isOut = (rand() % 4 == 0); // 25% chance of getting out (1 in 4)
    if (isOut)
    {
        team[currently_batting].totalWickets++;
        runs %= 3;// limiting to run out
    }

    if (runs == 1 || runs == 3)
    {
        int temp = currentBatsmanIndex;
        currentBatsmanIndex = secondary_batsman_index;
        secondary_batsman_index = temp;
        currentBatsman = &team[currently_batting].batsmen[currentBatsmanIndex];
        // currentBowler = &team[1 - currently_batting].bowlers[currentBowlerIndex];
    }

    // Update batting stats
    currentBatsman->runs += runs;
    currentBatsman->balls += (runs != 5); // 5 == no ball +4 run
    currentBatsman->fours += (runs == 4 || runs == 5);
    currentBatsman->sixes += (runs == 6);
    currentBatsman->is_out |= isOut;
    team[currently_batting].totalRuns += runs;
    team[currently_batting].total_balls += (runs != 5);
    team[currently_batting].current_rr = (team[currently_batting].totalRuns * 6.0) / team[currently_batting].total_balls;
    currentBatsman->strike_rate = (currentBatsman->runs * 100.0) / currentBatsman->balls;

    // Update bowling stats
    currentBowler->runs_conceded += runs;
    currentBowler->wickets += isOut;
    currentBowler->balls += (runs != 5); // 5 == no ball +4 run
    currentBowler->overs = currentBowler->balls / 6 + (currentBowler->balls % 6) / 10.0;
    currentBowler->economy = (currentBowler->runs_conceded * 6.0) / currentBowler->balls;

    // Calculate required run rate
    int run_needed = team[1 - currently_batting].totalRuns - team[currently_batting].totalRuns;
    int over_remaining = 6 * MAX_OVERS - team[currently_batting].total_balls;
    float rrr = (run_needed * 6.0) / over_remaining;
    team[currently_batting].required_rr = rrr;

    // change bowler
    if (currentBowler->balls % 6 == 0 && currentBowler->balls > 0)
    {
        // currentBowler->balls = 0;
        currentBowlerIndex++;
        if (currentBowlerIndex >= team[1 - currently_batting].bowler_Count)
        {
            currentBowlerIndex = 0; // rotate
        }

        // swap batsman
        // Batsman tmp = team[currently_batting].batsmen[currentBatsmanIndex];
        int temp = currentBatsmanIndex;
        currentBatsmanIndex = secondary_batsman_index;
        secondary_batsman_index = temp;
        currentBatsman = &team[currently_batting].batsmen[currentBatsmanIndex];
        currentBowler = &team[1 - currently_batting].bowlers[currentBowlerIndex];
    }

    // Display updated stats
    printf("RUNS SCORED: %d\n", runs);
    
    //printf("ON STRIKE: %s\n", team[currently_batting].batsmen[currentBatsmanIndex].name);
    //printf("NON-STRIKER: %s\n", team[currently_batting].batsmen[secondary_batsman_index].name);
    if (isOut || 6 * MAX_OVERS <= team[currently_batting].total_balls)
    {
        printf("WICKET %s IS OUT\n", currentBatsman->name);
        currentBatsmanIndex++;
        secondary_batsman_index++;
        // printf("total balls %d", team[currently_batting].total_balls);
        if ((currentBatsmanIndex >= team[currently_batting].batsman_Count || 6 * MAX_OVERS <= team[currently_batting].total_balls) && first_team_batting)
        {

            printf(GREEN "INNINGS OVER\n" RESET);
            puts(GREEN "SECOND INNINGS IS STARTING" RESET);
            first_team_batting = 0;
            currently_batting = 1 - currently_batting;
            currentBatsman = &team[currently_batting].batsmen[currentBatsmanIndex = 0];
            option();

            return;
        }

        currentBatsman = &team[currently_batting].batsmen[currentBatsmanIndex];
    }
    if ((currentBatsmanIndex >= team[currently_batting].batsman_Count || 6 * MAX_OVERS < team[currently_batting].total_balls || team[currently_batting].totalRuns > team[1 - currently_batting].totalRuns) && !first_team_batting)
    {
        winner();
        // ManOfTheMatch(teams);
        view_Current_Status(teams);
        end_of_match = 1;
        first_team_batting = 0;
        return;
    }
    // first_batting_team indexing problem   :not fixed

    printf("%d/%d\t (%d.%d)\n\n", team[currently_batting].totalRuns, team[currently_batting].totalWickets, team[currently_batting].total_balls / 6, team[currently_batting].total_balls % 6);

    printf("CRR: %.2f\n", team[currently_batting].current_rr);
    if (!first_team_batting)
        printf("RRR: %.2f\n", rrr);

    // Save updated stats to file
    save_Match_Stats_To_File(&team[currently_batting], (currently_batting == 0 ? filename1 : filename2));
    save_Match_Stats_To_File(&team[1 - currently_batting], (currently_batting == 0 ? filename2 : filename1));
}

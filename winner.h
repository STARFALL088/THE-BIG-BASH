#include "function.h"

void winner()
{
    end_of_match=1;
    Team winner;
    if (teams[0].totalRuns > teams[1].totalRuns)
        winner = teams[0];
    else if (teams[0].totalRuns == teams[1].totalRuns)
    {
        puts(BLUE "===========================================" RESET);
        puts(BLUE "             CRICKET MATCH RESULT         " RESET);
        puts(BLUE "===========================================" RESET);

        puts("");
        puts(BLUE "                 ITS A DRAW               " RESET);
        puts("");
        return;
    }
    else
        winner = teams[1];
    puts(BLUE "===========================================" RESET);
    puts(BLUE "             CRICKET MATCH RESULT         " RESET);
    puts(BLUE "===========================================" RESET);
    // puts(BLUE "Teams: " RESET);
    puts(" ");
    printf(BLUE "      %s  VS  %s\n" RESET, teams[0].name, teams[1].name);
    puts(BLUE "-------------------------------------------" RESET);
    puts(BLUE "              WINNER ANNOUNCEMENT        " RESET);
    puts(" ");
    printf(BLUE "               %s \n" RESET, winner.name);
    puts(" ");
    puts(BLUE "===========================================" RESET);
    puts(BLUE "     CONGRATULATIONS TO THE WINNING TEAM!     " RESET);
    puts(BLUE "===========================================" RESET);


    //printf("\nWANNA PLAY ANOTHER MATCH !");
    return;
}
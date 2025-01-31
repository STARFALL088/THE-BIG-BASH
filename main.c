#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include "macro.h"
#include "login.h"
#include "man_of_the_match.h"
#include "winner.h"
#include "welcome.h"
#include "begin.h"
#include "function.h"
#include "option.h"
#include "signup.h"
#include "manage_team.h"
#include "simulate_match.h"
#include "view_next_ball.h"
#include "view_current_status.h"
#include "save_match_to_file.h"
#include "view.h"
#include "save_user_to_file.h"
#include "save_team_to_file.h"
#include "load_team.h"
#include "load_user.h"
#include "initialize_team.h"
#include "is_strong.h"
#include "is_user_name_taken.h"




int main()
{
    srand(time(0)); // Seed for random number generation
    welcome();

    user_Count = load_Users_from_File();
    initialize_Teams(teams);
    begin();
    if(end_of_match==1)return 0;

    return 0;
}










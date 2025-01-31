// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "function.h"

// Function prototypes
void initialize_Teams(Team teams[]);
void simulate_Match(Team teams[]);
int login(int user_Count, int *logged_In_Team_Index);
int signup(int *user_Count);
void save_Users_to_File(int user_Count);
int load_Users_from_File();
void manageTeam(Team *team);
void saveTeamToFile(Team *team, const char *filename);
void loadTeamFromFile(Team *team, const char *filename);
void displayBattingView(Team *team);
void displayBowlingView(Team *team);
int isStrongPassword(const char *password);
int isUsernameTaken(const char *username);
void view_Next_Ball(Team team[], const char *filename1, const char *filename2);
void view_Current_Status(Team teams[]);
void save_Match_Stats_To_File(Team *team, const char *filename);
void begin();
void option();
void winner();

// void current_run_rate(Team teams[]);
void welcome();

#endif // FUNCTIONS_H
#define MAX_PLAYERS 5
#define MAX_TEAMS 2
#define MAX_OVERS 3
#define USERNAME_LENGTH 20
#define PASSWORD_LENGTH 20
#define MAX_USERS 100


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
// Struct to store player details
typedef struct
{
    char name[20];
    int runs;
    int balls;
    int sixes;
    int fours;
    int is_out;
    float strike_rate;
} Batsman;

typedef struct
{
    char name[20];
    float overs;
    int balls;
    int runs_conceded;
    int wickets;
    float economy;
} Bowler;

// Struct to store team details
typedef struct
{
    char name[20];
    Batsman batsmen[MAX_PLAYERS];
    Bowler bowlers[MAX_PLAYERS];
    int batsman_Count;
    int bowler_Count;
    int totalRuns;
    int totalWickets;
    int total_balls;
    float current_rr;
    float required_rr;
} Team;
Team teams[MAX_TEAMS];

typedef struct
{
    char name[20];
    int points; // Performance points for MoM calculation
    char team[20];
    char role[10]; // "Batsman" or "Bowler"
    union
    {
        struct
        {
            int runs;
            float strike_rate;
        } bat;
        struct
        {
            int wickets;
            float economy;
        } bowl;
    } stats;
} PlayerPerformance;
PlayerPerformance performances[MAX_PLAYERS * 2];
// Struct to store user credentials
typedef struct
{
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int teamIndex; // 0 for Team1, 1 for Team2
} User;

User users[MAX_USERS]; // Define the users array globally

int user_Count;
int logged_In_Team_Index = -1;
int first_team_batting = 1;
int currently_batting = 0;
int end_of_match = 0;

int login(int user_Count, int *logged_In_Team_Index)
{
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    printf(WHITE "\nENTER USERNAME: " RESET);
    scanf("%s", username);
    printf(WHITE "ENTER PASSWORD: " RESET);
    // Masking the password input with asterisks (****)
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch(); 
        if (ch == '\r' || ch == '\n')
        { 
            password[i] = '\0';
            break;
        }
        else if (ch == '\b' && i > 0)
        { 
            i--;
            printf("\b \b"); 
        }
        else if (i < PASSWORD_LENGTH - 1)
        {
            password[i++] = ch;
            printf("*"); 
        }
    }

    for (int i = 0; i < user_Count; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            *logged_In_Team_Index = users[i].teamIndex;
            return 1; // Login successful
        }
    }
    return 0; // Login failed
}

#include "function.h"

// check if a string has spaces
int containsSpace(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            return 1;
        }
    }
    return 0; 
}

int signup(int *user_Count)
{
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int teamChoice;

    
    while (1) {
        printf(WHITE"ENTER A NEW USERNAME: "RESET);
        scanf("%s", username);

        if (containsSpace(username)) {
            printf(WHITE"USERNAME CANNOT CONTAIN SPACES. PLEASE TRY AGAIN.\n"RESET);
        } else {
            break; // Valid username
        }
    }

    // Get password
    while (1) {
        printf(WHITE"ENTER A NEW PASSWORD: "RESET);
        scanf("%s", password);

        if (containsSpace(password)) {
            printf(WHITE"PASSWORD CANNOT CONTAIN SPACES. PLEASE TRY AGAIN.\n"RESET);
        } else if (!isStrongPassword(password)) {
            printf(WHITE"PASSWORD IS NOT STRONG ENOUGH..\n IT MUST BE AT LEAST 8 CHARACTERS LONG, CONTAIN UPPERCASE, LOWERCASE, DIGITS, AND SPECIAL CHARACTERS :(\n"RESET);
        } else {
            break; // Valid password
        }
    }

    // Get team choice
    printf(WHITE"CHOOSE TEAM (1 FOR OEH, 2 FOR LSH): "RESET);
    scanf("%d", &teamChoice);

    if (teamChoice < 1 || teamChoice > 2)
    {
        printf(WHITE"INVALID TEAM CHOICE :(\n"RESET);
        return 0;
    }

    // Check if username already exists
    if (isUsernameTaken(username))
    {
        printf(WHITE"USERNAME ALREADY TAKEN. PLEASE CHOOSE A DIFFERENT USERNAME.\n"RESET);
        return 0; // Signup failed
    }

    // Add new user
    strcpy(users[*user_Count].username, username);
    strcpy(users[*user_Count].password, password);
    users[*user_Count].teamIndex = teamChoice - 1; // 0 for Team1, 1 for Team2
    (*user_Count)++;
    return 1; // Signup successful
}
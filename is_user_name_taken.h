#include "function.h"
int isUsernameTaken(const char *username)
{
    int user_Count = load_Users_from_File();
    for (int i = 0; i < user_Count; i++)
    {
        if (strcmp(users[i].username, username) == 0)
        {
            return 1;
        }
    }
    return 0;
}

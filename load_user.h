#include "function.h"

int load_Users_from_File()
{
    FILE *file = fopen("users.txt", "r");
    if (file == NULL)
    {
        return 0; // No users file exists yet
    }

    int user_Count = 0;
    while (fscanf(file, "%s %s %d", users[user_Count].username, users[user_Count].password, &users[user_Count].teamIndex) != EOF)
    {
        user_Count++;
    }

    fclose(file);
    return user_Count;
}

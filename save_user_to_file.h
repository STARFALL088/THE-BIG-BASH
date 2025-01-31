#include"function.h"

void save_Users_to_File(int user_Count)
{
    FILE *file = fopen("users.txt", "w");
    if (file == NULL)
    {
        printf("CANNOT OPEN FILE :(\n");
        return;
    }

    for (int i = 0; i < user_Count; i++)
    {
        fprintf(file, "%s %s %d\n", users[i].username, users[i].password, users[i].teamIndex);
    }

    fclose(file);
}


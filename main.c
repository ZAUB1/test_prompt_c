#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "calc.h"
#include "actions.h"
#include "main.h"
#include "note.h"
#include "cat.h"

void cmd_handle();
void calc();

void cmd_handle()
{	
    char cmd[30];
    scanf("%s", cmd);

    if (strcmp(cmd, "ls") == 0)
    {
        char ls[6];

        #ifdef win
            strcpy(ls, "dir");
        #else
            strcpy(ls, "ls");
        #endif

        system(ls);

        prompt_back();
    }
    else if (strcmp(cmd, "ping") == 0)
    {
        printf("%s\n", "C'est partit pour le DDOS");
        printf("%s\n", "Args : ?");
        printf("%s", "-> ");

        char ip[12];
        scanf("%s", ip);

        char ping[20] = "ping ";
        strcat(ping, ip);

        system(ping);

        prompt_back();
    }
    else if (strcmp(cmd, "rm") == 0)
    {
        printf("%s\n", "");
        printf("%s\n", "| NORMAL = 0 | R = 1 |");
        printf("%s", "-> ");

        int type;
        scanf("%d", &type);

        if (type == 0)
        {
            printf("%s\n", "Entrez le nom du fichier ");
            printf("%s", "-> ");
            
            char name[100];
            scanf("%s", name);

            char rm[120] = "rm ";
            strcat(rm, name);

            printf("%s %s %s\n", "Etes vous sur de vouloir supprimer le fichier", name, "?");
            printf("%s", "Y/N -> ");

            char choice[5];
            scanf("%s", choice);

            if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0)
            {
                system(rm);
                prompt_back();
            }
            else if (strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0)
            {
                prompt_back();
            }
        }
        else if (type == 1)
        {
            #ifdef win //rmdir /s
                printf("%s\n", "Entrez le nom du dossier ");
                printf("%s", "-> ");
                
                char name[100];
                scanf("%s", name);

                char rm[120] = "rmdir /s ";
                strcat(rm, name);

                printf("%s %s %s\n", "Etes vous sur de vouloir supprimer le dossier", name, "?");
                printf("%s", "Y/N -> ");

                char choice[5];
                scanf("%s", choice);

                if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0)
                {
                    system(rm);
                    prompt_back();
                }
                else if (strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0)
                {
                    prompt_back();
                }
            #else
                printf("%s\n", "Entrez le nom du dossier ");
                printf("%s", "-> ");
                
                char name[100];
                scanf("%s", name);

                char rm[120] = "rm -r ";
                strcat(rm, name);

                printf("%s %s %s\n", "Etes vous sur de vouloir supprimer le dossier", name, "?");
                printf("%s", "Y/N -> ");

                char choice[5];
                scanf("%s", choice);

                if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0)
                {
                    system(rm);
                    prompt_back();
                }
                else if (strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0)
                {
                    prompt_back();
                }
            #endif
        }
    }
    else if (strcmp(cmd, "cd") == 0)
    {
        printf("%s\n", "Where to go ? ");
        printf("%s", "-> ");

        char tdir[100];
        scanf("%s", tdir);

        //char cd[120] = "cd ";
        //strcat(cd, tdir);

        //system(cd);
        chdir(tdir);

        prompt_back();
    }
    else if (strcmp(cmd, "l") == 0)
    {
        #ifdef win
            //todo
        #else
            system("ls -lah");
            prompt_back();
        #endif
    }
    else if (strcmp(cmd, "ifconfig") == 0)
    {
        #ifdef win
            system("ipconfig");
        #else
            system("ifconfig");
        #endif
        
        prompt_back();
    }
    else if (strcmp(cmd, "calc") == 0)
    {
        calc();
    }
    else if (strcmp(cmd, "note") == 0)
    {
        note();
    }
    else if (strcmp(cmd, "cat") == 0)
    {
        cat();
    }
    else if (strcmp(cmd, "help") == 0)
    {
        printf("%s\n", "--ZAUB1 Shell--");
        printf("%s\n", "");
        #ifdef win
            printf("%s\n", "[^u]Commandes disponibles :[^/u]"); // Not tested
        #else
            printf("\x1b[4m%s\x1b[0m%s\n", "Commandes disponibles :", "");
        #endif
        printf("%s\n", "• ls : List as usual");
        printf("%s\n", "• l : Alias to ls -lah");
        printf("%s\n", "• ping : Ping to wanted adress");
        printf("%s\n", "• cd : Allows to change directory");
        printf("%s\n", "• ifconfig : Displays network configuration");
        printf("%s\n", "• rm : Allows to remove any file or directory");
        printf("%s\n", "• calc : Displays a calculator within the terminal");
        printf("%s\n", "• help : Shows this page");
        printf("%s\n", "• note : Little note system that write in a file");
        prompt_back();
    }
    else if (strcmp(cmd, "clear") == 0)
    {
        prompt_reset();
    }
    else if (strcmp(cmd, "exit") == 0)
    {
        printf("%s\n", "++");
        exit(0);
    }
    else
    {
        printf("%s\n", "Nope");
        prompt_back();
    }
}

int main()
{
    prompt_reset();

    cmd_handle();
}
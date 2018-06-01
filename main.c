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
#include "ls.h"
#include "touch.h"
#include "mkdir.h"

void cmd_handle();
void calc();

void cmd_handle()
{	
    //char cmd[30];
    //int chk = scanf("%s", cmd);
    
    char* cmd = NULL;
    size_t len = 0;
    getline(&cmd, &len, stdin);

    if (strcmp(cmd, "ls\n") == 0)
    {
        /*char ls[6];

        #ifdef win
            strcpy(ls, "dir");
        #else
            strcpy(ls, "ls");
        #endif

        system(ls);

        prompt_back();*/

        ls();
    }
    else if (strcmp(cmd, "ping\n") == 0)
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
    else if (strcmp(cmd, "rm\n") == 0)
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

            char rm[120] = "";
            strcat(rm, name);

            printf("%s %s %s\n", "Etes vous sur de vouloir supprimer le fichier", name, "?");
            printf("\x1b[32m%s\x1b[0m%s\x1b[31m%s \x1b[0m%s", "Y", "/", "N", "-> ");

            char choice[5];
            scanf("%s", choice);

            if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0)
            {
                //system(rm);
                remove(rm);
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

                char rm[120] = "";
                strcat(rm, name);

                printf("%s %s %s\n", "Etes vous sur de vouloir supprimer le dossier", name, "?");
                printf("%s", "Y/N -> ");

                char choice[5];
                scanf("%s", choice);

                if (strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0)
                {
                    //system(rm);
                    rmdir(rm);
                    prompt_back();
                }
                else if (strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0)
                {
                    prompt_back();
                }
            #endif
        }
    }
    else if (strcmp(cmd, "cd\n") == 0)
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
    else if (strcmp(cmd, "l\n") == 0)
    {
        /*#ifdef win
            //todo
        #else
            system("ls -lah");
            prompt_back();
        #endif*/
        lah();
    }
    else if (strcmp(cmd, "ifconfig\n") == 0)
    {
        #ifdef win
            system("ipconfig");
        #else
            system("ifconfig");
        #endif
        
        prompt_back();
    }
    else if (strcmp(cmd, "calc\n") == 0)
    {
        calc();
    }
    else if (strcmp(cmd, "note\n") == 0)
    {
        note();
    }
    else if (strcmp(cmd, "cat\n") == 0)
    {
        cat();
    }
    else if (strcmp(cmd, "touch\n") == 0)
    {
        touch();
    }
    else if (strcmp(cmd, "mkdir\n") == 0)
    {
        mkdir_o();
    }
    else if (strcmp(cmd, "help\n") == 0)
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
    else if (strcmp(cmd, "clear\n") == 0)
    {
        prompt_reset();
    }
    else if (strcmp(cmd, "exit\n") == 0)
    {
        printf("%s\n", "++");
        exit(0);
    }
    else if (strcmp(cmd, "\n\0") == 0)
    {
        prompt_back();
    }
    else
    {
        printf("%s\n", "Nope");
        prompt_back();
    }
}

/*void keys()
{
    int ch2;
    while (1)
    {

        ch2 = getc(stdin);
        printf("%c", ch2);
        switch(ch2)
        {
            case 72: printf("UP WAS PRESSED\n");
            case 80: printf("DOWN WAS PRESSED\n");
            case 75: printf("LEFT WAS PRESSED\n");
            case 77: printf("RIGHT WAS PRESSED\n");

            default:
            printf("SOME OTHER KEY PRESSED: %d\n", ch2);
        }
    }
}*/

int main()
{
    prompt_reset();

    cmd_handle();

    //keys();
}

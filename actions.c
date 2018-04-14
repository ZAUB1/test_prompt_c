#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "calc.h"
#include "actions.h"
#include "main.h"

void clear_only()
{
    char clear_o[10];

    #ifdef win
        strcpy(clear_o, "cls");
    #else
        strcpy(clear_o, "clear");
    #endif

    system(clear_o);
}

void prompt_reset()
{
    char cwd[1024];
       if (getcwd(cwd, sizeof(cwd)) != NULL)
       {
        getcwd(cwd, sizeof(cwd));
    }
       else
    {
        puts("Impossible de get le wo dir");
    }

    char clear[6];
    
    #ifdef win
        strcpy(clear, "cls");
    #else
        strcpy(clear, "clear");
    #endif

    system(clear);
    printf("\x1b[32m%s \x1b[31m%s \x1b[0m%s", cwd, "=>", "");

    cmd_handle();
}

void prompt_back()
{
    char cwd[1024];
       if (getcwd(cwd, sizeof(cwd)) != NULL)
       {
        getcwd(cwd, sizeof(cwd));
    }
       else
    {
        puts("Impossible de get le wo dir");
    }

    printf("%s\n", "");
    printf("\x1b[32m%s \x1b[31m%s \x1b[0m%s", cwd, "=>", "");
    cmd_handle();
}
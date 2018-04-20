#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "mkdir.h"
#include "actions.h"

void mkdir_o()
{
    struct stat st = {0};

    char dir[100];
    scanf("%s", dir);

    if (stat(dir, &st) == -1) 
    {
        mkdir(dir, 0700);
        prompt_back();
    }
    else
    {
        printf("%s\n", "This directory already exist");
        prompt_back();
    }
}
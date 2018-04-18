#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "actions.h"

void touch()
{
    char n[100];
    scanf("%s", n);

    FILE *fc = fopen(n, "w+");
    if (fc == NULL)
    {
        perror("bite");
		puts("Il y a une couille dans le paté");
        exit(0);
    }   

    fclose(fc);

    prompt_back();
}
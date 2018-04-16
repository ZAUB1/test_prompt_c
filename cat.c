#include <stdio.h>
#include <stdlib.h>
#include "cat.h"
#include "actions.h"

void cat()
{
    char name[100];
    printf("%s\n", "Entrez le nom du fichier a lire");
    scanf("%s", name);

    FILE* fichier = fopen(name, "r");

    if (fichier == NULL)
    {
        puts("Il y a une couille dans le paté");
        return;
    }
    
    char c;
    while (fscanf(fichier, "%c", &c) != EOF)
    {
        printf("\x1b[%dm%s", 0, "");
        printf("%c", c);
        fflush(stdout);
    }

    prompt_back();
    //delay(1000);
}
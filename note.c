#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actions.h"
#include "main.h"
#include "note.h"

#define MAX 100
#define LEN 80

char text[MAX][LEN];

void note(void)
{
    int t, x, j;

    clear_only();

    printf("%s\n", "Entrez une ligne vide pour sauvegarder");

    getchar();

    for(t = 0; t < MAX; t++) 
    {
        printf("%d: ", t);
        //gets(text[t]);
	fgets(text[t], sizeof(text[t]), stdin);

        //if(!*text[t])
        //{
        //    break;
        //}
	//int z = strlen(text[t]);
	//printf("%d\n", z);
	if (strlen(text[t]) == 1)
	{
		break;
	}
    }

    printf("%s\n", "Entrez le nom du fichier : ");
    char name[100];
    scanf("%s", name);
    printf("%s", name);

    char extadd[100] = ".Z1";
    strcat(name, ".z1");
    //printf("%s", name);

    FILE *f = fopen(name, "w+");
    if (f == NULL)
    {
        perror("bite");
		puts("Il y a une couille dans le paté");
        exit(0);
    }

    for(x = 0; x < t; x++)
    {
        for(j = 0; text[ x ][ j ]; j++);

        fprintf(f, "%s\n", text[x]);
    }

    fclose(f);
    clear_only();
    prompt_reset();
}

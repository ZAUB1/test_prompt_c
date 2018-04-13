#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void cmd_handle();

void prompt_reset()
{
	char cwd[1024];
   	if (getcwd(cwd, sizeof(cwd)) != NULL)
   	{
    	getcwd(cwd, sizeof(cwd));
	}
   	else
	{
    	perror("Impossible de get le wo dir");
	}

	char clear[6];
	
	#ifdef win
		strcpy(clear, "cls");
	#else
		strcpy(clear, "clear");
	#endif

    system(clear);
	printf("%s %s", cwd,"=> ");

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
    	perror("Impossible de get le wo dir");
	}

	printf("%s\n", "");
	printf("%s %s", cwd, "=> ");
	cmd_handle();
}

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
	}
}

int main()
{
	prompt_reset();

	cmd_handle();
}

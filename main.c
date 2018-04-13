#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void cmd_handle();

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

#define LIGNES 64

void calc()
{	
	clear_only();

	for (int ii = 0; ii < 65; ii++)
    {
        printf("%s", "-");
    }

	printf("%s\n", " ");
	printf("%s\n", "| [1] + / - / x / ÷ | [2] Add |                                 |");
	printf("%s\n", "| [01] Pour fermer				                |");///////////////

	for (int iii = 0; iii < 65; iii++)
    {
        printf("%s", "-");
    }

	printf("%s\n", " ");
    printf("%s", "=> ");
	int x;
	scanf("%d", &x);

	if (x == 1)
	{
		printf("%s", "NBR 1 ? -> ");
        double n;
        scanf("%lf", &n);
        printf("%s", "NBR 2 ? -> ");
        double nn;
        scanf("%lf", &nn);
        printf("%s", "Operation (+, -, x, /) ? -> ");
        char ope[2];
        scanf("%s", ope);

        if ((strcmp(ope, "+") == 0))
        {
            double o = n + nn;
            printf("%s %lf", "Result :", o);
        }
        else if ((strcmp(ope, "-") == 0))
        {
            double o = n - nn;
            printf("%s %lf", "Result :", o);
        }
        else if ((strcmp(ope, "x") == 0))
        {
            double o = n * nn;
            printf("%s %lf", "Result :", o);
        }
        else if ((strcmp(ope, "-") == 0))
        {
            double o = (double)n / (double)nn;
            printf("%s %lf", "Result :", o);
        }

        printf("%s\n", "");

        getchar();
        getchar();

        calc();
	}
    else if (x == 2)
    {
        printf("%s\n", "Entrez tous les nombres à ajouter, puis tapez 0 pour faire le calcul");
        
        int z = 1;
        while (z != 0)
        {
            int e;
            printf("%s", "->");
            int f;
            scanf("%lf", &f);
            if (f != 0)
            {
                e = e + f;
            }
            else
            {
                z = f;
            }
        }
    }
	else if (x == 01)
	{
		prompt_back();
	}
}

int main()
{
	prompt_reset();

	cmd_handle();
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "calc.h"
#include "actions.h"
#include "main.h"

#define LIGNES 64

long otd(long, long);
long dto(long, long);

void calc()
{	
    clear_only();

    for (int ii = 0; ii < 65; ii++)
    {
        printf("%s", "-");
    }

    printf("%s\n", " ");
    printf("%s\n", "| [1] + / - / x / ÷ | [2] Add | [3] Eucl | [4] Conversion bases |");
    printf("%s\n", "| [0] Pour fermer				                |");///////////////

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
        printf("%s", "↵");

        getchar();
        getchar();

        calc();
    }
    else if (x == 2)
    {
        printf("%s\n", "Entrez tous les nombres à ajouter, puis tapez 0 pour faire le calcul");
        
        double z;
        double e;

        while (1)
        {
            st:
            printf("%s", "-> ");
            scanf("%lf", &z);
            if (z != 0)
            {
                e = e + z;
                goto st;
            }
            else
            {
                printf("%s %lf\n", "Total : ", e);
                break;
            }
        }

        printf("%s\n", "");
        printf("%s", "↵");

        getchar();
        getchar();

        calc();
    }
    else if (x == 3)
    {
        long a;
        long b;
        long r;

        printf("%s\n", "Numerateur : ");
        printf("%s", "-> ");
        scanf("%ld", &a);
        printf("%s\n", "Denominateur : ");
        printf("%s", "-> ");
        scanf("%ld", &b);
  
        while (b > 0) 
        {
            r = a % b;
            a = b;
            b = r;
        }

        printf("%s %ld\n", "Result :", a);
        printf("%s %ld\n", "Reste : ", r);

        printf("%s\n", "");
        printf("%s", "↵");

        getchar();
        getchar();

        calc();
    }
    else if (x == 4)
    {
        long base1;
        long base_o;
        long nbr1;
        long number_o;
        long s;

        printf("%s\n", "Entrez le nombre : ");
        printf("%s", "-> ");
        scanf("%ld", &nbr1);
        printf("%s\n", "Entrez sa base : ");
        printf("%s", "-> ");
        scanf("%ld", &base1);
        printf("%s\n", "Entrez la base dans laquelle convertir : ");
        printf("%s", "-> ");
        scanf("%ld", &base_o);

        //main

        if (base_o == 10)
        {
            number_o = otd(nbr1, base1);
        }

        else
        {
            if (base1 == 10)
            {
                number_o = dto(nbr1,base_o);
            }
            else
            {
                s = otd(nbr1, base1);
                number_o = dto(s, base_o);
            }
        }

        printf("%s %ld", "Result =", number_o);

        printf("%s\n", "");
        printf("%s", "↵");

        getchar();
        getchar();

        calc();
    }
    else if (x == 0)
    {
        prompt_back();
    }
    else
    {
        printf("%s", "Nope");
        printf("%s\n", "");
        printf("%s", "↵");

        getchar();
        getchar();

        calc();
    }
}

long otd(long nbr1, long base1)
{
    long c;
    long op;
    long z;
    long p;

    op = 0;
    c = nbr1;
    p = 1;

    while(c != 0)
    {
        z = c % 10;
        c = c / 10;
        op = op + z * p;
        p = p * base1;
    }

    return op;
}

long dto(long number_o, long base_o)
{
    long op = 0;
    long p;
    long c;
    long z;

    c = number_o;
    p = 1;

    while(c != 0)
    {
        z = c % base_o;
        c = c / base_o;
        op = op + z * p;
        p = p * 10;
    }

    return op;
}
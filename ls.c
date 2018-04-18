#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"
#include "actions.h"
#include "ls.h"

void ls()
{
    struct dirent **namelist;
    int n;

    n = scandir(".", &namelist, NULL, alphasort);
    if (n == -1)
    {
        perror("scandir");
        exit(0);
    }

    while (n--) 
    {
        printf("%s ", namelist[n]->d_name);
        free(namelist[n]);
    }

    free(namelist);

    prompt_back();
}

void lah()
{
    struct dirent **namelist;
    struct stat st;
    int n;

    n = scandir(".", &namelist, NULL, alphasort);
    if (n == -1)
    {
        perror("scandir");
        exit(0);
    }

    while (n--) 
    {
        stat(namelist[n]->d_name, &st);
        //printf("%d", st.st_size);

        int fileMode = st.st_mode;

        if ((fileMode & S_IRUSR) && (fileMode & S_IREAD))
        {
            printf("r");
        }
        else
        {
            printf("-");
        }

        if ((fileMode & S_IWUSR) && (fileMode & S_IWRITE))
        {
            printf("w");
        }
        else
        {
            printf("-");
        }

        if ((fileMode & S_IXUSR) && (fileMode & S_IEXEC))
        {
            printf("x");
        }
        else
        {
            printf("-");
        }

        if ((fileMode & S_IRGRP) && (fileMode & S_IREAD))
        {
            printf("r");
        }
        else
        {
            printf("-");
        }

        if ((fileMode & S_IWGRP) && (fileMode & S_IWRITE))
        {
            printf("w");
        }
        else
        {
            printf("-");
        }

        if ((fileMode & S_IXGRP) && (fileMode & S_IEXEC))
        {
            printf("x");
        }
        else
        {
            printf("-");
        }

        if ((fileMode & S_IROTH) && (fileMode & S_IREAD))
        {
            printf("r");
        }
        else
        {
            printf("-");
        }
        
        if ((fileMode & S_IWOTH) && (fileMode & S_IWRITE))
        {
            printf("w");
        }
        else
        {
            printf("-");
        }

        if ((fileMode & S_IXOTH) && (fileMode & S_IEXEC))
        {
            printf("x");
        }
        else
        {
            printf("-");
        }

        printf(" |%s", " ");

        struct passwd *pw = getpwuid(st.st_uid);
        struct group  *gr = getgrgid(st.st_gid);

        printf("%s - %s", pw->pw_name, gr->gr_name);

        struct tm *foo;
        foo = gmtime(&(st.st_mtime));

        char *mon;

        if (foo->tm_mon == 0)
        {
            mon = "Jan";
        }
        else if (foo->tm_mon == 1)
        {
            mon = "Feb";
        }
        else if (foo->tm_mon == 2)
        {
            mon = "Mar";
        }
        else if (foo->tm_mon == 3)
        {
            mon = "Apr";
        }
        else if (foo->tm_mon == 4)
        {
            mon = "May";
        }
        else if (foo->tm_mon == 5)
        {
            mon = "Jun";
        }
        else if (foo->tm_mon == 6)
        {
            mon = "Jul";
        }
        else if (foo->tm_mon == 7)
        {
            mon = "Aug";
        }
        else if (foo->tm_mon == 8)
        {
            mon = "Sep";
        }
        else if (foo->tm_mon == 9)
        {
            mon = "Oct";
        }
        else if (foo->tm_mon == 10)
        {
            mon = "Nov";
        }
        else if (foo->tm_mon == 11)
        {
            mon = "Dec";
        }

        printf("| %d/%s - %d:%d |%s", foo->tm_mday, mon , foo->tm_hour, foo->tm_min," ");

        if (st.st_size > 1048576)
        {
            int mo = st.st_size / 1048576;
            //S_ISDIR((st.st_mode), ? "d" : "-");
            printf("%d Mo | %s\n", mo, namelist[n]->d_name);
        }
        else if (st.st_size > 1024)
        {
            double ko = st.st_size / 1024;
            printf("%.2lf Ko | %s\n", ko, namelist[n]->d_name);
        }
        else
        {
            printf("%d o | %s\n", st.st_size, namelist[n]->d_name);
        }

        free(namelist[n]);
    }

    free(namelist);

    prompt_back();
}
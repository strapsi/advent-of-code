#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *f;

    char *fline = NULL;
    char *sline = NULL;
    char *tline = NULL;
    size_t len = 0;
    ssize_t read;

    f = fopen("./inputs/day3", "r");

    if (f == NULL)
        return 1;

    int prio = 0;
    getline(&fline, &len, f);
    getline(&sline, &len, f);
    read = getline(&tline, &len, f);

    while (read != -1)
    {
        for (int i = 0; i < strlen(fline); i++)
        {
            if (strchr(sline, fline[i]) != NULL && strchr(tline, fline[i]))
            {
                if (fline[i] > 96)
                    prio += (fline[i] - 96);
                else
                    prio += (fline[i] - 38);
                break;
            }
        }

        getline(&fline, &len, f);
        getline(&sline, &len, f);
        read = getline(&tline, &len, f);
    }
    fclose(f);

    printf("the solution is %d\n", prio);

    if (fline)
        free(fline);
    if (sline)
        free(sline);
    if (tline)
        free(tline);
    return 0;
}
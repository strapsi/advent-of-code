#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *f;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    f = fopen("./inputs/day3", "r");

    if (f == NULL)
        return 1;

    int prio = 0;
    while ((read = getline(&line, &len, f)) != -1)
    {
        int str_len = strlen(line);
        int former_len = str_len / 2;
        int latter_len = str_len - former_len;
        char *former = malloc(former_len + 1);
        char *latter = malloc(latter_len + 1);
        memcpy(former, line, former_len);
        memcpy(latter, line + former_len, latter_len);
        former[former_len] = '\0';
        latter[latter_len] = '\0';
        for (int i = 0; i < former_len; i++)
        {
            if (strchr(latter, former[i]) != NULL)
            {
                if (former[i] > 96)
                    prio += (former[i] - 96);
                else
                    prio += (former[i] - 38);
                break;
            }
        }

        free(former);
        free(latter);
    }
    fclose(f);

    printf("the solution is %d\n", prio);

    if (line)
        free(line);
    return 0;
}
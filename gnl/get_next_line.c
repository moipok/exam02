
#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}


int get_next_line(char **line)
{
    int ret;
    char c;
    char *tmp;
    int i;
    
    *line = malloc(sizeof(char) * 2);
    line[0][0] = '\0';
    while ((ret = read(0, &c, 1)) != 0)
    {
        if (c == '\n')
            return (1);
        else
        {
            tmp = *line;
            *line = malloc(sizeof(char) * (ft_strlen(*line) + 2));
            i = -1;
            while(tmp[++i])
                line[0][i] = tmp[i];
            line[0][i] = c;
            line[0][i + 1] = '\0';
            free(tmp);
        }
    }
    return (0);
}


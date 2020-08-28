#include <unistd.h>

void    ft_putchar(int c)
{
    write(1, &c, 1);
}

int ft_check1(char *s, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        if (s[i] == s[j])
            return (0);
        j++;
    }
    return(1);
}

int ft_check(char *s, char c)
{
    int j;

    j = 0;
    while (s[j])
    {
        if (s[j] == c)
            return (0);
        j++;
    }
    return(1);
}

int main(int argc, char **argv)
{
    int i;

    if (argc != 3)
    {
        ft_putchar('\n');
        return (0);
    }
    i = 0;
    while (argv[1][i])
    {
        if (ft_check1(argv[1], i) == 1)
        {
            ft_putchar(argv[1][i]);
        }
        i++;
    }
    i = 0;
    while (argv[2][i])
    {
        if (ft_check(argv[1], argv[2][i]) == 1 && ft_check1(argv[2], i) == 1)
        {
            ft_putchar(argv[2][i]);
        }
        i++;
    }
    ft_putchar('\n');
    return(0);
}
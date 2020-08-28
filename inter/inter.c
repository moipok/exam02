/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarbera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 16:19:57 by fbarbera          #+#    #+#             */
/*   Updated: 2020/08/28 16:20:01 by fbarbera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(int c)
{
    write(1, &c, 1);
}

int     ft_check(char *s, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        if (s[i] == s[j])
            return (-1);
        j++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i;
    int j;
    
    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    i = 0;
    while (argv[1][i])
    {
        j = 0;
        if (ft_check(argv[1], i) == 1)
        {
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                {
                    ft_putchar(argv[1][i]);
                    j++;
                    break;
                }
                j++;
            }
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_list
{
	int			flag_weght;
	int			flag_acc;
}				t_list;

void ft_putchar(int c)
{
    write(1, &c, 1);
}

int     ft_isnum(int c)
{
    if (c > '0' && c < '9')
        return (1);
    return (0);
}

int         ft_docase(const char *format, va_list p, t_list *flag)
{
    int i;

    i = 1;
    if ((format[i] == '*') || (ft_isnum(format[i]) == 1))
    {
        if (format[i] == '*')
            flag->flag_weght = va_arg(p, int);
        else
            flag->flag_weght = ft_atoi(format);
        
    }
    i++;
    return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list	p;
    int i;
    t_list *flag;

	va_start(p, format);
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
            i += ft_docase(format + i, p, flag);
        else
        {
            ft_putchar(format[i]);
            i++;
        }
    }

	va_end(p);
	return (i);
}
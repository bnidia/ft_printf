#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	char	*str;
	int		i;
	int		len;

	if (!s)
		return (-1);
	va_start(ap, s);
	i = 0;
	len = 0;
	str = (char *)malloc(4096);
	while (s[i])
	{
		if (s[i] == '%')
			process_type_field();
		else
		{

		}
	}
	write(1, str, len);
	free(str);
	va_end(ap);
	return (len);
}
#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	char	*str;
	int		i;
	size_t	len;
	size_t	size;

	if (!s)
		return (-1);
	va_start(ap, s);
	i = 0;
	len = 0;
	str = (char *)malloc(4096);
	size = 4096;
	while (s[i])
	{
		if (s[i] == '%')
			process_type_field(&len);
		else
		{

		}
		if (len = size)
			ft_realloc(&str, &size);
	}
	write(1, str, len);
	free(str);
	va_end(ap);
	return (len);
}

void	ft_realloc(char **str, size_t *size)
{
	char 	*new_str;
	size_t	i;
	size_t	i_size;

	i = 0;
	i_size = *size;
	if (*size <= 16384)
		*size *= 2;
	else
		*size += 4096;
	new_str = (char *)malloc(*size);
	while(i <= i_size)
	{
		new_str[i] = *str[i];
		i++;
	}
	free(*str);
	*str = new_str;
}
#include "ft_printf.h"
#include <unistd.h>

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	char	*str;
	size_t	s_i;
	size_t	len;
	size_t	size;

	if (!s)
		return (-1);
	va_start(ap, s);
	s_i = 0;
	len = 0;
	str = (char *)malloc(4096);
	size = 4096;
	while (s[s_i])
	{
		if (s[s_i] == '%')
			process_type_field(str, &len, ap, s, &s_i);
		else
		{
			str[len] = s[s_i];
		}
		if (len = size)
			ft_realloc(&str, &size);
	}
	write(1, str, len);
	free(str);
	va_end(ap);
	return (len);
}

void	process_type_field(char *str, size_t *len, va_list ap, char *s, size_t *s_i)
{
	*s_i++;//cspdiuxX%
	if (s[*s_i] == 'c')
		str[*len] = (char)va_arg(ap, int);
	if (s[*s_i] == 's')
		ft_s();
	if (s[*s_i] == 'p')
	if (s[*s_i] == 'd')
	if (s[*s_i] == 'i')
	if (s[*s_i] == 'u')
	if (s[*s_i] == 'x')
	if (s[*s_i] == 'X')

	if (s[*s_i] == '%')
		str[*len] = '%';
	*len++;
}

void	ft_realloc(char **str, size_t *size)
{
	size_t	i;
	size_t	i_size;
	char 	*new_str;

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
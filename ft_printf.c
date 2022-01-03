#include "ft_printf.h"
#include <unistd.h>

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	char	*str;
	size_t	s_i;
	size_t	size;

	if (s == NULL)
		return (-1);
	va_start(ap, s);
	s_i = 0;
	g_len = 0;
	str = (char *)malloc(4096);
	size = 4096;
	while (s[s_i])
	{
		if (s[s_i] == '%')
		{
			process_type_field(str, ap, s, &s_i);
			continue;
		}
		str[g_len++] = s[s_i++];
		if (g_len + 1024 > size)
			ft_realloc(&str, &size);
	}
	write(1, str, g_len);
	free(str);
	va_end(ap);
	return (g_len);
}

void	process_type_field(char *str, va_list ap, const char *s, size_t *s_i)
{
	(*s_i)++;
	if (s[*s_i] == 'c')
		str[g_len++] = (char)va_arg(ap, int);
	if (s[*s_i] == 's')
		ft_s(str, va_arg(ap, char *));
	if (s[*s_i] == 'p')
		ft_p(str, va_arg(ap, unsigned long long));
	if (s[*s_i] == 'd' || s[*s_i] == 'i')
		ft_di(str, va_arg(ap, int));
	if (s[*s_i] == 'u')
	if (s[*s_i] == 'x')
	if (s[*s_i] == 'X')

	if (s[*s_i] == '%')
		str[g_len] = '%';
	*s_i++;
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
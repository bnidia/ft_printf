/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:23:08 by bnidia            #+#    #+#             */
/*   Updated: 2022/01/04 19:53:34 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		s_i;

	if (s == NULL)
		return (-1);
	va_start(ap, s);
	s_i = 0;
	g_len = 0;
	g_size = 4096;
	g_str = (char *)malloc(g_size);
	while (s[s_i])
	{
		if (s[s_i] == '%')
		{
			process_type_field(ap, s, &s_i);
			continue ;
		}
		g_str[g_len++] = s[s_i++];
		if (g_len + 1024 > g_size)
			ft_realloc();
	}
	write(1, g_str, g_len);
	free(g_str);
	va_end(ap);
	return (g_len);
}

void	process_type_field(va_list ap, const char *s, int *s_i)
{
	(*s_i)++;
	if (s[*s_i] == 'c')
		g_str[g_len++] = (char)va_arg(ap, int);
	if (s[*s_i] == 's')
		ft_s(va_arg(ap, char *));
	if (s[*s_i] == 'p')
		ft_p(va_arg(ap, unsigned long long));
	if (s[*s_i] == 'd' || s[*s_i] == 'i')
		ft_di(va_arg(ap, int));
	if (s[*s_i] == 'u')
		ft_hex(va_arg(ap, unsigned int), 10, BASE_L);
	if (s[*s_i] == 'x')
		ft_hex(va_arg(ap, unsigned int), 16, BASE_L);
	if (s[*s_i] == 'X')
		ft_hex(va_arg(ap, unsigned int), 16, BASE_A);
	if (s[*s_i] == '%')
		g_str[g_len++] = '%';
	(*s_i)++;
}

void	ft_realloc(void)
{
	int		i;
	char	*new_str;

	i = 0;
	if (g_size <= 16384)
		g_size *= 2;
	else
		g_size += 4096;
	new_str = (char *)malloc(g_size);
	while (i < g_len)
	{
		new_str[i] = g_str[i];
		i++;
	}
	free(g_str);
	g_str = new_str;
}

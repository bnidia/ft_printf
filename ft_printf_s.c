/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:07:41 by bnidia            #+#    #+#             */
/*   Updated: 2022/01/11 21:29:18 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_out(t_pf *z);

int	ft_s(t_pf *z, const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if ((z->precision > 5 || z->precision == -1) && __linux__)
			ft_s(z, "(null)");
		else if ((z->precision != 0 && !(__linux__)))
			ft_s(z, "(null)");
		else
			ft_s(z, "");
		return (0);
	}
	if (z->precision > (int)ft_strlen(str) || z->precision == -1)
		z->precision = (int)ft_strlen(str);
	if (z->f_minus == false && z->width && z->width > z->precision)
	{
		while (z->width-- > z->precision)
		{
			z->s[z->s_i++] = ' ';
			if (ft_print_out(z) == -1)
				return (-1);
		}
	}
	while (str[i] && i < z->precision)
	{
		z->s[z->s_i++] = str[i++];
		if (ft_print_out(z) == -1)
			return (-1);
	}
	if (z->f_minus && z->width > z->precision)
	{
		while (z->width-- > z->precision)
		{
			z->s[z->s_i++] = ' ';
			if (ft_print_out(z) == -1)
				return (-1);
		}
	}
	return (0);
}

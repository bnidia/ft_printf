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

extern void	ft_itoa_base(t_pf *z, t_ull nbr, int base, const char *base_);
int			ft_print_out(t_pf *z);

int	ft_p(t_pf *z, t_ull nbr)
{
	int	numlen;

	numlen = (int)ft_numlen(nbr, 16) + 2;
	if (z->f_minus == false && z->width > numlen)
	{
		while (z->width-- > numlen)
		{
			z->s[z->s_i++] = ' ';
			if (ft_print_out(z) == -1)
				return (-1);
		}
	}
	z->s[z->s_i++] = '0';
	z->s[z->s_i++] = 'x';
	ft_itoa_base(z, nbr, 16, "0123456789abcdef");
	if (z->f_minus && z->width > numlen)
	{
		while (z->width-- > numlen)
		{
			z->s[z->s_i++] = ' ';
			if (ft_print_out(z) == -1)
				return (-1);
		}
	}
	return (0);
}

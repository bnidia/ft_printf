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

void	ft_s(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_s("(null)");
		return ;
	}
	while (s[i])
	{
		g_str[g_len++] = s[i++];
		if (g_len + 1024 > g_size)
			ft_realloc();
	}
}

void	ft_p(unsigned long long nbr)
{
	int					i;
	unsigned long long	temp;

	if (nbr == 0)
	{
		ft_s("0x0");
		return ;
	}
	ft_s("0x");
	i = 0;
	temp = nbr;
	while (temp >= 16 && i++ >= 0)
		temp /= 16;
	temp = i + 1;
	while (i >= 0)
	{
		g_str[g_len + i] = BASE_L[nbr % 16];
		nbr /= 16;
		i--;
	}
	g_len += (int)temp;
}

void	ft_di(int nbr)
{
	long long	nbr_long;
	long long	temp;
	int			i;

	i = 0;
	nbr_long = nbr;
	if (nbr == 0)
		g_str[g_len++] = '0';
	if (nbr == 0)
		return ;
	if (nbr_long < 0)
	{
		g_str[g_len++] = '-';
		nbr_long *= -1;
	}
	temp = nbr_long;
	while (temp > 0 && i++ >= 0)
		temp /= 10;
	nbr = i;
	while (i-- > 0)
	{
		g_str[g_len + i] = BASE_L[nbr_long % 10];
		nbr_long /= 10;
	}
	g_len += nbr;
}

void	ft_hex(unsigned int nbr, int base, const char *base_)
{
	int					i;
	unsigned long long	temp;

	if (nbr == 0)
	{
		g_str[g_len++] = '0';
		return ;
	}
	i = 0;
	temp = nbr;
	while (temp > 0)
	{
		temp /= base;
		i++;
	}
	temp = i;
	i--;
	while (i >= 0)
	{
		g_str[g_len + i] = base_[nbr % base];
		nbr /= base;
		i--;
	}
	g_len += (int)temp;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/05/07 20:42:54 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 24 bytes is enough because ull 0xffffffffffffffff - 18 chars */
int	ft_print_out(t_pf *z)
{
	int	i;

	i = 0;
	if (z->s_i + 24 > BUF_SIZE)
	{
		i = (int) write(1, z->s, z->s_i);
		z->s_printed += z->s_i;
		z->s_i = 0;
	}
	return (i);
}

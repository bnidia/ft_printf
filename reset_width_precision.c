/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 08:42:42 by bnidia            #+#    #+#             */
/*   Updated: 2022/05/07 20:56:05 by bnidia           ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_width_precision(t_pf *z)
{
	z->f_zero = false;
	z->f_minus = false;
	z->f_space = false;
	z->f_plus = false;
	z->f_hash = false;
	z->width = 0;
	z->precision = -1;
}

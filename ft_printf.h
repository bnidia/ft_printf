/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnidia <bnidia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:13:17 by bnidia            #+#    #+#             */
/*   Updated: 2022/01/04 19:55:52 by bnidia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE_L "0123456789abcdef"
# define BASE_A "0123456789ABCDEF"
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	process_type_field(va_list ap, const char *s, int *s_i);
void	ft_realloc(void);
void	ft_s(const char *s);
void	ft_p(unsigned long long nbr);
void	ft_di(int nbr);
void	ft_hex(unsigned int nbr, int base, const char *base_);
int		g_len;
char	*g_str;
int		g_size;
#endif

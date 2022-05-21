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

int		ft_print_out(t_pf *z);
void	ft_itoa_base(t_pf *z, t_ull nbr, int base, const char *base_);
int		for_zero_put_empty_string(t_pf *z, unsigned int nbr);
void	reset_insignificant_values(t_pf *z, int signlen);
int		output_of_initial_spaces(t_pf *z, int numlen, int signlen);
int		output_of_zeros(t_pf *z, int numlen, int signlen);
int		output_of_finite_spaces(t_pf *z, int numlen, int signlen);

int	ft_x(t_pf *z, unsigned int nbr, char base_charset)
{
	int	numlen;
	int	signlen;

// обработка исключения с нулями
	// возвращает -1 при ошибке, 0 при нормальном завершении и строка найдена
	// возвращает 1 если условие не найдено, цифра не ноль
	if (for_zero_put_empty_string(z, nbr) <= 0)
		return (z->return_value);

// подсчет символов если есть знаки
	signlen = 0;
	if (z->f_hash)
		signlen += 2;
// подсчет длины строки
	numlen = (int)ft_numlen((t_ull)ft_abs_d(nbr), 16);

// сброс незначащих значений
	reset_insignificant_values(z, signlen);

// вывод лидирующих пробелов
	// если указана точность и ширина, при этом ширина больше точности,
	// выводить пробелы
	// и у нас нет ключа f_minus который указывает выводить слева
	if (output_of_initial_spaces(z, numlen, signlen) == -1)
		return (-1);

// вывод знаков + - или #
	if (z->f_hash && nbr !=0)
	{
		z->s[z->s_i++] = '0';
		z->s[z->s_i++] = base_charset;
	}

// подсчет и вывод нулей
	if (output_of_zeros(z, numlen, signlen) == -1)
		return (-1);

// обработка исключения на пробел
	if (z->f_space)
		z->s[z->s_i++] = ' ';

// вывод числа
	if (base_charset == 'x')
		ft_itoa_base(z, nbr, 16, "0123456789abcdef");
	else if (base_charset == 'X')
		ft_itoa_base(z, nbr, 16, "0123456789ABCDEF");

// вывод конечных пробелов
	if (output_of_finite_spaces(z, numlen, signlen) == -1)
		return (-1);

	return (0);
}


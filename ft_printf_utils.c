#include "ft_printf.h"

void	ft_s(char *str, const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		str[g_len++]='(';
		str[g_len++]='n';
		str[g_len++]='u';
		str[g_len++]='l';
		str[g_len++]='l';
		str[g_len++]=')';
		return;
	}
	while (s[i])
		str[g_len++] = s[i++];
}

void	ft_p(char *str, unsigned long long nbr)
{
	int 	i;
	unsigned long long temp;


	str[g_len++] = '0';
	str[g_len++] = 'x';
	i = 0;
	temp = nbr;
	while (temp > 0)
	{
		temp /= 16;
		i++;
	}
	temp = i;
	while (i > 0)
	{
		str[g_len + i] = BASE[nbr % 16];
		nbr /= 16;
		i--;
	}
	g_len += (int)temp;
}

void ft_di(char *str, int nbr)
{
	long long	nbr_long;
	int 		i;

	i = 0;
	nbr_long = nbr;
	if (nbr_long < 0)
	{
		str[g_len++] = '-';
		nbr_long *= -1;
	}
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	nbr = i;
	while (i >= 0)
	{
		str[g_len + i] = BASE[nbr_long % 10];
		nbr_long /= 10;
		i--;
	}
	g_len += nbr;
}
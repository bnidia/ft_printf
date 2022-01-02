#include "ft_printf.h"

void	ft_s(char *str, int *len, char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		str[*len++]='(';
		str[*len++]='n';
		str[*len++]='u';
		str[*len++]='l';
		str[*len++]='l';
		str[*len++]=')';
		return;
	}
	while (s[i])
	{
		str[*len] = s[i];
		*len++;
		i++;
	}
}

void	ft_p(char *str, int *len, unsigned long long nbr)
{
	char	ch;
	int 	i;
	unsigned long long temp;
	char base[16] = "0123456789abcdef";

	str[*len++] = '0';
	str[*len++] = 'x';
	i = 0;
	temp = nbr;
	while (temp > 0)
	{
		temp /= 16;
		i++;
	}
	temp = i;
	while (i >= 0)
	{
		str[*len + i] = nbr % 16;
		nbr /= 16;
		i--;
	}
	*len += temp;
}

void ft_di(char *str, size_t *len, int num)
{

}
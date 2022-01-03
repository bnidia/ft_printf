

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	process_type_field(char *str, int *len, va_list ap, char *s, size_t *s_i);
void	ft_realloc(char **str, size_t *size);
void	ft_s(char *str, int *len, char *s);
void	ft_p(char *str, int *len, unsigned long long nbr);
void 	ft_di(char *str, int *len, int num);

#endif

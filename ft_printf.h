

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE "0123456789abcdef"

# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	process_type_field(char *str, va_list ap, const char *s, size_t *s_i);
void	ft_realloc(char **str, size_t *size);
void	ft_s(char *str, const char *s);
void	ft_p(char *str, unsigned long long nbr);
void 	ft_di(char *str, int num);
int	g_len;


#endif

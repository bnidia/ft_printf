

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	process_type_field(char *str, size_t *len, va_list ap, char *s, size_t *s_i);
void	ft_realloc(char **str, size_t *size);

#endif

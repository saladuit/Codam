#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <stdarg.h>
struct s_format_data {
	int	width;
	int	precision;
	int	width_bzero;
	int	width_negative;
	int	return_value;
};
int		int_len(int n);
int		parse_flags(char **format, struct s_format_data *data, va_list args);
void	put_str(char *str, int len, struct s_format_data *data);
int		print_string(struct s_format_data *data, va_list list);
int		print_char(va_list list, struct s_format_data *data, int is_pct);
void	width_handler(struct s_format_data *data, char *str);
int		print_int(struct s_format_data *data, va_list list, int is_unsigned);
void	print_width(char c, int len, struct s_format_data *data);
char	*itoa_nbr_base(unsigned long long int nbr, char *base);
int		print_hexa(va_list list, struct s_format_data *data, char specifier);
void	string_to_upper(char **str);
int		print_pointer(va_list list, struct s_format_data *data);
int		strlen_pointer_address(char *str, struct s_format_data *data);
int		ft_printf(char *format, ...);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amace-ty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:09:32 by amace-ty          #+#    #+#             */
/*   Updated: 2019/10/12 13:18:39 by amace-ty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/get_next_line.h"
# include <stdarg.h>

# define STRJOIN new_str = str; str = ft_strjoin(temp, new_str); free(new_str);
# define ELSEONE new->flag_sharp = 0; new->flag_null = 0; str = ft_strnew(1);
# define ELSETWO str[0] = '0'; return (ft_uinteger_print(str, new));
# define ELSE else {ELSEONE; ELSETWO;}
# define INT_PLUS {i++; format++;}
# define INT_PLUS_TWO else if (*format) {ft_putchar(*format);res1++; format++;}
# define FLAG_SPACE if (new->flag_space) {i = 1; new->flag_space = 0;}
# define INT_I i = -1; hoba = ft_itoa(new->sobaka);
# define STR_T {t = str; str = ft_strjoin("0x", t); free(t);}
# define STR_T2 {free(new_str); new_str = check_flags_width_two(str, new);}
# define NUM ft_putstr(dlc_str); num = ft_strlen(dlc_str); free(dlc_str);
# define IF_X {temp = "-"; *x *= -1; flag = 1;}
# define VA_ARG_X len = ft_bl_analise_float_part_two_len(new); number = NULL;
# define RETURN_VAL ft_putstr(number); ft_memdel((void**)&number);return(value);

# define MANCOLOUR M1 M2 M3 M4 M5 M6 M7 M8 M9 M10 M11 M12 M13 M14 M15 M16
# define M1 "\e[0;30mFR_BLACK\e[0;0m\n\e[40;0mBG_BLACK\e[0;0m\n"
# define M2 "\e[0;31mFR_RED\e[0;0m\n\e[41;0mBG_RED\e[0;0m\n"
# define M3 "\e[0;32mFR_GREEN\e[0;0m\n\e[42;0mBG_GREEN\e[0;0m\n"
# define M4 "\e[0;33mFR_YELLOW\e[0;0m\n\e[43;0mBG_YELLOW\e[0;0m\n"
# define M5 "\e[0;34mFR_BLUE\e[0;0m\n\e[44;0mBG_BLUE\e[0;0m\n"
# define M6 "\e[0;35mFR_MAGENTA\e[0;0m\n\e[45;0mBG_MAGENTA\e[0;0m\n"
# define M7 "\e[0;36mFR_CYAN\e[0;0m\n\e[46;0mBG_CYAN\e[0;0m\n"
# define M8 "\e[0;37mFR_WHITE\e[0;0m\n\e[47;0mBG_WHITE\e[0;0m\n"
# define M9 "\e[0;90mFR_BBLACK\e[0;0m\n\e[100;0mBG_BBLACK\e[0;0m\n"
# define M10 "\e[0;91mFR_BRED\e[0;0m\n\e[101;0mBG_BRED\e[0;0m\n"
# define M11 "\e[0;92mFR_BGREEN\n\e[102;0mBG_BGREEN\e[0;0m\n"
# define M12 "\e[0;93mFR_BYELLOW\n\e[103;0mBG_BYELLOW\e[0;0m\n"
# define M13 "\e[0;94mFR_BBLUE\n\e[104;0mBG_BBLUE\e[0;0m\n"
# define M14 "\e[0;95mFR_BMAGENTA\n\e[105;0mBG_BMAGENTA\e[0;0m\n"
# define M15 "\e[0;96mFR_BCYAN\n\e[106;0mBG_BCYAN\e[0;0m\n"
# define M16 "\e[0;97mFR_BWHITE\n\e[107;0mBG_BWHITE\e[0;0m\n"

# define FR_BLACK "\e[0;30m"
# define BG_BLACK "\e[40;0m"
# define FR_RED "\e[0;31m"
# define BG_RED "\e[41;0m"
# define FR_GREEN "\e[0;32m"
# define BG_GREEN "\e[42;0m"
# define FR_YELLOW "\e[0;33m"
# define BG_YELLOW "\e[43;0m"
# define FR_BLUE "\e[0;34m"
# define BG_BLUE "\e[44;0m"
# define FR_MAGENTA "\e[0;35m"
# define BG_MAGENTA "\e[45;0m"
# define FR_CYAN "\e[0;36m"
# define BG_CYAN "\e[46;0m"
# define FR_WHITE "\e[0;37m"
# define BG_WHITE "\e[47;0m"
# define DEFAULT "\e[0;0m"

# define FR_BBLACK "\e[0;90m"
# define BG_BBLACK "\e[100;0m"
# define FR_BRED "\e[0;91m"
# define BG_BRED "\e[101;0m"
# define FR_BGREEN "\e[0;92m"
# define BG_BGREEN "\e[102;0m"
# define FR_BYELLOW "\e[0;93m"
# define BG_BYELLOW "\e[103;0m"
# define FR_BBLUE "\e[0;94m"
# define BG_BBLUE "\e[104;0m"
# define FR_BMAGENTA "\e[0;95m"
# define BG_BMAGENTA "\e[105;0m"
# define FR_BCYAN "\e[0;96m"
# define BG_BCYAN "\e[106;0m"
# define FR_BWHITE "\e[0;97m"
# define BG_BWHITE "\e[107;0m"

# define GG "(╮°-°)┳┳\n    GG\n( ╯°□°)╯┻┻\n"
# define MEOW "cat"

typedef struct		s_print
{
	char			*size;
	char			type;
	int				width;
	int				flag_width;
	int				accuracy;
	int				flag_accuracy;
	int				flag_minus;
	int				flag_plus;
	int				flag_null;
	int				flag_space;
	int				flag_sharp;
	int				flag_otr_i;
	int				sobaka;
	struct s_print	*next;
}					t_print;

t_print				*ft_lstnew_ft_printf(void);
int					ft_printf(char *format, ...);
int					ft_check_one(char *str);
int					ft_check_two(char *format, va_list ap);
int					ft_analise(va_list ap, int res, t_print *new);
char				*ft_itoa_base(int notation, int up_or_down);
int					ft_power(unsigned long nb, int notation);
int					ft_integer(va_list ap, t_print *new);
int					ft_h_integer(va_list ap, t_print *new);
int					ft_hh_integer(va_list ap, t_print *new);
int					ft_l_integer(va_list ap, t_print *new);
int					ft_ll_integer(va_list ap, t_print *new);
int					ft_string(va_list ap, t_print *new);
int					ft_uinteger(va_list ap, t_print *new);
char				*ft_uinteger_2(unsigned int num);
int					ft_h_uinteger(va_list ap, t_print *new);
int					ft_hh_uinteger(va_list ap, t_print *new);
int					ft_ll_uinteger(va_list ap, t_print *new);
int					ft_l_uinteger(va_list ap, t_print *new);
int					ft_octal(va_list ap, t_print *new);
int					ft_h_octal(va_list ap, t_print *new);
int					ft_hh_octal(va_list ap, t_print *new);
int					ft_l_octal(va_list ap, t_print *new);
int					ft_ll_octal(va_list ap, t_print *new);
int					ft_upx(va_list ap, t_print *new);
int					ft_hh_upx(va_list ap, t_print *new);
int					ft_h_upx(va_list ap, t_print *new);
int					ft_l_upx(va_list ap, t_print *new);
int					ft_ll_upx(va_list ap, t_print *new);
int					ft_x(va_list ap, t_print *new);
int					ft_hh_x(va_list ap, t_print *new);
int					ft_h_x(va_list ap, t_print *new);
int					ft_l_x(va_list ap, t_print *new);
int					ft_ll_x(va_list ap, t_print *new);
char				*ft_float_tochka(double *x, t_print *new, char **number);
char				*stack(long double x, int value);
int					ft_analise_float_accuracy_null(double x, int value,
						t_print *new);
char				*float_flags(char *number, t_print *new, int *value);
int					ft_analise_float(va_list ap, t_print *new);
char				*stack_part_two_while(int power, double x, char *number);
char				*ft_float_tochka_part_two(double x, int flag, char *number);
void				ft_put_long(long n);
int					ft_infinity_float_l(double x);
int					long_x(long double *x);
char				*float_flags_part_two(t_print *new, char *number, char ch);
int					ft_analise_float_part_two_len(t_print *new);
void				ft_float_put_part_two(char **number, int null,
						long long num);
void				ft_float_put(long long z, int len, char **number);
char				*ft_float_circle(double x, int len, char **number);
char				*ft_bl_float_tochka(long double *x, t_print *new,
						char *number);
int					ft_bl_analise_float_accuracy_null(long double x, int value,
						t_print *new);
char				*float_bl_flags(char *number, t_print *new, int *value);
int					ft_bl_analise_float(va_list ap, t_print *new);
char				*stack_bl_part_two_while(int power, long double x,
						char *number);
char				*ft_bl_float_tochka_part_two(long double x, int flag,
						char *number);
void				ft_bl_put_longlong(long long int n);
int					ft_bl_infinity_float_l(long double x);
char				*float_bl_flags_part_two(t_print *new, char *number,
						char ch);
int					ft_bl_analise_float_part_two_len(t_print *new);
void				ft_bl_float_put_part_two(char **number, int null,
						long long num);
void				ft_bl_float_put(long long z, int len, char **number);
char				*ft_bl_float_circle(long double x, int len, char **number);
int					ft_analise_simvol(va_list ap, t_print *new);
char				*ft_check_char_flag_minus(char c, char *str_width,
						t_print *new);
int					ft_analise_procent(t_print *new);
int					ft_integer_print(char *str, t_print *new);
char				*check_flag_sharp(char *str, t_print *new);
int					ft_uinteger_print(char *str, t_print *new);
int					ft_iprint_null(t_print *new);
int					ft_print_string(char *str, t_print *new);
int					ft_sobachiy_null(t_print *new);
char				*ft_litoa(long int n);
char				*ft_llitoa(long long int n);
int					ft_lpower(long int n);
int					ft_llpower(long long int n);
int					ft_power_ll(unsigned long long int nb, int notation);
int					ft_power_h(unsigned short int nb, int notation);
int					ft_power_hh(unsigned char nb, int notation);
int					ft_power_l(unsigned long int nb, int notation);
int					ft_lupower(unsigned long int n);
void				ft_hobaflags(t_print *new);
int					ft_analise_jd(va_list ap);
int					ft_analise_zd(va_list ap);
void				ft_check_accuracy_two(t_print *new, va_list ap);
int					ft_check_width(char *format, va_list ap, t_print *new);
int					while_flags(char *format, t_print *new);
int					ft_check_accuracy(char *format, va_list ap, t_print *new);
int					ft_check_size(char *format, t_print *new);
int					ft_check_type(char *format, t_print *new);
int					ft_while_tchk(t_print *new, char *str, int flag);
int					ft_check_star(char *format, va_list ap, t_print *new);
char				*ft_analise_z_two(t_print *new);
int					ft_analise_z(t_print *new);
int					ft_analise_n(va_list ap, int res);
int					ft_analise_two(va_list ap, t_print *new, char c);
int					ft_print_pointer(char *str, t_print *new);
char				*check_flags_integer_width(char *str, t_print *new);
char				*ft_width_for_minus_and_zero(char *str, t_print *new);
int					ft_analise_pointer(va_list ap, t_print *new);
int					check_snull_o(t_print *new);
char				*ft_uinteger_accuracy(char *temp, t_print *new);
char				*check_flags_width(char *temp4, t_print *new);
char				*check_flags_width_three(char *str, t_print *new);
char				*check_flags_width_two(char *str, t_print *new);
char				*ft_uinteger_minus(char *temp, t_print *new);

#endif

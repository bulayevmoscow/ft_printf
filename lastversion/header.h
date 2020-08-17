/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:52:28 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 14:03:50 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define PF_HH 1
# define PF_H 2
# define PF_L 3
# define PF_LL 4
# define PF_J 5
# define PF_Z 6
# define PF_T 7
# define PF_Y 8

typedef struct		s_model
{
	char			*str;
	int				value;
	struct s_model	*next;
}					t_model;

typedef struct		s_info
{
	int				flag_space;
	int				flag_minus;
	int				flag_plus;
	int				flag_oct;
	int				flag_zero;
	int				width;
	int				width_mod;
	int				precision;
	int				precision_mod;
	int				length;
	char			specifier;

}					t_info;

t_info				info_init();

t_model				*g_model;

int					ft_printf(const char *input, ...);
int					parse_main(const char *str, va_list arg_list);
int					parse_sec(const char *str, va_list arg_list);
int					parse_pros(char *str, va_list arg_list);
t_model				*push_mopdel(const char *str, t_model *g_model, int isnew);
int					parse_percent(const char *str);
int					check_manager(char *str, t_info *info);
int					check_flag(char *str, t_info *info);
int					check_width(char *str, t_info *info);
int					check_precision(const char *str, t_info *info);
int					check_length(const char *str, t_info *info);
int					check_length_ext(const char *str, t_info *info);
int					check_specifier(const char *str, t_info *info);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				ft_putchar(char c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void				ft_putchar_fd(char c, int fd);
void				stars_manager(t_info *info, va_list arg_list);
int					pusher_manager(t_info *info, va_list arg_list);
int					pusher_percent(t_info *info, va_list arg_list);
int					pusher_c(t_info *info, va_list arg_list);
int					pusher_string(t_info *info, va_list arg_list);
char				*pusher_string_width(t_info *info, char *str);
int					pusher_d_i(t_info *info, va_list arg_list);
int					pusher_d_i_2(t_info *info, char *str);
char				*pusher_d_i_2_precision(t_info *info, char *str);
int					pusher_u(t_info *info, va_list arg_list);
int					pusher_f(t_info *info, va_list arg_list);
int					pusher_f_split(long double *in, long double *de,
t_info *info, va_list arg_list);
void				round_float(long double *nbr, int precision);
int					pusher_f_join(double long nbr1, char *nbr2, t_info *info);
int					pusher_f_join_2(char pos, char *nbr);
char				*ft_strmaker(int space, int size);
static int			ft_itoa_external_len(long long int n);
char				*ft_itoa_external(long long int n);
static int			ft_itoa_external_unsgn_len(unsigned long long int n);
char				*ft_itoa_external_unsgn(unsigned long long int n);
int					print_result(void);
void				debug_struct(void);
void				remove_struct(void);
char 				*ft_str_concat(char *str1, int d1,char *str2, int d2);

#endif

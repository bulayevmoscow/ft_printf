/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemignatev <artemignatev@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:52:28 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/16 03:03:27 by artemignate      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define pf_hh 1
# define pf_h 2
# define pf_l 3
# define pf_ll 4
# define pf_j 5
# define pf_z 6
# define pf_t 7
# define pf_L 8

typedef struct		s_model
{
	char			*str;
	int				value;
	struct s_model	*next;
} 					t_model;

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

t_model				*model;

int					ft_printf(const char *input, ...);
int					parseMain(const char *str, va_list arg_list);
int					parseSec(const char *str, va_list arg_list);
int					parsePros(char *str, va_list arg_list);
t_model				*pushModel(const char *str, t_model *model, int isNew);
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
void				debugStruct(void);
void				removeStruct(void);

#endif

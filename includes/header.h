/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghar <aghar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:52:28 by artemignate       #+#    #+#             */
/*   Updated: 2020/08/21 17:23:13 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

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
	int				len;
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
	int				pre;
	int				precision_mod;
	int				length;
	char			specifier;

}					t_info;

t_info				info_init();

t_model				*g_model;

int					ft_printf(const char *input, ...);
int					parse_main(const char *str, va_list arg_list);
int					parse_sec(const char *str, va_list arg_list);
char				*ft_spec_trans_xx(unsigned long int a, int os);
int					parse_pros(char *str, va_list arg_list);
t_model				*push_mopdel(const char *str, t_model *g_model,
int isnew, int len);
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
char				*ft_spec_trans_x(unsigned long int a, int os);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void				ft_putchar_fd(char c, int fd);
void				pusher_x_xx_2(t_info *info, char **str);
void				stars_manager(t_info *info, va_list arg_list);
int					pusher_manager(t_info *info, va_list arg_list);
int					pusher_percent(t_info *info);
void				pusher_c(t_info *info, va_list arg_list);
void				pusher_string(t_info *info, va_list arg_list);
char				*pusher_string_width(t_info *info, char *str);
int					pusher_d_i(t_info *info, va_list arg_list);
int					pusher_d_i_2(t_info *info, char *str);
void				pusher_d_i_2_precision(t_info *info, char **str);
int					pusher_u(t_info *info, va_list arg_list);
int					pusher_f(t_info *info, va_list arg_list);
int					pusher_f_split(long double *in, long double *de,
t_info *info, va_list arg_list);
void				round_float(long double *nbr, int precision);
int					pusher_f_join(double long nbr1, char *nbr2, t_info *info);
int					pusher_f_join_2(char pos, char **nbr);
char				*ft_strmaker(int space, int size);
int					ft_itoa_external_len(long long int n);
char				*ft_itoa_external(long long int n);
int					ft_itoa_external_unsgn_len(unsigned long long int n);
char				*ft_itoa_external_unsgn(unsigned long long int n);
int					print_result(void);
char				*ft_str_concat(char *str1, int d1, char *str2, int d2);
void				remove_struct(void);
char				*ft_str_concat(char *str1, int d1, char *str2, int d2);
int					pusher_x(t_info *info, va_list arg_list);
int					pusher_o(t_info *info, va_list arg_list);
int					pusher_xx(t_info *info, va_list arg_list);
char				*ft_spec_trans_x(unsigned long int a, int os);
char				*ft_spec_trans_xx(unsigned long int a, int os);
int					pusher_p(t_info *info, va_list arg_list);
void				pusher_string(t_info *info, va_list arg_list);
char				*pusher_string_width(t_info *info, char *str);
char				*ft_strmaker(int space, int size);
int					pusher_u(t_info *info, va_list arg_list);
char				*ft_back_string(int *str, int x, int a);

#endif

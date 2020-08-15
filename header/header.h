//
// Created by paada on 30.07.2020.
//
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "../libft/libft.h"

#ifndef TEST1_HEADER_H
#define TEST1_HEADER_H

typedef struct s_model
{
	char *str;
	int value;
	struct s_model *next;
} t_model;

typedef struct s_info
{
	int flag_space;
	int flag_minus;
	int flag_plus;
	int flag_oct;
	int flag_zero;

	int width;
	int width_mod;
	int precision;
	int precision_mod;
	int length;
	char specifier;

} t_info;
//info init
t_info info_init();

t_model *model;
int debug;

int ft_printf(const char *input, ...);


int parseMain(const char *str, va_list arg_list);

int parseSec(const char *str, va_list arg_list);

int parsePros(char *str, va_list arg_list);

t_model *pushModel(const char *str, t_model *model, int isNew);

//parse_percent
int parse_percent(const char *str);
// Checker
int check_manager(char *str, t_info *info);
int check_flag(char *str, t_info *info);
int check_width(char *str, t_info *info);
int check_precision(const char *str, t_info *info);
int check_length(const char *str, t_info *info);
int check_length_ext(const char *str, t_info *info);
int check_specifier(const char *str, t_info *info);
//Stars
void stars_manager(t_info *info, va_list arg_list);
//Pusher
int pusher_manager(t_info *info,va_list arg_list);
int pusher_percent(t_info *info, va_list arg_list);
int pusher_c(t_info *info, va_list arg_list);
int pusher_string(t_info *info, va_list arg_list);
char *pusher_string_width(t_info *info, char *str);
int pusher_d_i(t_info *info, va_list arg_list);
int pusher_d_i_2(t_info *info, char *str);
char *pusher_d_i_2_precision(t_info *info, char *str);
int pusher_u(t_info *info, va_list arg_list);
int pusher_f(t_info *info, va_list arg_list);
int pusher_f_split(long double *in,long double *de, t_info *info, va_list arg_list);
void round_float(long double *nbr, int precision);
int pusher_f_join(double long nbr1, char *nbr2, t_info *info);
//String Width Maker
char *ft_strmaker(int space, int size);
//Add to lib
static int		ft_itoa_external_len(long long int n);
char			*ft_itoa_external(long long int n);
static int		ft_itoa_external_unsgn_len(unsigned long long int n);
char			*ft_itoa_external_unsgn(unsigned long long int n);


int print_result();
void debugStruct();
void removeStruct();




#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define pf_hh 1
#define pf_h 2
#define pf_l 3
#define pf_ll 4
#define pf_j 5
#define pf_z 6
#define pf_t 7
#define pf_L 8

#endif //TEST1_HEADER_H

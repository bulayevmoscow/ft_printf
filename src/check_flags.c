#include "../header/header.h"

int check_manager(char *str, t_info *info)
{
	int len;
	int spec;

	len = 1;
	len += check_flag(str, info);
	len += check_width(str + len, info);
	len += check_precision(str + len, info);
	len += check_length(str + len, info);
	spec = check_specifier(str + len, info);
	if (spec == -1) {
		printf("\n[check_manager]Spec not found \"%s\"", str + len);
		pushModel(ft_strsub(str, 0, 1), model, 4);
		info->specifier = 0;
		return (len);
	}
//	printf("\n[check_manager]Spec was found \"%s\"", str + (spec + len));
//
	printf("\n[s_info] [Length] = %d [T_Len] = %zu [ ] = %d;[-] = %d;[+] = %d;[#] = %d;[0] = %d;", len, ft_strlen(str),
		   info->flag_space,
		   info->flag_minus, info->flag_plus, info->flag_oct, info->flag_zero);
	printf("\n[s_info] [\"%d\"Width] = %d [\"%d\"Precision] = %d [Length] = %d [Specifier] = %c",
		   info->width_mod,
		   info->width,
		   info->precision_mod, info->precision, info->length, info->specifier);
	return spec + len;


}


int check_flag(char *str, t_info *info)
{

	int len = 0;
	printf("\n[check_flag] Get string %s", str);

	while (*(str + len + 1)) {
		if (*(str + len + 1) == ' ')
			info->flag_space = 1;
		else if (*(str + len + 1) == '-')
			info->flag_minus = 1;
		else if (*(str + len + 1) == '+')
			info->flag_plus = 1;
		else if (*(str + len + 1) == '#')
			info->flag_oct = 1;
		else if (*(str + len + 1) == '0')
			info->flag_zero = 1;
		else
			break;
		len++;
	}


	return len;
}

int check_width(char *str, t_info *info)
{
	int width;
	int len;
	printf("\n[check_width] Get string %s", str);
	len = 0;
	if (*str == '*') {
		info->width_mod = 2;
		return ++len;
	}
	width = ft_atoi(str + len);
//	printf("\n[check_width] Width %d", width);
	info->width = width;
	if (width == 0)
		return (0);
	else
		while (ft_isdigit(*(str + len)))
			len++;
	return len;
}

int check_precision(const char *str, t_info *info)
{
	int len;
	int precision;

	len = 0;
	precision = 0;
	if (*str == '.') {
		len = 1;
		if (!ft_isdigit(*(str + 1))){
			info->precision_mod = 1;
		}
		if (*(str + 1) == '*'){
			info->precision_mod = 2;
			return ++len;
		}
		precision = ft_atoi(str + len);
		while (ft_isdigit(*(str + len)))
			len++;
	} else {
	    info->precision = -1;
        return 0;
	}
	if (precision != 0)
		info->precision = precision;
	else
		info->precision_mod = 1;

//	printf("\n[check_precision] Precision %d", precision);
	return len;
}

int check_length(const char *str, t_info *info)
{
//	printf("\n[check_length] Get string %s", str);
	if (*str == 'j')
		info->length = pf_j;
	if (*str == 'z')
		info->length = pf_z;
	if (*str == 't')
		info->length = pf_t;
	if (*str == 'L')
		info->length = pf_L;
	if (info->length != 0)
		return (1);

	return (check_length_ext(str, info));
}

int check_length_ext(const char *str, t_info *info)
{
	if (*str == 'h') {
		if (*(str + 1) == 'h') {
			info->length = pf_hh;
			return (2);
		}
		info->length = pf_h;
		return (1);
	}
	if (*str == 'l') {
		if (*(str + 1) == 'l') {
			info->length = pf_ll;
			return (2);
		}
		info->length = pf_l;
		return (1);
	}
	return (0);
}

int check_specifier(const char *str, t_info *info)
{
//	printf("\n[check_length] Get string %s", str);
	if (*(str) == 'd' || *(str) == 'i' || *(str) == 'u' || *(str) == 'o' || \
    *(str) == 'x' || *(str) == 'X' || *(str) == 'f' || *(str) == 'F' || \
    *(str) == 'E' || *(str) == 'e' || *(str) == 'g' || *(str) == 'G' || \
    *(str) == 'a' || *(str) == 'A' || *(str) == 'c' || *(str) == 's' || \
    *(str) == 'p' || *(str) == 'n' || *(str) == '%') {
		info->specifier = *str;
	} else if (*(str) == '%') {
		return -2;
	} else {
		return (-1);
	}


	return (1);
}

#include "../header/header.h"

int pusher_manager(t_info *info, va_list arg_list)
{
	if (info->specifier == 'c')
		pusher_c(info, arg_list);
	if (info->specifier == '%')
		pusher_percent(info, arg_list);
	if (info->specifier == 's')
		pusher_string(info, arg_list);
	if (info->specifier == 'd' || info->specifier == 'i')
		pusher_d_i(info, arg_list);

	return 0;
}

int pusher_c(t_info *info, va_list arg_list)
{
	char *str;

	str = ft_strnew(2);
	if (str == NULL) {
		return (-1);
	}
	*str = va_arg(arg_list, int);
	pushModel(str, model, 125);

}

int pusher_percent(t_info *info, va_list arg_list)
{
	char *str;

	str = ft_strnew(2);
	if (str == NULL) {
		return (-1);
	}
	*str = '%';
	pushModel(str, model, 125);

}

int pusher_string(t_info *info, va_list arg_list)
{
	char *str;

	if (info->width_mod == 2) {
		info->width = va_arg(arg_list, int);
		info->width_mod = 0;
		printf("\ninfo->width_mod == 2");
	}
	if (info->precision_mod == 2) {
		info->precision = va_arg(arg_list, int);
		info->precision_mod = 0;
		printf("\tinfo->precision_mod == 2");
	}

	if (info->precision_mod == 1)
		str = ft_strnew(0);
	if (info->precision_mod == 0 && info->precision != -1)
		str = ft_strsub(va_arg(arg_list, char *), 0, info->precision);
	if (info->precision_mod == 0 && info->precision == -1)
		str = ft_strdup(va_arg(arg_list, char *));

	if (info->width)
		str = pusher_string_width(info, str);


	printf("\n[pusher_string]precision = %s", str);

	pushModel(str, model, 125);


	printf("\n\n[s_info][ ] = %d;[-] = %d;[+] = %d;[#] = %d;[0] = %d;", info->flag_space,
		   info->flag_minus, info->flag_plus, info->flag_oct, info->flag_zero);
	printf("\n[s_info] [\"%d\"Width] = %d [\"%d\"Precision] = %d [Length] = %d [Specifier] = %c",
		   info->width_mod,
		   info->width,
		   info->precision_mod, info->precision, info->length, info->specifier);

}

char *pusher_string_width(t_info *info, char *str)
{
	int len;
	char *str1;
	int i;

	i = -1;
	if (ft_strlen(str) > info->width)
		return str;
	len = info->width;
	str1 = ft_strmaker((info->flag_zero), len);
	if (!str1)
		return NULL;
	while (str[++i] && info->flag_minus)
		str1[i] = str[i];
	i--;
	while (str[++i] && !info->flag_minus)
		str1[len - ft_strlen(str) + i] = str[i];
	free(str);
	printf("\nLen = %d, str %s", len, str1);
	return (str1);
}

char *ft_strmaker(int space, int size)
{
	char *str;
	int i;

	i = 0;
	str = (char *) malloc((size + 1) * sizeof(char));
	if (!str)
		return NULL;

	while (i != size) {
		str[i] = (space) ? '0' : ' ';
		i++;
	}
	str[size] = '\0';
	return str;

}

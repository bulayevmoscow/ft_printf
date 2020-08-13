#include "../header/header.h"


int parseMain(const char *str, va_list arg_list)
{
	int ft_printf;

	if (debug)
		printf(ANSI_COLOR_YELLOW "\n[parseMain]Get str \"%s\""ANSI_COLOR_RESET, str);
	model = pushModel(str, NULL, 1);


	if (debug)
		printf("\n[parseMain]Parse result is %d", parseSec(str, arg_list));
	else
		parseSec(str, arg_list);


	debugStruct(model);
	ft_printf = print_result();
	removeStruct();
	return (ft_printf);
}

int print_result(){
	int len;
	int i;
	t_model *model1 = model;
	model1 = model1->next;

	len = 0;
	while (model1) {
		i = 0;
		while (model1->str[i])
			ft_putchar(model1->str[i++]);
		len += i;
		if (model1->next == NULL)
			break;
		model1 = model1->next;
	}
	return len;
}



int parseSec(const char *str, va_list arg_list)
{
	printf(ANSI_COLOR_BLUE "\n[parse]Get str \"%s\""ANSI_COLOR_RESET, str);

	int len[2];

	len[0] = 0;
	len[1] = 0;
	while (str[(len[1] + len[0])]) {
		if (str[len[1] + len[0]] == '%') {
			pushModel(ft_strsub(str, len[0], len[1]), model, 02);
			if (debug)
				printf("\nFind! len[0] = %d, len[1] = %d", len[0], len[1]);
			len[1] += parsePros((char *) str + (len[0] + len[1]), arg_list);
			len[0] += len[1];
			len[1] = 0;
		} else
			len[1]++;
	}


	pushModel(ft_strsub(str, len[0], len[1]), model, 022);

	if (debug)
		printf("\n[parse]Result is %d", len[1]);

}


int parsePros(char *str, va_list arg_list)
{
	int len;
	t_info test;

	test = info_init();
	len = check_manager(str, &test);
	pusher_manager(&test, arg_list);
	return len;

//	if (debug)
//		printf("\n[parsePros]Get \"%s\"", str);
//	len = 2;
//	if (*(str + 1) == '%') {
//		return (parse_percent(str));
//	} else
//
//		return 1;

}


t_model *pushModel(const char *str, t_model *model, int isNew)
{
	if (debug)
		printf("\n[pushModel] get str = \"%s\"", str);
	t_model *model1;

	model1 = (t_model *) malloc(sizeof(t_model));
	model1->value = isNew;
	model1->str = (char *) str;
	model1->next = NULL;
	if (isNew == 1) {
		return model1;
	}
	while (model->next != NULL)
		model = (t_model *) model->next;
	model->next = (t_model *) model1;
	return model1;


}

void debugStruct()
{
	int i = 0;
	t_model *model1;
	model1 = model;
	while (model1) {
		printf(ANSI_COLOR_RED  "\nModel[%d] Value is %d String is\"%s\"" ANSI_COLOR_RESET,
			   i,
			   model1->value,
			   model1->str);
		if (model1->next == NULL)
			break;
		model1 = model1->next;
		i++;
	}
	model1 = model;
	model1 = model1->next;
	printf(ANSI_COLOR_MAGENTA);
	printf("\n\n");
	while (model1) {
		printf("%s", model1->str);
		if (model1->next == NULL)
			break;
		model1 = (t_model *) model1->next;
	}

	printf("\n");
	printf(ANSI_COLOR_RESET);
}


void removeStruct()
{
	t_model *model1 = model;
	t_model *buffer;
	model1 = model1->next;
	free(model);
	while (model1->value) {
//		printf("\nRemove str [%s] [value = %d]", model1->str, model1->value);
		free(model1->str);
		buffer = model1->next;
		free(model1);
		model1 = buffer;
		if (buffer->next == NULL) {
//			printf("\nRemove str [%s] [value = %d]", model1->str, model1->value);
			free(model1->str);

			buffer = model1->next;
			free(model1);
			model1 = buffer;
			break;

		}

	}


}























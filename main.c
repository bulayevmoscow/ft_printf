
#include "header/header.h"

int main()
{
	int a1, a2;
	void *test1;
	char string[] = "\n%.10p при-вет\"";
	char test[5];
	test[0] = ' ';

	test1 = string;
//	a1 = ft_printf(&string, 105, 5,  "12345");
	a1 = ft_printf("test string %2s", "string");
	a2 = printf(&string, 105, 5,  "12345");
	a2 = printf(test, 105, 5,  "12345");
	printf(ANSI_COLOR_GREEN);
	if (a1 == a2)
		printf("\nУспех = %d", a1);
	else
		printf("Неудача a1 = %d, a2 = %d", a1, a2);

	return 0;

}


#include "header.h"

int main()
{
	int a1, a2;
//	char string[] = "\n[1]test string %d!";
	char string[] = "(\"hello, world!\")";

	double test4;
	test4 = -12.23;

	a1 = ft_printf("%-8.5i", 34);
//	a2 = printf("%.03s", NULL);




	if (a1 == a2) {
		printf(ANSI_COLOR_GREEN);
		printf("\nУспех = %d", a1);
	} else {
		printf(ANSI_COLOR_RED);
		printf("\nНеудача a1 = %+d, a2 = %+d", a1, a2);
	}
	printf(ANSI_COLOR_RESET);

	return 0;


}


#include "header.h"

int main()
{
	int a1, a2;
//	char string[] = "\n[1]test string %d!";
	char string[] = "(\"hello, world!\")";

	double test4;
	test4 = -12.23;
//	00034

	a1 = ft_printf("%#-15.5x || %X  || %o || %100.5p", -5, -5 , -5, &a1);
	printf("\n");
	a2 = printf("%#-15.5x || %X  || %o || %100.5p", -5, -5 , -5, &a1);





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

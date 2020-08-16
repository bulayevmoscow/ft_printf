
#include "header/header.h"

int main()
{
	int a1, a2;
//	char string[] = "\n[1]test string %d!";
	char string[] = "\n[1]test string %0120.3f!";

	double test4;
	test4 = -12.23;

	a1 = ft_printf("%.6i", -3);
	printf(ANSI_COLOR_CYAN);
	a2 = printf(string, test4);


	if (a1 == a2) {
		printf(ANSI_COLOR_GREEN);
		printf("\nУспех = %d", a1);
	} else {
		printf(ANSI_COLOR_RED);
		printf("\nНеудача a1 = %+d, a2 = %-d", a1, a2);
	}
	printf(ANSI_COLOR_RESET);

	return 0;


}

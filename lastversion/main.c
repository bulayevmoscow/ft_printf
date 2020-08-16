
#include "header.h"

int main()
{
	int testGH;
	int a1, a2;
	char string[] = "\n[1]test string %-20f!";
	char test[5];
	test[0] = ' ';
	unsigned long long int test3;
	test3 = 500;
	double test4;
	test4 = 12;

	a1 = ft_printf(string, test4);
	printf(ANSI_COLOR_CYAN);
	a2 = printf(string, test4);


	if (a1 == a2) {
		printf(ANSI_COLOR_GREEN);
		printf("\nУспех = %d", a1);
	} else {
		printf(ANSI_COLOR_RED);
		printf("\nНеудача a1 = %d, a2 = %d", a1, a2);
	}
	printf(ANSI_COLOR_RESET);

	return 0;


}

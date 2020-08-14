
#include "header/header.h"

int main()
{
	int testGH;
	int a1, a2;
	char string[] = "\n[1]test string %020.5u!";
	char test[5];
	test[0] = ' ';
	unsigned long long int test3;
	test3 = 500;
	unsigned long long test4;
	test4 = (unsigned int)test3;

	a1 = ft_printf(string, test4 + 1);
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

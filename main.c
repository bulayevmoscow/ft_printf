
#include "header/header.h"

int main()
{
	int a1, a2;
	char string[] = "\n[1]test string %+50d !";
	char test[5];
	test[0] = ' ';


	a1 = ft_printf(string, 201);
	printf(ANSI_COLOR_CYAN);
	a2 = printf(string, 200);


	if (a1 == a2) {
		printf(ANSI_COLOR_GREEN);
		printf("\nУспех = %d", a1);
	} else {
		printf(ANSI_COLOR_RED);
		printf("\nНеудача a1 = %d, a2 = %d", a1, a2);
	}
	printf(ANSI_COLOR_RESET);

	long long int test4 = 2666666;
//    test4 = (int)test4;
	printf("\nkekw%d %d", test4, (short int) test4);

	return 0;


}

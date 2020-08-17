
#include "header.h"

int main()
{
	int a1, a2;
//	char string[] = "\n[1]test string %d!";
	char string[] = "%6.10d";

	double test4;
	test4 = -12.23;
//	00034



//	a1 = ft_printf(string, -500);
	printf("\n");
	a2 = printf(string, -500 + 1);





	if (a1 == a2) {
		printf(ANSI_COLOR_GREEN);
		printf("\nУспех = %d", a1);
	} else {
		printf(ANSI_COLOR_RED);
		printf("\nНеудача a1 = %+d, a2 = %+d", a1, a2);
	}
	printf(ANSI_COLOR_RESET);
	printf("\n%s\n", ft_str_concat("Hello", 0, "World" , 0));
	return 0;


}

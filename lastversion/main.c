
#include "header.h"

int main()
{
	int a1, a2;
//	char string[] = "\n[1]test string %d!";
//	char string[] = "%#10.122f";

	double test4;
	test4 = -12.23;
//	00034


//test("%c", '
	a1 = ft_printf("@moulitest: %#.d %#.0o", 0, 0);
//	a1 = ft_printf("%03.2d", 0);
	// a1 = ft_printf("@moulitest: %#.o %#.0o", 0, 0);
	printf("\n");
	printf(ANSI_COLOR_GREEN);
	a2 = printf("@moulitest: %#.d %#.0o", 0, 0);
//	a2 = printf("%");





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

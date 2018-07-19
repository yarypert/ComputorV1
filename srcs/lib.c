#include "../includes/computor.h"

void	error(char *str)
{
	printf("\033[1;31m%s\n\033[0m", str);
	exit(0);
}

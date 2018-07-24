#include "../includes/computor.h"

void	init_struct(t_poly *p, char *str)
{
	p->e = str;
	p->disc = 0;
	p->deg = 0;
	p->a = 0;
	p->b = 0;
	p->c = 0;
	p->sol1 = 0;
	p->sol2 = 0;
	p->delta = 0;
	p->x = NULL;
	p->cstr = NULL;
	p->cut = 0;
	p->exp = (int *)malloc(sizeof(int) * 3);
}

int		check_argv(char *str)
{
	int i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+' && str[i] != '*' && str[i] != '/' && str[i] != '=' && str[i] != '.' && str[i] != 'X' && str[i] != '^' && str[i] != ' ')
			return(1);
		i++;
	}
	return(0);
}


int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_argv(argv[1]) == 1)
			error("THere is unacceptable characters in your formula, check and resubmit please.");
		t_poly p;
		init_struct(&p, argv[1]);
		computor(&p);
	}
	else
		printf("%s\n", "Error, not enough arguments.");
	return 0;
}

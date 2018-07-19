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
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_poly p;
		init_struct(&p, argv[1]);
		computor(&p);
	}
	else
		printf("%s\n", "Error, not enough arguments.");
	return 0;
}

#include "../includes/computor.h"



double		get_value(t_poly *p, char c)
{
	int i = 0;
	int flag = 0;
	int j = 0;
	double ret;
	double signe = 1;
	while(p->e[i])
	{
		if (p->e[i] == 'X' && p->e[i + 1] == '^' && p->e[i + 2] == c)
		{
			j = i;
			while(j >= 0)
			{
				if (p->e[j] == ' ' || j == 0)
				{
					flag++;
				}
				if (flag == 3 && j > 0)
				{
					if (p->e[j - 1] == '-')
						signe = -1;
					ret = atof(p->e + (j + 1));
				}
				else if (flag == 3 && j == 0)
				ret = atof(p->e);
				j--;
			}
			j = 0;
		}
		i++;;
	}
	return(ret * signe);
}

void	get_degree(t_poly *p)
{
	int i = 0;
	while(p->e[i])
	{
		if (p->e[i] == '^')
		{
			if ((p->e[i + 1] - 48) >= p->deg)
				p->deg = atoi(p->e + (i + 1));
			if (p->deg > 2)
				error("The polynomial degree is strictly greater than 2, I can't solve.");
		}
		i++;;
	}
}

void	deg_two_sol(t_poly *p)
{
	double sol;
	double sol1;
	double sol2;
	printf("\na = %f, b = %f, c = %f\n",p->a, p->b,p->c);
	p->delta = (p->b * p->b) - 4 * p->a * p->c;
	printf("%f\n", p->delta);
	if (p->delta < 0)
		printf("%s\n", "No solutions");
	else if (p->delta == 0)
	{
		sol = -((double)p->b / (2 * (double)p->a));
		printf("%s\n", "one solution");
		printf("sol = \n%f", sol);
	}
	else if (p->delta > 0)
	{
		sol1 = -((p->b + sqrt(p->delta) ) / (2 * p->a));
		sol2 = -((p->b - sqrt(p->delta) ) / (2 * p->a));
		printf("%s\n", "two solutions");
		printf("\nsol1 = %f\n", sol1);
		printf("\nsol2 = %f\n", sol2);
	}
}


void	deg_one_sol(t_poly *p)
{
	double sol;
	printf("\na = %f, b = %f\n",p->a, p->b);
	sol = - (p->b / p->a);
	printf("\nsol = %f\n", sol);
}



void	decompose(t_poly *p)
{
	get_degree(p);
	printf("\ndegree = %d\n", p->deg);
	if (p->deg == 2)
	{
		p->a = get_value(p, '2');
		p->b = get_value(p, '1');
		p->c = get_value(p, '0');
		deg_two_sol(p);
	}
	else if (p->deg == 1)
	{
		p->a = get_value(p, '1');
		p->b = get_value(p, '0');
		deg_one_sol(p);
	}
	else if (p->deg == 0)
		p->a = get_value(p, 0);
}

void	computor(t_poly *p)
{
	decompose(p);
}

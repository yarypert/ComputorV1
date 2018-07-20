#include "../includes/computor.h"

void	count_exp(t_poly *p)
{
	int i = strlen(p->cstr);
	p->exp[0] = 0;
	p->exp[1] = 0;
	p->exp[2] = 0;
	while (i >= 0)
	{
		if (p->cstr[i] == 'X')
		{
			if (p->cstr[i + 1] == '^' && p->cstr[i + 2] == '2')
				p->exp[2]++;
			else if (p->cstr[i + 1] == '^' && p->cstr[i + 2] == '1')
				p->exp[1]++;
			else if (p->cstr[i + 1] == '^' && p->cstr[i + 2] == '0')
				p->exp[0]++;
		}
		i--;
	}
	printf("\n\n/////\nNombre d'expressions\n%d\n%d\n%d\n//////\n\n", p->exp[0], p->exp[1], p->exp[2]);
}




int		count_char(t_poly *p)
{
	int i = 0;
	int count = 0;
	while(p->e[i])
	{
		if (p->e[i] != ' ' && p->e[i] != '\t' && p->e[i] != '\n' && p->e[i] != '\v' && p->e[i] != '\f' &&p->e[i] != '\r')
		{
			if (p->e[i] == '+' || p->e[i] == '-' || p->e[i] == '*' || p->e[i] == '/' || p->e[i] == '=')
				count = count + 2;
			count++;
		}
		i++;
	}
	return (count);
}

void	*fill_str(t_poly *p)
{
	int i = 0;
	int j = 0;
	while (p->e[i])
	{
		if (p->e[i] != ' ' && p->e[i] != '\t' && p->e[i] != '\n' && p->e[i] != '\v' && p->e[i] != '\f' &&p->e[i] != '\r')
		{
			if (p->e[i] == '+' || p->e[i] == '-' || p->e[i] == '*' || p->e[i] == '/' || p->e[i] == '=')
			{
				p->cstr[j] = ' ';
				p->cstr[j + 1] = p->e[i];
			printf("%c", p->cstr[i]);
				p->cstr[j + 2] = ' ';
				j = j + 2;
			}
			else if (p->e[i] != '+' || p->e[i] != '-' || p->e[i] != '*' || p->e[i] != '/' || p->e[i] != '=')
				p->cstr[j] = p->e[i];
			j++;
		}
		i++;
	}
}

void	del_whitespaces(t_poly *p)
{
	int c;
	c = count_char(p);
	p->cstr = (char *)malloc(sizeof(char) * c + 1);
	fill_str(p);
	printf("%s\n", p->cstr);
}






void	create_tab0(t_poly *p)
{
	int		i;
	i = strlen(p->cstr);
	while (p->cstr[i])
	{
		i++;
	}

}

void	get_len(t_poly *p)
{
	int i = 0;
	int j = i;
	int k = 0;
	int count = 0;

	while (p->cstr[i])
	{
		if (p->cstr[i - 1] == '^' && p->cstr[i - 2] == 'X')
		{
			j = i;
			count = 0;
			while ((p->cstr[j] != '+' && p->cstr[j] != '-' && p->cstr[j] != '=') && j >= 0)
			{
				printf("%c", p->cstr[j]);
				count++;
				j--;
			}
			printf("\n");
		}
		i++;
	}
}







void	simplify(t_poly *p)
{
	int i;
	i = 0;
	int j = 0;
	get_degree(p);
	del_whitespaces(p);
	count_exp(p);
	p->len = (int *)malloc(sizeof(int) * (p->exp[0] + p->exp[1] + p->exp[2]));
	get_len(p);

}

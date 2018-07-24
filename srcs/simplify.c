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
				count++;
				j--;
			}
			if (p->cstr[j] == '+' || p->cstr[j] == '-' || p->cstr[j] == '=')
			{
				count++;
			}
			p->len[k] = count;
			k++;
		}
		i++;
	}
}


void	fill_x(t_poly *p, int a)
{
	int j;
	int add = p->cut;
	j = 0;
	int i = p->cut;
	while (i <= p->len[a] + add)
	{
		p->x[a][j] = p->cstr[i];
		j++;
		i++;
	}
	p->cut = i;
}

double	compute_value(t_poly *p, int i)
{
	int j = 0;
	double ret = 0;
	while(p->x[i][j])
	{
		if(p->x[i][j] >= 48 && p->x[i][j] <= 57)
		{
			if (p->sign[i] == '1')
			{
				ret = atof(p->x[i] + j);
				break;
			}
			else if (p->sign[i] == '2')
			{
				ret = atof(p->x[i] + j) * -1;
				break;
			}
			else if (p->sign[i] == '3')
			{
				ret = atof(p->x[i] + j) * -1;
				break;
			}
			else if (p->sign[i] == '4')
			{
				ret = atof(p->x[i] + j);
				break;
			}
		}
		j++;
	}
	return (ret);
}

char	*refill(char *tmp, char *str)
{
	int i = 0;
	int j = 0;

	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
		{
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '=')
			{
				tmp[j] = ' ';
				tmp[j + 1] = str[i];
				tmp[j + 2] = ' ';
				j = j + 2;
			}
			else if (str[i] != '+' || str[i] != '-' || str[i] != '*' || str[i] != '/' || str[i] != '=')
				tmp[j] = str[i];
			j++;
		}
		i++;
	}
	return (tmp);
}


char	*format(char *str)
{
	int i = 0;
	int count = 0;
	char *tmp;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '=')
			count = count + 2;
		count++;
		i++;
	}
	tmp = (char *)malloc(sizeof(char) * count + 1);
	str = refill(tmp, str);
	return (str);
}

void	epur(t_poly *p)
{
	int i = 0;
	int j = 0;
	char *tmp = p->str_clean;
	while (p->str_clean[i])
	{
		if (p->str_clean[i] != ' ' && p->str_clean[i] != '\t' && p->str_clean[i] != '\n' && p->str_clean[i] != '\v' && p->str_clean[i] != '\f' &&p->str_clean[i] != '\r')
		{
			if (i == 0 && p->str_clean[i] == '+')
				;
			else
			{
				tmp[j] = p->str_clean[i];
				j++;
			}
		}
		i++;
	}
	tmp[j] = '\0';
	p->str_clean = format(tmp);
}

void	cat_str(t_poly *p)
{
	int i = 0;
	char *a = (char *)malloc(sizeof(char) * 8192);
	char *b = (char *)malloc(sizeof(char) * 8192);
	char *c = (char *)malloc(sizeof(char) * 8192);
	while (i <= 8192)
	{
		a[i] = '\0';
		b[i] = '\0';
		c[i] = '\0';
		i++;
	}
	if (p->a >= 0)
		sprintf(a, "+ %g", p->a);
	else if (p->a < 0)
		sprintf(a, "%g", p->a);
	else if (p->a == 0)
		sprintf(a, " ");
	if (p->b >= 0)
		sprintf(b, "+ %g", p->b);
	else if (p->b < 0)
		sprintf(b, "%g", p->b);
	else if (p->b == 0)
		sprintf(b, " ");
	if (p->c >= 0)
		sprintf(c, "+ %g", p->c);
	else if (p->c < 0)
		sprintf(c, "%g", p->c);
	else if (p->c == 0)
		sprintf(c, " ");
	sprintf(p->str_clean, "%s * X^0 %s * X^1 %s * X^2 = 0", a, b, c);
	epur(p);
}


void	add_exp(t_poly *p)
{
	int i = 0;
	double x0 = 0;
	double x1 = 0;
	double x2 = 0;
	while (i < p->exp[0] + p->exp[1] + p->exp[2])
	{
	if (p->x[i][strlen(p->x[i]) - 1] == '0')
		p->a = compute_value(p,i) + p->a;
	else if (p->x[i][strlen(p->x[i]) - 1] == '1')
		p->b = compute_value(p,i) + p->b;
	else if (p->x[i][strlen(p->x[i]) - 1] == '2')
		p->c = compute_value(p,i) + p->c;
	i++;
	}
	cat_str(p);
}

void	create_sign(t_poly *p, int a)
{
	static int flag = 0;
	if (p->x[a][0] == '=')
		flag = 1;
	if ((flag == 0 && strchr(p->x[a], '+') != 0) || (flag == 0 && ((strchr(p->x[a], '+') == 0 && (strchr(p->x[a], '-') == 0)))))
		p->sign[a] = '1';
	else if (flag == 0 && strchr(p->x[a], '-') != 0)
		p->sign[a] = '2';
	else if ((flag == 1 && strchr(p->x[a], '+') != 0) || (flag == 1 && ((strchr(p->x[a], '+') == 0 && (strchr(p->x[a], '-') == 0)))))
		p->sign[a] = '3';
	else if (flag == 1 && strchr(p->x[a], '-') != 0)
		p->sign[a] = '4';
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
	p->x = (char **)malloc(sizeof(char *) * (p->exp[0] + p->exp[1] + p->exp[2]));
	p->sign = (char *)malloc(sizeof(char) * p->exp[0] + p->exp[1] + p->exp[2]);
	get_len(p);
	while (i < (p->exp[0] + p->exp[1] + p->exp[2]))
	{
		p->x[i] = (char *)malloc(sizeof(char) * p->len[i] + 1);
		fill_x(p, i);
		create_sign(p, i);
		p->x[i][p->len[i]] = '\0';
		i++;
	}
	add_exp(p);
	p->e = p->str_clean;
	printf("Simplify Expression : %s\n", p->e);
}

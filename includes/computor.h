#ifndef COMPUTER_H
# define COMPUTER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct		s_poly
{
	double		a;
	double		b;
	double		c;
	char	*e;
	double		disc;
	int		deg;
	double		sol1;
	double		sol2;
	double		delta;
}					t_poly;

double			ft_atof(const char *str);
char			*ft_strnew(size_t new);
char			*ft_itoa(int n);
static size_t	get_str_len(int n);
void			error(char *str);
void			computor(t_poly *p);

#endif

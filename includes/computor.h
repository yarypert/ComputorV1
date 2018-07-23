#ifndef COMPUTER_H
# define COMPUTER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct		s_poly
{
	double		a;
	double		b;
	double		c;
	char	*e;
	char	*cstr;
	double		disc;
	int		deg;
	double		sol1;
	double		sol2;
	double		delta;
	char		**x;
	int			*exp;
	char		*sign;
	int			*len;
	int			cut;
	char		*str_clean;
}					t_poly;

double			ft_atof(const char *str);
double			get_value(t_poly *p, char c);


char			*ft_strnew(size_t new);
char			*ft_itoa(int n);

void			get_degree(t_poly *p);
void			deg_two_sol(t_poly *p);
void			deg_one_sol(t_poly *p);
void			solve(t_poly *p);
void			init_struct(t_poly *p, char *str);
void			error(char *str);
void			computor(t_poly *p);
void			simplify(t_poly *p);

#endif

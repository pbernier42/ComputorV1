/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorV1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:16:17 by pbernier          #+#    #+#             */
/*   Updated: 2019/01/22 14:16:18 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_computor   t_computor;
typedef struct s_equation   t_equation;
typedef struct s_verbos     t_verbos;

struct  s_computor
{
        size_t i;
		t_equation *start;
};

struct  s_equation
{
		float number;
		char symbol;
		t_equation *next;
};

struct s_verbos
{
        int number_error;
		size_t i;
		char *argv;
};

bool		initialization(
				char *argv, t_computor *comp, t_equation *equa, t_verbos *verb);
bool		initialization_verbos(char *argv, t_verbos *verb);
void		clean(t_computor *comp, t_equation *equa, t_verbos *verb);

t_equation	analyze(char *argv, t_computor *comp, t_verbos *verb);
bool		skip_space(char *argv, t_computor *comp);

#endif

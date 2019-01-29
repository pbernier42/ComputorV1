/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:35:46 by pbernier          #+#    #+#             */
/*   Updated: 2019/01/28 14:35:47 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorV1.h>

t_equation	analyze(char *argv, t_computor *comp, t_verbos *verb)
{
	t_equation data;

	data.number = 0;
	data.symbol = 'h';
	data.next = NULL;
	// si signe
		//verfie le
			//sigen espqce signe
	// choffre obligé chiffre
		//verfie le
			//float
	(void)verb;

	printf("[%s] + [%zu]\n", &argv[comp->i], comp->i);
	++comp->i;
	return (data);
}

// t_equation tmp;
//
// tmp.number = -1;
// tmp.symbol = 'y';
// tmp.next = NULL;
// (void)verb;
//
// printf("[%s] + [%zu]\n", &argv[comp->i], comp->i);
// ++comp->i;
// return (tmp);

bool	skip_space(char *argv, t_computor *comp)
{
	while (argv[comp->i] == '\t' || argv[comp->i] == '\n'
		|| argv[comp->i] == '\r' || argv[comp->i] == '\v'
		|| argv[comp->i] == '\f' || argv[comp->i] == ' ')
		++comp->i;
	if (argv[comp->i] == '\0')
		return (0);
	return(1);
}

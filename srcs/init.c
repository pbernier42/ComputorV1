/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:35:39 by pbernier          #+#    #+#             */
/*   Updated: 2019/01/28 14:35:40 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorV1.h>

bool	initialization(
	char *argv, t_computor *comp, t_equation *equa, t_verbos *verb)
{
	//if (!(equa = (t_equation *)malloc(sizeof(t_equation))))
	//	return (0);
	equa->number = 0;
	equa->symbol = "\0\0";
	//equa->next = ??
	comp->i = 0;
	//comp->start = equa;
	if (!initialization_verbos(argv, verb))
		return (0);
	return (1);
}

bool	initialization_verbos(char *argv, t_verbos *verb)
{
	size_t	i;
	size_t	len_argv;

	i = 0;
	len_argv = 0;
	verb->number_error = 0;
	verb->i = 0;
	while (argv && argv[i])
	{
		if (i > 0 && (argv[i - 1] != '\t' || argv[i - 1] != '\n' ||
			argv[i - 1] != '\r' || argv[i - 1] != '\v' || argv[i - 1] != '\f' ||
			argv[i - 1] != ' '))
			++len_argv;
		++i;
	}
	if (!(verb->argv = (char *)malloc(sizeof(char) * (len_argv + 1))))
		return (0);
	i = 0;
	while (i < len_argv)
		verb->argv[i++] = '\0';
	return (1);
}

void	clean(t_computor *comp, t_equation *equa, t_verbos *verb)
{
	//free equa
	//free data ?
	//free comp->start ?
	//free verb->argv
	(void)comp;
	(void)equa;
	(void)verb;
}

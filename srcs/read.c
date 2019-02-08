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

	data.next = NULL;
	data.symbol = symbol(argv, comp, verb);
	data.number = number(argv, comp, verb);

	//else
		//verbos
	return (data);
}

float	number(char *argv, t_computor *comp, t_verbos *verb)
{
	float	ret;
	float	diz;

	ret = 0;
	diz = 1;
	while ((argv[comp->i] >= '0' && argv[comp->i] <= '9'))
	{
		ret = (ret * diz) + (argv[comp->i] - '0');
		diz = diz * 10;
		add_argv(verb, argv[comp->i++]);
	}
	if (argv[comp->i] == '.')
	{
		add_argv(verb, argv[comp->i++]);
		diz = 10;
		while ((argv[comp->i] >= '0' && argv[comp->i] <= '9'))
		{
			printf("{%f} + {%f}\n", ret, (argv[comp->i] - '0') / diz);
			ret += (argv[comp->i] - '0') / diz;
			diz *= 10;
			add_argv(verb, argv[comp->i++]);
			//proble;e d4arrondi
			//taille max duc chiffres
		}
	}
	//un espace entre les chiffres
	return (ret);
}

char	*symbol(char *argv, t_computor *comp, t_verbos *verb)
{
	int 	minu;
	int		plus;
	char	*ret;

	minu = 0;
	plus = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (2 + 1))))
	{
		//
		printf("ERROR2\n");
		exit(0);
	}
	ret[0] = '.';
	ret[1] = '.';
	if (argv[comp->i] == '/' || argv[comp->i] == '*')
	{
		ret[0] = argv[comp->i++];
		skip_space(argv, comp);
	}
	while (argv[comp->i] == '+' || argv[comp->i] == '-')
	{
		add_argv(verb, argv[comp->i]);
		argv[comp->i++] == '-' ? ++minu : ++plus;
		if (skip_space(argv, comp) > 0)
			add_argv(verb, ' ');
	}
	if (minu && (minu % 2))
		ret[1] = '-';
	else if (plus || (minu && !(minu % 2)))
		ret[1] = '+';
	//CLEAR RETURN ??
	return (ret);
}

int		skip_space(char *argv, t_computor *comp)
{
	int	count_space;

	count_space = comp->i;
	while (argv[comp->i] == '\t' || argv[comp->i] == '\n'
		|| argv[comp->i] == '\r' || argv[comp->i] == '\v'
		|| argv[comp->i] == '\f' || argv[comp->i] == ' ')
		++comp->i;
	count_space = comp->i - count_space;


	if (argv[comp->i] == '\0')
		return (-1);
	return (count_space);
}

void	add_argv(t_verbos *verb, char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
		c = ' ';
	if (verb->i && verb->argv[verb->i - 1] == ' ')
		return ;
	verb->argv[verb->i++] = c;
}

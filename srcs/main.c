/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:13:39 by pbernier          #+#    #+#             */
/*   Updated: 2019/01/22 14:13:44 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorV1.h>

int		main(int argc, char **argv)
{
	t_computor	computor;
	t_equation	data;
    t_equation  equation;
    t_verbos    verbos;

    (void)argc;

	//verification entrer
    if (!initialization(argv[1], &computor, &equation, &verbos))
	{
		//
		printf("ERROR1\n");
		exit(0);
	}
	while (skip_space(argv[1], &computor) != -1)
	{
		data = analyze(argv[1], &computor, &verbos);
		printf("[%s]-", data.symbol);
		printf ("[%f]\n", data.number);
	}
    //si pas erreur de verbos
        //calcul puis imprim
    //else
        //imprime le verbos

	printf("\n[%s]\n", verbos.argv);
	clean(&computor, &equation, &verbos);
	while(1)
		;
    return (0);
}

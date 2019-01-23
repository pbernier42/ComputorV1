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

typedef struct s_equation   t_equation;
typedef struct s_computor   t_computor;
typedef struct s_verbos     t_verbos;

struct  s_computor
{
        size_t i;
};

struct  s_equation
{
        int tmp;
};

struct s_verbos
{
        int tmp;
};

#endif

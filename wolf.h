/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 12:23:10 by aratinau          #+#    #+#             */
/*   Updated: 2015/07/11 23:24:35 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libraire/libft.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 1200
# define HEIGHT 800

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

#endif

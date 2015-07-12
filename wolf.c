/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 12:22:18 by aratinau          #+#    #+#             */
/*   Updated: 2015/07/12 00:35:45 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int key_code, t_env *e)
{
	if (key_code == 53)
		exit (0);
	mlx_clear_window(e->mlx, e->win);
	ft_putstr("key: ");
	ft_putnbr(key_code);
	ft_putchar('\n');
	return (0);
}

int		main(void)
{
	t_env			e;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "wolf");

	mlx_pixel_put(e.mlx, e.win, 120, 120, 0xFF5500);

	mlx_key_hook(e.win, key_hook, &e);
	//mlx_mouse_hook(e.win, mouse_hook, &e); // fonction draw la dedans pour eviter l'expose
	//mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

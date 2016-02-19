/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 12:23:10 by aratinau          #+#    #+#             */
/*   Updated: 2016/02/19 16:59:40 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "includes/libft/libft.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 512
# define HEIGHT 384

# define MOVESPEED 0.2
# define ROTSPEED 8

# define KEYPRESS			2
# define KEYPRESSMASK				(1L << 0)

typedef struct		s_cam
{
	int				hauteur;
	int				orientation;
	int				direction;
	int				fov;
	int				pos_cam_x;
	int				pos_cam_y;
	float			dirX;
	float			dirY;
	float			planeX;
	float			planeY;
	int				test;
}					t_cam;

typedef struct		s_control
{
	int				up;
	int				down;
	int				right;
	int				left;
}					t_control;

typedef struct		s_coor
{
	float			x;
	float			y;
}					t_coor;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				sizeline;
	int				bpp;
	char			*data;
	int				color;
	int				**map;
	t_control		*control;
	t_cam			*cam;
}					t_env;

/* event_mlx */
//int		key_hook(int key_code, t_env *e);
int		key_press_hook(int keycode, t_env *e);
int		key_release_hook(int keycode, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		loop_hook(t_env *e);

/* print_cam.c */
void	print_cam(t_env *e);

/* draw_function.c */
void	count_dist(t_env *e);
void	pixel_put_t_coord(t_env *e, t_coor *coord);
void	pixel_put_coord(t_env *e, float x, float y);
void	draw_line(t_coor co_1, t_coor co_2, t_env *e);
void	line(int x, int y_start, int y_end, t_env *e);
void	mur(t_env *e);
void	cast_rays(t_env *e);

#endif

#include "wolf.h"

#include <stdio.h>
void		cast_rays(t_env *e)
{
    int x;
    x = 0;

    while(x < WIDTH)
    {

		e->color = 0x989898;
		line(x, 0, HEIGHT, e);

		e->color = 0xff5454;
		line(x, 0, 150, e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
        x++;
    }
}

void	pixel_put_t_coord(t_env *e, t_coor *coord)
{
	int q;

	q = coord->x * e->sizeline + coord->y * (e->bpp / 8);

	e->data[q] = e->color;
	e->data[q + 1] = e->color >> 8;
	e->data[q + 2] = e->color >> 16;
}

void	pixel_put_coord(t_env *e, float x, float y)
{
	int q;

	q = y * e->sizeline + x * (e->bpp / 8);

	e->data[q] = e->color;
	e->data[q + 1] = e->color >> 8;
	e->data[q + 2] = e->color >> 16;
}

void	line(int x, int y_start, int y_end, t_env *e)
{
	int y;
	y = y_start;
	while (y < y_end)
	{
		pixel_put_coord(e, x, y);
		y++;
	}
}

void	mur(t_env *e)
{
	int i;
	i = 0;
	while (i < WIDTH)
	{
		line(i, 0, HEIGHT, e);
		i++;
	}
}

#include "wolf.h"

int ft_exp(int n, int p)
{
	int tmp;

	tmp = n;
	p--;
	if (p == 0)
		return (n);
	while (p--)
		n *= tmp;
	return (n);
}

int		ft_d_getnumber(double n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	if (n >= -1 && n <= 1)
		return (1);
	while (n > 1 || n < -1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_ditoa(double n, int c)
{
	int		nb;
	double	ent;
	char	*s;
	int		i;

	if ((nb = ft_d_getnumber(n)) >= c)
		return (ft_itoa((nb = n)));
	s = ft_strnew(c + 2);
	s[0] = '0';
	s[nb] = '.';
	ent = (n * ft_exp(10, c - nb));
	i = 0;
	while (i < c + 1)
	{
		if (s[c - i] == '.')
		{
			i++;
			continue ;
		}
		s[c - i] = fmod(ent, 10) + 48;
		ent = ent / 10; i++; }
	return (s);
}

void ft_putfloat(double n, int c)
{
	char *tmp;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	tmp = ft_ditoa(n, c);
	ft_putstr(tmp);
}

/***********************************************************/
/***********************************************************/
/***********************************************************/

void		count_dist(t_env *e)
{
	int x = e->cam->pos_cam_x;
	int y = e->cam->pos_cam_y;
	int i;
	i = 0;
	while (e->map[y][x] == 0)
	{
		if (e->cam->direction == 0)
			x++;
		if (e->cam->direction == 45)
		{
			x++;
			y++;
		}
		if (e->cam->direction == 90)
			y++;
		if (e->cam->direction == 135)
		{
			x--;
			y++;
		}
		if (e->cam->direction == 180)
			x--;
		if (e->cam->direction == 225)
		{
			x--;
			y--;
		}
		if (e->cam->direction == 270)
			y--;
		if (e->cam->direction == 315)
		{
			x++;
			y--;
		}
		i++;
		e->cam->test = i;
	}
}

void		cast_rays(t_env *e)
{
    int x;
    x = 0;
    while(x < WIDTH)
    {
		/*
		 * balayer tous les x de WIDTH pour connaitre la distance avec un 1
		 * par rapport a notre position actuelle et notre orientation
		 *
		 *
		 * ==> que traverse ce rayon qui a la direction de x ?
		 * commencer avec un rayon a 0
		 */

		e->color = 0x77EEEE;
		line(x, 0, HEIGHT, e);

		e->color = 0xBA85CD;
		line(x, e->cam->test * 20, HEIGHT, e);
        x++;
    }
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
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

#include "wolf.h"

void	print_coord(int x, int y, t_env *e)
{
	ft_putstr("[");
	ft_putnbr(x);
	ft_putstr(" ; ");
	ft_putnbr(y);
	ft_putstr("]");
	ft_putnbr(e->map[x][y]);
}

void	direction(t_env *e)
{
	//
	// 0 - 45 - 90 - 135 - 180 - 225 - 270 - 315 - 360
	if (e->cam->orientation >= 0 && e->cam->orientation < 45)
		e->cam->direction = 0;
	if (e->cam->orientation >= 45 && e->cam->orientation < 90)
		e->cam->direction = 45;
	if (e->cam->orientation >= 90 && e->cam->orientation < 135)
		e->cam->direction = 90;
	if (e->cam->orientation >= 135 && e->cam->orientation < 180)
		e->cam->direction = 135;
	if (e->cam->orientation >= 180 && e->cam->orientation < 225)
		e->cam->direction = 180;
	if (e->cam->orientation >= 225 && e->cam->orientation < 270)
		e->cam->direction = 225;
	if (e->cam->orientation >= 270 && e->cam->orientation < 315)
		e->cam->direction = 270;
	if (e->cam->orientation >= 315 && e->cam->orientation < 360)
		e->cam->direction = 315;
}

void	print_cam(t_env *e)
{
	t_cam *cam;
	cam = e->cam;
	/*
	ft_putstr("posX : ");
	ft_putnbr(cam->pos_cam_x);
	ft_putstr(" posY : ");
	ft_putnbr(cam->pos_cam_y);
	*/
	ft_putchar('\n');
	ft_putstr(" orientation : ");
	ft_putnbr(cam->orientation);
	ft_putstr(" ==direction=:==== ");
	ft_putnbr(e->cam->direction);
	// D'APRES LA CARTE : qu'est qu'il y a a gauche, en face, a droite...
	//ft_putnbr(e->map[cam->pos_cam_x][cam->pos_cam_y]);

/*

       225      270       315
	[-x ; -y] [x ; -y] [+x ; -y]
      180                  0
	[-x ;  y] [x ;  y] [+x ;  y]
      135        90        45
	[-x ; +y] [x ; +y] [+x ; +y]

*/

	ft_putchar('\n');
	/*
	print_coord(cam->pos_cam_x - 1, cam->pos_cam_y - 1, e);
	print_coord(cam->pos_cam_x, cam->pos_cam_y - 1, e);
	print_coord(cam->pos_cam_x + 1, cam->pos_cam_y - 1, e);
	ft_putchar('\n');
	print_coord(cam->pos_cam_x - 1, cam->pos_cam_y, e);
	*/
	print_coord(cam->pos_cam_x, cam->pos_cam_y, e);
	/*
	print_coord(cam->pos_cam_x + 1, cam->pos_cam_y, e);
	ft_putchar('\n');
	print_coord(cam->pos_cam_x - 1, cam->pos_cam_y + 1, e);
	print_coord(cam->pos_cam_x, cam->pos_cam_y + 1, e);
	print_coord(cam->pos_cam_x + 1, cam->pos_cam_y + 1, e);
	*/

	direction(e);

	//print_coord(cam->pos_cam_x, cam->pos_cam_y, e);
	//ft_putnbr(e->map[cam->pos_cam_x][cam->pos_cam_y]);
}

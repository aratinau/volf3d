#include "wolf.h"


void		castRays2(t_env *e) {
	e->color = 0xffff00;
	line(0, 15, 150, e);
}

void		castRays(t_env *e) {

	t_cam *cam;
	cam = e->cam;

    int x = 0;
    while(x < WIDTH)
    {
        // Calculate ray position and direction
        int cameraX = 2 * x / WIDTH - 1; // x coord in cam space
        int rayPosX = cam->pos_cam_x;
        int rayPosY = cam->pos_cam_y;
        int rayDirX = cam->dirX + cam->planeX * cameraX;
        int rayDirY = cam->dirY + cam->planeY * cameraX;

        // Which square of the map we are in //
        int mapX = floor(rayPosX);
        int mapY = floor(rayPosY);

        // Length of ray from current position to next x or y
        float sideDistX;
        float sideDistY;

        // Length of ray from one x or y to next x or y side
        float deltaDistX = sqrt(1 + (rayDirY*rayDirY)/(rayDirX*rayDirX));
        float deltaDistY = sqrt(1 + (rayDirX*rayDirX)/(rayDirY*rayDirY));
//        int perpWallDist;

        // What direction to step in x or y dir (+1 or -1)
        int stepX;
        int stepY;

//        int hit = 0; // was there a wall hit
//        int side; // was a NS or EW wall hit

        // Calculate step and initial sideDist
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (rayPosX - mapX) * deltaDistX;
        }
        else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (rayPosY - mapY) * deltaDistY;
        }
        else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
        }

        // Perform DDA
        /*
        while (hit == 0) {
            // jump to next map square, OR in x dir, OR in y
            if (sideDistX < sideDistY){
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            // Check if ray has hit a wall
            if (map[mapY][mapX] > 0) {
                hit = 1;
            }
        }
        */
        // Calculate distance projected on camera direction
        /*
        if (side == 0) {
            perpWallDist = abs((mapX - rayPosX + (1 - stepX) / 2) / rayDirX);
        }
        else {
            perpWallDist = abs((mapY - rayPosY + (1 - stepY) / 2) / rayDirY);
        }
        */

        // Calculate he height of the line
        int lineHeight = fabs(floor(HEIGHT/* / perpWallDist*/)) * 2;

		//exit(0);

        // Calculate lowest and highest pixel to fill stripe
        int drawStart = -lineHeight / 2 + HEIGHT / 2;
        if (drawStart < 0) {
            drawStart = 0;
        }
        int drawEnd = lineHeight / 2 + HEIGHT / 2;
        if (drawEnd >= HEIGHT) {
            drawEnd = HEIGHT - 1;
        }

        //e->color = 0xffff00;
        line(x, drawStart, drawEnd, e);

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

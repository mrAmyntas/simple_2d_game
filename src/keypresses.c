/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypresses.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/24 20:36:26 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/02/18 21:24:53 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	ft_keypress(int keycode, t_img *img)
{
	int	img_width;
	int	img_length;

	img->img = mlx_xpm_file_to_image(img->mlx, "./images/ghost.xpm",
			&img_width, &img_length);
	if (keycode == 1 && wallcheck_s(img) == 1)
		move_down(img);
	if (keycode == 2 && wallcheck_d(img) == 1)
		move_right(img);
	if (keycode == 0 && wallcheck_a(img) == 1)
		move_left(img);
	if (keycode == 13 && wallcheck_w(img) == 1)
		move_up(img);
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	return (0);
}

int	wallcheck_s(t_img *img)
{
	int	a;
	int	b;

	b = (img->start_x) / 32;
	a = (img->start_y) / 32 + 1;
	if (img->walls[a][b] == 1)
		return (0);
	return (1);
}

int	wallcheck_d(t_img *img)
{
	int	a;
	int	b;

	b = (img->start_x) / 32 + 1;
	a = (img->start_y) / 32;
	if (img->walls[a][b] == 1)
		return (0);
	return (1);
}

int	wallcheck_a(t_img *img)
{
	int	a;
	int	b;

	b = (img->start_x) / 32 - 1;
	a = (img->start_y) / 32;
	if (img->walls[a][b] == 1)
		return (0);
	return (1);
}

int	wallcheck_w(t_img *img)
{
	int	a;
	int	b;

	b = (img->start_x) / 32;
	a = (img->start_y) / 32 - 1;
	if (img->walls[a][b] == 1)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   build_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/24 21:09:41 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/09/26 17:29:14 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	build_floor(t_img *img, int x, int y)
{
	int	img_width;
	int	img_length;

	img->img = mlx_xpm_file_to_image(img->mlx, "./images/floor.xpm",
			&img_width, &img_length);
	mlx_put_image_to_window(img->mlx, img->win, img->img, y * 32, x * 32);
}

void	build_wall(t_img *img, int x, int y)
{
	int	img_width;
	int	img_length;

	img->img = mlx_xpm_file_to_image(img->mlx, "./images/wall_1.xpm",
			&img_width, &img_length);
	mlx_put_image_to_window(img->mlx, img->win, img->img, y * 32, x * 32);
}

void	build_apple(t_img *img, int x, int y)
{
	int	img_width;
	int	img_length;

	img->img = mlx_xpm_file_to_image(img->mlx, "./images/apple.xpm",
			&img_width, &img_length);
	mlx_put_image_to_window(img->mlx, img->win, img->img, y * 32, x * 32);
}

void	build_exit(t_img *img, int x, int y)
{
	int	img_width;
	int	img_length;

	img->img = mlx_xpm_file_to_image(img->mlx, "./images/ladder.xpm",
			&img_width, &img_length);
	mlx_put_image_to_window(img->mlx, img->win, img->img, y * 32, x * 32);
}

void	build_player(t_img *img, int x, int y)
{
	int	img_width;
	int	img_length;

	img->img = mlx_xpm_file_to_image(img->mlx, "./images/ghost.xpm",
			&img_width, &img_length);
	mlx_put_image_to_window(img->mlx, img->win, img->img, y * 32, x * 32);
	img->start_x = y * 32;
	img->start_y = x * 32;
}

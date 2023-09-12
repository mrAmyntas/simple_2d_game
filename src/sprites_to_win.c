/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites_to_win.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/24 20:10:51 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/01 17:19:19 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	move_down(t_img *img)
{
	int	img_width;
	int	img_length;
	int	a;
	int	b;

	mlx_put_image_to_window(img->mlx, img->win, img->img,
		img->start_x, img->start_y + 32);
	a = ft_dont_remove_exit(img);
	img->start_y = img->start_y + 32;
	if (a == 0)
	{
		b = (img->start_x) / 32;
		a = (img->start_y) / 32;
		ft_check_apple_exit(img, a, b);
		img->img = mlx_xpm_file_to_image(img->mlx, "./images/floor.xpm",
				&img_width, &img_length);
		mlx_put_image_to_window(img->mlx, img->win, img->img, img->start_x,
			img->start_y - 32);
	}
	img->ret++;
	printf("Number of moves:%d\n", img->ret);
}

void	move_right(t_img *img)
{
	int	img_width;
	int	img_length;
	int	a;
	int	b;

	mlx_put_image_to_window(img->mlx, img->win, img->img,
		img->start_x + 32, img->start_y);
	a = ft_dont_remove_exit(img);
	img->start_x = img->start_x + 32;
	if (a == 0)
	{
		b = (img->start_x) / 32;
		a = (img->start_y) / 32;
		ft_check_apple_exit(img, a, b);
		img->img = mlx_xpm_file_to_image(img->mlx, "./images/floor.xpm",
				&img_width, &img_length);
		mlx_put_image_to_window(img->mlx, img->win, img->img,
			img->start_x - 32, img->start_y);
	}
	img->ret++;
	printf("Number of moves:%d\n", img->ret);
}

void	move_left(t_img *img)
{
	int	img_width;
	int	img_length;
	int	a;
	int	b;

	mlx_put_image_to_window(img->mlx, img->win, img->img,
		img->start_x - 32, img->start_y);
	a = ft_dont_remove_exit(img);
	img->start_x = img->start_x - 32;
	if (a == 0)
	{
		b = (img->start_x) / 32;
		a = (img->start_y) / 32;
		ft_check_apple_exit(img, a, b);
		img->img = mlx_xpm_file_to_image(img->mlx, "./images/floor.xpm",
				&img_width, &img_length);
		mlx_put_image_to_window(img->mlx, img->win, img->img,
			img->start_x + 32, img->start_y);
	}
	img->ret++;
	printf("Number of moves:%d\n", img->ret);
}

void	move_up(t_img *img)
{
	int	img_width;
	int	img_length;
	int	a;
	int	b;

	mlx_put_image_to_window(img->mlx, img->win, img->img,
		img->start_x, img->start_y - 32);
	a = ft_dont_remove_exit(img);
	img->start_y = img->start_y - 32;
	if (a == 0)
	{
		b = (img->start_x) / 32;
		a = (img->start_y) / 32;
		ft_check_apple_exit(img, a, b);
		img->img = mlx_xpm_file_to_image(img->mlx, "./images/floor.xpm",
				&img_width, &img_length);
		mlx_put_image_to_window(img->mlx, img->win, img->img, img->start_x,
			img->start_y + 32);
	}
	img->ret++;
	printf("Number of moves:%d\n", img->ret);
}

void	ft_check_apple_exit(t_img *img, int a, int b)
{
	if (img->walls[a][b] == 3 && img->consumables == 0)
	{
		printf("CONGRATULATIONS YOU BEAT THE GAME\n");
		printf("FINAL SCORE: %d MOVES - DO BETTER NEXT TIME\n", (img->ret + 1));
		exit(0);
	}
	if (img->walls[a][b] == 3 && img->consumables > 0)
		printf("YOU HAVEN'T EATEN ALL THE APPLES YET?!?!?!\n");
	if (img->walls[a][b] == 2 && (img->consumables - 1) == 0)
	{
		printf("ALL APPLES EATEN! HEAD TO EXIT!\n");
		img->consumables--;
		img->walls[a][b] = 0;
	}
	else if (img->walls[a][b] == 2)
	{
		printf("YOU ATE AN APPLE: ONLY %d APPLES LEFT!\n", img->consumables - 1);
		img->consumables--;
		img->walls[a][b] = 0;
	}
}

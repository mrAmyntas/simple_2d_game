/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/24 20:48:37 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/02/18 21:18:08 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	set_struct_values(t_img *img)
{
	int	ret;

	ret = close(img->fd);
	if (ret == -1)
		ft_error(2);
	img -> mlx = mlx_init();
	img->ret = 0;
	img->fd = open(img->map, O_RDONLY);
	img->consumables = 0;
	readmap(img);
	check_start_exit_cons(img);
	check_one_p(img);
	img->win = mlx_new_window(img->mlx, img->x, img->y, "./so_long");
	img->img = mlx_new_image(img->mlx, img->x, img->y);
}

int	ft_exit(void)
{
	exit(0);
}

int	ft_dont_remove_exit(t_img *img)
{
	int	a;
	int	b;
	int	img_width;
	int	img_length;

	b = (img->start_x) / 32;
	a = (img->start_y) / 32;
	if (img->walls[a][b] == 3 && img->consumables > 0)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "./images/floor.xpm",
				&img_width, &img_length);
		mlx_put_image_to_window(img->mlx, img->win, img->img, img->start_x,
			img->start_y);
		img->img = mlx_xpm_file_to_image(img->mlx, "./images/ladder.xpm",
				&img_width, &img_length);
		mlx_put_image_to_window(img->mlx, img->win, img->img, img->start_x,
			img->start_y);
		return (1);
	}
	return (0);
}

void	ft_check_valid_map(t_img *img)
{
	char	*line;
	int		ret;
	int		array[1000];
	int		i;

	i = 1;
	img->fd = open(img->map, O_RDONLY);
	if (img->fd == -1)
		ft_error(1);
	ret = get_next_line(img->fd, &line);
	if (ret == -1)
		ft_error(0);
	array[0] = ft_check_line(line, 1);
	while (ret == 1)
	{
		free(line);
		ret = get_next_line(img->fd, &line);
		if (ret == -1)
			ft_error(0);
		array[i] = ft_check_line(line, 2);
		i++;
	}
	array[i] = ft_check_line(line, 1);
	check_rectangle(array, i);
	free(line);
}

int	ft_check_line(char *line, int x)
{
	int	i;
	int	ret;

	ret = 1;
	i = 0;
	if (x == 1)
	{
		while (line[i] != '\0')
		{
			if (line[i] != '1')
				ft_invalid_map();
			i++;
		}
	}
	if (x == 2)
	{	
		i = 0;
		while (line[i] != '\0')
			i++;
		if (line[i - 1] != '1' || line[0] != '1')
			ft_invalid_map();
	}
	return (i);
}

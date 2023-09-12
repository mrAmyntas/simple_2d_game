/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   readmap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/24 20:36:34 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/02 19:05:33 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	background(t_img *img)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	img->img = mlx_xpm_file_to_image(img->mlx, "./images/floor.xpm", &x, &y);
	x = 0;
	y = 0;
	while (i < (img->y / 32))
	{
		x = 0;
		j = 0;
		while (j <= (img->x / 32))
		{
			mlx_put_image_to_window(img->mlx, img->win, img->img, x, y);
			x = x + 32;
			j++;
		}
		y = y + 32;
		i++;
	}
}

void	readmap(t_img *img)
{
	int		y;
	int		x;
	char	*line;
	int		ret;

	x = 0;
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(img->fd, &line);
		if (ret == -1)
			ft_error(0);
		y = ft_set_number(line, img, x);
		x++;
		free(line);
	}
	ft_edgemap(img, x, y);
}

int	ft_set_number(char *line, t_img *img, int x)
{
	int	i;
	int	j;
	int	y;

	i = 0;
	while (line[i] != '\0')
		i++;
	y = 0;
	while (y < i)
	{
		j = ft_char_to_int(line[y]);
		if (j == 2)
			img->consumables++;
		img->walls[x][y] = j;
		y++;
	}
	img->walls[x][y] = 9;
	img->x = y * 32;
	return (y);
}

void	ft_edgemap(t_img *img, int x, int y)
{
	int	a;

	a = y;
	y = 0;
	while (y <= a)
	{
		img->walls[x][y] = 9;
		y++;
	}
	img->y = x * 32;
}

int	ft_char_to_int(char c)
{
	int	x;

	if (c == '1' || c == '0')
	{
		x = c - 48;
		return (x);
	}
	else if (c == 'C')
		return (2);
	else if (c == 'E')
		return (3);
	else if (c == 'P')
		return (4);
	else
	{
		printf("Error\nIllegal character in map!\n");
		exit(0);
	}
}

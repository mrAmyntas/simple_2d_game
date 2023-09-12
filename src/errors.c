/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/26 15:13:59 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/02 19:34:53 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	ft_error(int x)
{
	if (x == 0)
		printf("Error\nError reading map\n");
	if (x == 1)
		printf("Error\nFailed to open map\n");
	if (x == 2)
		printf("Error\nFailed to close map\n");
	exit(1);
}

void	ft_invalid_map(void)
{
	printf("Error\nInvalid map, stupid!\n");
	exit(0);
}

void	check_rectangle(int array[1000], int i)
{
	int	j;
	int	a;

	a = array[0];
	j = 0;
	while (j <= i)
	{
		if (array[j] != a)
		{
			printf("Error\nUnlike your head, the map is no rectangle!\n");
			exit(0);
		}
		j++;
	}
}

void	check_start_exit_cons(t_img *img)
{
	int			i;
	int			j;
	static int	array[3];

	i = 0;
	while (img->walls[i][0] != 9)
	{
		j = 0;
		while (img->walls[i][j] != 9)
		{
			if (img->walls[i][j] == 2)
				array[0] = 1;
			if (img->walls[i][j] == 3)
				array[1] = 1;
			if (img->walls[i][j] == 4)
				array[2] = 1;
			j++;
		}
		i++;
	}
	if (array[0] != 1 || array[1] != 1 || array[2] != 1)
	{
		printf("Error\nMap missing a consumable, starting position or exit!\n");
		exit(0);
	}
}

void	ft_inputerror(void)
{
	printf("Error\nOnly one argument allowed: the map!\n");
	exit(0);
}

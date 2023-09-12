/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/24 20:36:43 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/02/18 21:17:44 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int	main(int argc, char **argv)
{
	t_img	img;
	int		ret;

	if (argc != 2)
		ft_inputerror();
	is_it_ber(argv[1]);
	img.map = argv[1];
	ft_check_valid_map(&img);
	set_struct_values(&img);
	background(&img);
	read_xpm(&img);
	mlx_hook(img.win, 2, 1L << 0, ft_keypress, &img);
	mlx_hook(img.win, 17, 1L << 17, ft_exit, &img);
	mlx_loop(img.mlx);
	ret = close(img.fd);
	if (ret == -1)
		ft_error(2);
	return (0);
}

void	check_one_p(t_img *img)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	while (img->walls[i][0] != 9)
	{
		j = 0;
		while (img->walls[i][j] != 9)
		{
			if (img->walls[i][j] == 4)
				x++;
			j++;
		}
		i++;
	}
	if (x > 1)
	{
		printf("Error\nMore than one starting position\n");
		exit(0);
	}
}

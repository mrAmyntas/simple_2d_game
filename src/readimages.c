/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   readimages.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/24 20:36:31 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/02 19:24:20 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	read_xpm(t_img *img)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	x = 0;
	while (img->walls[0][i] != 9)
	{
		x = 0;
		while (img->walls[x][y] != 9)
		{
			ft_put_image(img, x, y);
			x++;
		}
		y++;
		i++;
	}
}

void	ft_put_image(t_img *img, int x, int y)
{
	if (img->walls[x][y] == 0)
		build_floor(img, x, y);
	if (img->walls[x][y] == 1)
		build_wall(img, x, y);
	if (img->walls[x][y] == 2)
		build_apple(img, x, y);
	if (img->walls[x][y] == 3)
		build_exit(img, x, y);
	if (img->walls[x][y] == 4)
		build_player(img, x, y);
}

void	is_it_ber(char *str)
{
	char	**index;
	int		i;

	i = 0;
	index = ft_split(str, '.');
	while (index[i] != NULL)
		i++;
	i = ft_strncmp(index[i - 1], "ber", 3);
	if (i != 0)
	{
		printf("Error\nNot a '.ber' file as input!\n");
		exit(0);
	}
	i = 0;
	while (index[i] != NULL)
	{
		free(index[i]);
		i++;
	}
	free(index);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (len + 1));
	if (buff == NULL)
		return (NULL);
	while ((len > i) && (s[start] != '\0'))
	{
		buff[i] = s[start];
		i++;
		start++;
	}
	buff[i] = '\0';
	return (buff);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

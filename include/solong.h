/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solong.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/24 19:53:41 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/02/18 12:09:10 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_img {
	void	*img;
//	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int		start_x;
	int		start_y;
	int		x;
	int		y;
	int		walls[1000][1000];
	int		fd;
	int		ret;
	int		consumables;
	char	*map;
}				t_img;

typedef struct s_buffer
{
	char		*content;
	int			endoffile;
	int			call_number;
	int			ret;
	int			input;
	int			last_call_eof;
}				t_buffer;

void		readmap(t_img *img);
void		read_xpm(t_img *img);
int			ft_keypress(int keycode, t_img *img);
void		background(t_img *img);
int			wallcheck(t_img *img);
void		wallarray(t_img *img);
int			ft_set_number(char *line, t_img *img, int x);
int			ft_char_to_int(char c);
void		ft_put_image(t_img *img, int x, int y);
void		ft_edgemap(t_img *img, int x, int y);
int			wallcheck_s(t_img *img);
int			wallcheck_w(t_img *img);
int			wallcheck_a(t_img *img);
int			wallcheck_d(t_img *img);
void		move_down(t_img *img);
void		move_right(t_img *img);
void		move_left(t_img *img);
void		move_up(t_img *img);
void		set_struct_values(t_img *img);
void		build_player(t_img *img, int x, int y);
void		build_apple(t_img *img, int x, int y);
void		build_exit(t_img *img, int x, int y);
void		build_wall(t_img *img, int x, int y);
void		build_floor(t_img *img, int x, int y);
int			ft_exit(void);
void		ft_check_apple_exit(t_img *img, int a, int b);
int			ft_dont_remove_exit(t_img *img);
void		ft_check_valid_map(t_img *img);
void		ft_error(int x);
void		ft_invalid_map(void);
int			ft_check_line(char *line, int x);
void		check_rectangle(int array[1000], int i);
void		check_start_exit_cons(t_img *img);
void		ft_inputerror(void);
int			get_next_line(int fd, char **line);
int			ft_set_line(char *store, char **line, int x);
char		*ft_gnl_strjoin(char *s1, const char *s2, int ret);
char		*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		is_it_ber(char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strlen(const char *str);
void		check_one_p(t_img *img);

#endif

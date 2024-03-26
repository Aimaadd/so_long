/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:54:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/03/26 14:50:43 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>
// #include <mlx.h>

# define SO_LONG_H
# define CRATE "./textures/crate.xpm"
# define BEE "./textures/bee.xpm"
# define FLOOR "./textures/grassfloor.xpm"
# define HONEY "./textures/honey.xpm"
# define EXIT "./textures/beehive.xpm"

typedef struct s_map_lookup
{
	char	**map;
	int		max_x;
	int		max_y;
}			t_map_lookup;

typedef struct s_map_info
{
	int	num_lines;
	int	line_length;
	int	player_count;
	int	collectible_count;
	int	player_x;
	int	player_y;
	int	exit_count;
}				t_map_info;

typedef struct s_img
{
	void	*collectible;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
}				t_img;

typedef struct s_win
{
	void	*win;
	void	*ptr;
	int		moves;
	char	*map_name;
	char	**map;
	t_img	img;
	int		collectibles;	
	int		pos_x;
	int		pos_y;
	int		disp;
	int		length;
	int		width;
}				t_win;

typedef struct s_reachable_pair
{
	int	exit;
	int	collectibles;
}				t_reachable_pair;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int			close_win(t_win *var);
void		init_display(t_win *mlg, char *map);
void		put_player(t_win *mlg, int pos_x, int pos_y);
void		set_img(t_win *content);
void		put_wall(t_win *mlg, int pos_x, int pos_y);
void		put_floor(t_win *mlg, int pos_x, int pos_y);
void		put_collectible(t_win *mlg, int pos_x, int pos_y);
void		put_exit(t_win *mlg, int pos_x, int pos_y);
t_map_info	read_map(char *map);
t_map_info	map_check(char *map, t_win *mlg);
int			controls(int keycode, t_win *mlg);
int			closed_map(char *map, t_map_info map_info);

/* MOVES */
void		move_right(t_win *mlg);
void		move_left(t_win *mlg);
void		move_up(t_win *mlg);
void		update_elements(t_win *mlg);
void		move_down(t_win *mlg);
int			is_walkable(t_win *mlg, int x, int y);

/* UTILS */
void		check_all_chars(char *line, t_map_info map_info);
void		check_first_last_chars(char *line, t_map_info map_info);
void		process_line(t_win *mlg, char *line, int pos_x, int pos_y);
int			ft_strncmp(char *s1, char *s2, int n);
int			ft_strlen(const char *str);
int			ft_error(void);
t_win		player_pos(t_win *mlg);
char		**get_map(t_win *mlg, char **map, int x, int y);
void		update_player_position(t_win *mlg, int x, int y);
void		check_first_last_chars(char *line, t_map_info map_info);
void		check_all_chars(char *line, t_map_info map_info);
void		display_player(t_win *mlg, int pos_x, int pos_y);
int			is_collectible(t_win *mlg, int x, int y);
int			is_exit(t_win *mlg, int x, int y);
int			is_exit_reachable(t_win *mlg, int x, int y);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strcpy(char *dest, const char *src);
int			is_finishable(t_win *mlg, t_map_info *map_info);
void		disp_move(t_win *mlg);
void		lengths(int n, size_t *len, int *weight);
char		*ft_itoa(int n);

/* GNL */
char		*get_next_line(int fd);
char		*read_and_keep(int fd, char *remn_str);
char		*ft_get_line(char *remn_str);
char		*ft_strjoin(char *remn_str, char *buff);
char		*ft_strchr(const char *s, int c);
char		*new_remn_str(char *remn_str);

#endif

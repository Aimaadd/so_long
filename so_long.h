/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:54:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/21 14:59:02 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>
// #include <mlx.h>

# ifndef SO_LONG_H
# define SO_LONG_H
# define CRATE "./textures/crate.xpm"
# define BEE "./textures/bee.xpm"
# define FLOOR "./textures/grassfloor.xpm"
# define HONEY "./textures/honey.xpm"
# define EXIT "./textures/beehive.xpm"

typedef struct s_map_info
{
    int num_lines;
    int line_length;
    int player_count;
    int collectible_count;
}              t_map_info;

typedef struct	s_img
{
	void	*collectible;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
}				t_img;

typedef struct   s_win {
    void    *win;
    void    *ptr;
    t_img   img;
	int		disp;
    int     length;
    int     width;
}               t_win;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int			close_win(int keycode, t_win *var);
void		init_display(t_win *mlg, int length, int width);
void		put_bee(t_win *mlg);
void    	put_images(t_win *mlg);
void    	set_img(t_win *content);
void    	put_wall(t_win *mlg, int length, int width);
void		put_floor(t_win *mlg);
void    	put_collectible(t_win *mlg);
void    	put_exit(t_win *mlg);
t_map_info	read_map(char *map);


/* UTILS */
int ft_strncmp(char *s1, char *s2, size_t n);
size_t	ft_strlen(const char *s);

/* GNL */
char	*get_next_line(int fd);
char	*read_and_keep(int fd, char *remn_str);
char	*ft_get_line(char *remn_str);
char	*ft_strjoin(char *remn_str, char *buff);
char	*ft_strchr(const char *s, int c);
char	*new_remn_str(char *remn_str);


# endif

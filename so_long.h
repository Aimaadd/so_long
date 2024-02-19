/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:54:56 by abentaye          #+#    #+#             */
/*   Updated: 2024/02/19 16:21:15 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <mlx.h>

# ifndef SO_LONG_H
# define SO_LONG_H
# define CRATE "./pic/crate.xpm"
# define BEE "./pic/bee.xpm"
# define FLOOR "./pic/grassfloor.xpm"
# define HONEY "./pic/honey.xpm"

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

int		close_win(int keycode, t_win *var);
void	put_bee(t_win *mlg);
void    put_images(t_win *mlg);
void    set_img(t_win *content);
void	put_wall(t_win *mlg);
void	put_floor(t_win *mlg);
void    put_collectible(t_win *mlg);


# endif

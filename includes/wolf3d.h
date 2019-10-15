/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 13:38:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 1000
# define HEIGHT 700
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# include <SDL2/SDL.h>
# include <SDL2/SDL_surface.h>
# include <SDL2/SDL_video.h>
# include <SDL2/SDL_render.h>
# include <SDL2/SDL_pixels.h>
# include <SDL2/SDL_events.h>

#include <stdio.h>

typedef struct		s_lst
{
	char			*line;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_xy
{
	double			x;
	double			y;
}					t_xy;

typedef struct		s_calc
{
	t_ixy			step;
	t_xy			sidedist;
	t_xy			deltadist;
	t_ixy			map;
	t_xy			raydir;
}					t_calc;

typedef struct		s_pos
{
	t_xy			pos;
	t_xy			dir;
	t_xy			plane;
	int				time;
	int				oldtime;
}					t_pos;

/*-----------------------------DRAWLINE-------------------------------*/
typedef struct		s_spot
{
	int				x;
	int				y;
}					t_spot;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_rgb;

typedef struct		s_bressen
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bressen;
/*-----------------------------ENVIRONNEMENT----------------------------*/

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*sur;
	t_pos			*pos;
	int				row;
	int				col;
	int				**map;
}					t_env;

/*-----------------------------NECESSARY---------------------------------*/
/*--main--*/
void				free_env(t_env *v);
void				ft_error(char *str);

/*--draw--*/
void				my_sdl_drawline(t_spot m1, t_spot m2, t_rgb color, t_env *v);
t_rgb				make_rgb(int r, int g, int b, int a);
t_spot				make_spot(int x, int y);

/*--event--*/
int					red_cross(t_env *v);
int					key_press(int keycode, t_env *v);
int					key_release(int keycode, t_env *v);
int					button_event(int button, int x, int y, t_env *v);
/*-----------------------------WOLF3D------------------------------------*/
void				make_map(t_env *v, int fd);

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 13:50:46 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 1000
# define HEIGHT 700
# define TEXWIDTH 128
# define FIELDOFVIEW 45
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

typedef struct		s_tex
{
	int				x;
	int				y;
	int				hit;
}					t_tex;

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
	int				x;
	int				side;
	double			ang;
	t_ixy			step;
	t_xy			sidedist;
	t_xy			deltadist;
	t_ixy			map;
	t_xy			dir;
}					t_calc;

typedef struct		s_pos
{
	t_xy			pos;
	int				angle;
	int				fov;
	int				time;
	int				oldtime;
}					t_pos;

/*-----------------------------DRAWLINE-------------------------------*/
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
typedef struct		s_lst
{
	char			*line;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*sur[16];
	t_pos			pos;
	double			rad[360];
	int				row;
	int				col;
	int				**map;
	double			rot_speed;
	int				bool_cursor;
	int				bool_cam;
	int				inc;
	t_lst			*lst;
}					t_env;

/*-----------------------------NECESSARY---------------------------------*/
/*--main--*/
void				free_env(t_env *v);
void				ft_error(char *str);
void				assigntextures(t_env *v);

/*--draw--*/
void				drawtexedline(t_xy src, t_xy dst, t_env *v, t_tex tex);
void				my_sdl_drawline(t_ixy m1, t_ixy m2, t_rgb color, t_env *v);
t_rgb				make_rgb(int r, int g, int b, int a);
t_ixy				make_spot(int x, int y);

/*--event--*/
void				mouse_button_event(SDL_Event event, t_env *v);
void				mouse_motion_event(SDL_Event event, t_env *v);
void				key_event(SDL_Event event, t_env *v);
/*-----------------------------WOLF3D------------------------------------*/
/*--parsing--*/
t_lst				*wolf3d_parsing(t_env *v, int fd);
void				map(t_env *v);

/*--calculs--*/
void				render(t_env *v);
void				make_rad(t_env *v);
void				render(t_env *v);

/*--draw--*/
void				drawtexedline(t_xy src, t_xy dst, t_env *v, t_tex tex);

/*--display--*/
void				display(t_env *v);
void				background(t_env *v);

#endif

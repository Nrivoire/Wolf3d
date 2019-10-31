/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 19:49:57 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 1000
# define HEIGHT 700
# define TEXWIDTH 128
# define FIELDOFVIEW 45
# define ANGLE 105
# define ROTSPEED 1
# define MOVESPEED .1

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
	int				x;			//Correspond a la colonne dessinee
	int				side;		//Pour savoir si on touche un mur en X ou en Y
	double			ang;		//Angle d'un seul rayon en Rad
	t_ixy			step;		//Savoir si on avance ou on recule en X et en Y
	t_xy			sidedist;	//Distance entre nous et la premiere intersection en X et en Y
	t_xy			deltadist;	// Distance entre deux points d'intersection en X et en Y
	t_ixy			map;		// Coordonnees de la case qu'on verifie
	t_xy			dir;		// Vecteur qui correspond a notre direction
}					t_calc;

typedef struct		s_pos
{
	t_xy			pos;
	int				angle;
	int				fov;
	int				time;
	int				oldtime;
}					t_pos;

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
	SDL_Surface		*sur[16][4];
	t_pos			pos;
	double			rad[360];
	int				row;
	int				col;
	int				**map;
	double			rot_speed;
	double			movespeed;
	int				bool_cam;
	int				inc;
	t_lst			*lst;
}					t_env;

/*-----------------------------NECESSARY---------------------------------*/
/*--main--*/
void				free_env(t_env *v);
void				ft_error(char *str);
void				assigntextures(t_env *v);

/*--event--*/
void				mouse_button_event(SDL_Event event, t_env *v);
void				mouse_motion_event(SDL_Event event, t_env *v);
void				key_event(const Uint8 *keyboard_state, t_env *v);
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

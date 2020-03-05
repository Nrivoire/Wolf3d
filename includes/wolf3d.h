/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/29 04:56:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 18:57:25 by tprzybyl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 1000
# define HEIGHT 700
# define FIELDOFVIEW 55
# define ROTSPEED .2
# define MOVESPEED 0.1

# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include "../sdl2/2.0.10/include/SDL2/SDL.h"
# include "../sdl2/2.0.10/include/SDL2/SDL_surface.h"
# include "../sdl2/2.0.10/include/SDL2/SDL_video.h"
# include "../sdl2/2.0.10/include/SDL2/SDL_render.h"
# include "../sdl2/2.0.10/include/SDL2/SDL_pixels.h"
# include "../sdl2/2.0.10/include/SDL2/SDL_events.h"
# include "../sdl2_image/2.0.5/include/SDL2/SDL_image.h"

typedef struct		s_tex
{
	int				x;
	int				y;
	int				hit;
	int				ori;
	float			dist;
}					t_tex;

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_xy
{
	float			x;
	float			y;
}					t_xy;

typedef struct		s_calc
{
	int				x;
	int				side;
	float			ang;
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
}					t_pos;

/*
** -----------------------------ENVIRONNEMENT----------------------------
*/
typedef struct		s_lst
{
	char			*line;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env
{
	pthread_mutex_t	mutex;
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*sur[9][4];
	SDL_Texture		*back;
	t_pos			pos;
	float			rad[1080];
	int				row;
	int				col;
	int				**map;
	float			fovmax;
	float			fovmin;
	float			rot_speed;
	float			m_speed;
	int				thread_index;
	int				bool_cam;
	int				inc;
	t_lst			*lst;
}					t_env;

/*
** -----------------------------NECESSARY---------------------------------
*/
/*
** --main--
*/
void				ft_error(char *str);
void				assigntextures(t_env *v);

/*
** --event--
*/
void				mouse_button_event(SDL_Event event, t_env *v);
void				mouse_motion_event(SDL_Event event, t_env *v);
int					key_event(const Uint8 *keyboard_state, t_env *v);
void				movement_side(const Uint8 *keyboard_state, t_env *v);
void				movement_direction(const Uint8 *keyboard_state, t_env *v);
void				set_mouse(t_env *v);
void				close_sdl(t_env *v);
/*
** -----------------------------WOLF3D------------------------------------
*/
/*
** --parsing--
*/
t_lst				*wolf3d_parsing(t_env *v, int fd);
void				map(t_env *v);

/*
** --calculs--
*/
void				background(t_env *v);
void				render(t_env *v);

/*
** --draw--
*/
void				drawtexedline(t_xy src, t_xy dst, t_env v, t_tex tex);
void				get_texture(t_env *v, t_calc *c, t_tex *tex,
		float distance);

/*
** --display--
*/
void				display(t_env *v);

#endif

# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/06/14 18:19:22 by nrivoire     #+#   ##    ##    #+#        #
#    Updated: 2019/11/15 18:23:20 by nrivoire    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Output
NAME = wolf3d

#	Sources
# SRC_SUP = {dossiers dans src qui seront separe par une virgule}
SRC_SUP = my_sdl
SRC_PATH = src
SRC_NAME =  main.c wolf3d_parsing.c make_map.c wolf3d_drawline.c wolf3d_renderer.c \
		    wolf3d_textures.c \
			mouse_event.c key_event.c display.c\
		   

#	Objects
OBJ_PATH = .objects
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#	Includes
INC_PATH = includes
INC_NAME = wolf3d.h
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

CPPFLAGS = -I $(INC_PATH)
LDFLAGS = -O3 -lpthread -L libft
LDLIBS = -lft

#	SDL
SDL = -lft -F /Library/Frameworks/ -L sdl2/2.0.10/lib/ -lSDL2 -L sdl2_image/2.0.5/lib/ -lSDL2_image
PATH_TO_SDL = ./

#	Compiler
CC = clang
CFLAGS = -Wall -Wextra

################
##   COLORS   ##
################

GREY=$ \x1b[30m
RED=$ \x1b[31m
GREEN=$ \x1b[32m
YELLOW=$ \x1b[33m
BLUE=$ \x1b[34m
PINK=$ \x1b[35m
CYAN=$ \x1b[36m
WHITE=$ \x1b[37m

# This is a minimal set of ANSI/VT100 color codes
END=$ \x1b[0m
BOLD=$ \x1b[1m
UNDER=$ \x1b[4m
SUR=$ \x1b[7m

#################
##  TARGETS    ##
#################

# $@ -> nom de la règle
# $^ -> représente tout ce qui est apres le :
# $< -> nom de la dependance

	#@[ -d sdl2 ] && echo "SDL2 exist" || echo "SDL2 does not exist"
	#@[ -d sdl2_image ] && echo "SDL2_image exist" || echo "SDL2_image does not exist"

# empêche le Makefile de confondre un fichier et une règle en cas de même nom
.PHONY: all clean fclean re sdl

all: libft.a $(NAME)
	@printf "$(BLUE)> $(NAME) : $(YELLOW)Project ready !$(END)\n"

$(NAME): $(OBJ)
	@$(CC) $(LDFLAGS) $(SDL) $(LDLIBS) $^ -o $@
	@printf "\n$(BLUE)> $@ : $(GREEN)Success !$(END)\n\n"

libft.a:
	@make -C ./libft/

sdl:
	brew update && brew reinstall sdl2 sdl2_image
	cp -R ~/.brew/Cellar/sdl2 ./
	cp -R ~/.brew/Cellar/sdl2_image ./ 
	cp sdl/SDL_image.h sdl2_image/2.0.5/include/SDL2/SDL_image.h

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/$(SRC_SUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf "\r$(YELLOW)$(BOLD)[COMPILE] $(END) $(<:.c=)..."

clean:
	@make -C libft clean
	@rm -rf $(OBJ_PATH)
	@rm -rf sdl2 sdl2_image
	@printf "$(BLUE)> Deleted : $(RED)$(OBJ_PATH)$(END)\n"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@rm -rf sdl2 sdl2_image
	@printf "$(BLUE)> Deleted : $(RED)$(NAME)$(END)\n"

re: fclean sdl all

norme:
	norminette $(SRC_PATH) $(INC_PATH)

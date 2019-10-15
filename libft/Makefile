# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/04 11:42:11 by vasalome     #+#   ##    ##    #+#        #
#    Updated: 2019/08/21 15:30:48 by nrivoire    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Libft Makefile path
LIBFTDIR	=	../libft

#	Sources
SRC = ft_putchar.c ft_putchar_fd.c\
	  ft_putstr.c ft_putstr_fd.c ft_strlen.c\
	  ft_putnbr.c ft_putnbr_fd.c\
	  ft_strequ.c ft_strnequ.c\
	  ft_strcmp.c ft_strncmp.c\
	  ft_strcpy.c ft_strncpy.c\
	  ft_putendl.c ft_putendl_fd.c\
	  ft_strcat.c ft_strncat.c ft_strlcat.c\
	  ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c\
	  ft_strchr.c ft_strrchr.c ft_strnchr.c\
	  ft_memset.c ft_memcmp.c ft_memchr.c ft_memccpy.c ft_memcpy.c ft_memmove.c ft_memdel.c\
	  ft_toupper.c ft_tolower.c\
	  ft_atoi.c ft_natoi.c ft_itoa.c ft_range.c ft_swap.c\
	  ft_strstr.c ft_strnstr.c\
	  ft_bzero.c ft_strdup.c ft_memalloc.c\
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_strrev.c\
	  ft_striter.c ft_striteri.c\
	  ft_strmap.c ft_strmapi.c\
	  ft_strtrim.c ft_strjoin.c ft_strjoinfree.c ft_strcjoin.c ft_strsub.c ft_strsplit.c\
	  ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_print_lst.c\
	  ft_print_bits.c\
	  ft_strspn.c ft_strcspn.c\
	  ft_stractrim.c ft_occur.c ft_sqrt.c ft_error.c\
	  ft_absolu.c\
	  get_next_line.c\

#	Output
NAME = libft.a

#	Objects
OBJ = $(SRC:.c=.o)

#	Includes
INCLUDE = libft.h

#	Compiler
CFLAGS = -Wall -Werror -Wextra -I. -c 

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
all: $(NAME)

$(NAME): $(OBJ)
	@ ar ruc $(NAME) $(OBJ)
	@ ranlib $(NAME)

%.o:%.c libft.h
	@gcc $(CFLAGS) $< -o $@
	@printf "\r $(PINK) $(BOLD) [CC] $(END) $(<:.c=)..."

clean:
	@ /bin/rm -f $(OBJ)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
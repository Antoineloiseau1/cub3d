NAME	=	cub3D

SRCS	=	./srcs/main.c \
			./srcs/parsing/check_map.c \
			./srcs/parsing/check_map_utils.c \
			./srcs/parsing/parse_utils.c \
			./srcs/parsing/check_data.c \
			./srcs/error.c \
			./srcs/parsing/data.c \
			./srcs/free.c \
			./srcs/utils.c \
			./srcs/parsing/parse_textures.c \
			./srcs/parsing/check_file.c \
			./srcs/parsing/parse_map.c \
			./srcs/hook.c \
			./srcs/raycasting.c \
			./srcs/movements.c \
			./srcs/rotate.c \
			./srcs/raycasting_utils.c \
			./srcs/wall.c

OBJS	= 	${SRCS:.c=.o}

LIB		=	libft/libft.a

LFT		= 	-L./libft -lft

MLX		= 	-L ./minilibx -lmlx -framework Opengl -framework Appkit

CC		=	gcc -g

CFLAGS	=	-Wall -Werror -Wextra

RM		= 	rm -rf

%.o: %.c
	${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:		${LIB} ${NAME}

${LIB}:		
			@make all -sC ./libft

${NAME}:	${LIB} ${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${MLX} ${LFT} -o ${NAME}

bonus:		all

clean:
			@make clean -sC ./libft
			${RM} ${OBJS}

fclean:		clean
			@make fclean -sC ./libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all re clean fclean bonus

NAME	=	cub3d

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
			./srcs/raycasting.c

OBJS	= 	${SRCS:.c=.o}

LIB		=	libft/libft.a

LFT		= 	-L./libft -lft

MLX		= 	-L /usr/local/lib/ -lmlx -framework Opengl -framework Appkit
#MLX 	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC		=	gcc -g

CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address

RM		= 	rm -rf

all:		${LIB} ${NAME}

${LIB}:		
			@make all -sC ./libft

${NAME}:	${LIB} ${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${MLX} ${LFT} -o ${NAME}

clean:
			@make clean -sC ./libft
			${RM} ${OBJS}

fclean:		clean
			@make fclean -sC ./libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all re clean fclean

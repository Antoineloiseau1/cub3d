NAME	=	cub3d

SRCS	=	./srcs/main.c \
			./srcs/parsing/check_map.c \
			./srcs/parsing/check_map_utils.c \
			./srcs/error.c \
			./srcs/parsing/data.c \
			./srcs/free.c \
			./srcs/utils.c \
			./srcs/parsing/parse_textures.c \
			./srcs/parsing/check_file.c \
			./srcs/parsing/parse_map.c

OBJS	= 	${SRCS:.c=.o}

LIB		=	libft/libft.a

LFT		= 	-L./libft -lft

#MLX		= 	-L /usr/local/lib/ -lmlx -framework Opengl -framework Appkit

CC		=	gcc -g

CFLAGS	=	-Wall -Werror -Wextra

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

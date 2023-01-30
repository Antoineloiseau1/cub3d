NAME	=	cub3d

SRCS	=	./srcs/main.c \
			./srcs/checkers.c \
			./srcs/error.c \
			./srcs/data.c \
			./srcs/free.c \
			./srcs/utils.c \
			./srcs/parser.c

OBJS	= 	${SRCS:.c=.o}

LIB		=	libft/libft.a

LFT		= 	-L./libft -lft

MLX		= 	-L /usr/local/lib/ -lmlx -framework Opengl -framework Appkit

CC		=	gcc

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

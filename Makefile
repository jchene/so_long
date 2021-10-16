NAME		=	so_long

SRCS		=	./srcs/*.c\
				./utils/get_next_line/*.c

CC			=	gcc

CFLAGS		=	-Werror -Wextra -Wall

SANFLAGS	=	-g -fsanitize=address

LIB			=	-lm -lX11 -lXext

MLX			=	./utils/minilibx-linux/libmlx_Linux.a

DEL			=	rm -f

OBJ			=	$(SRCS:.c=.o)

all:			$(NAME)

%.o:%.c
				$(CC) $(CFLAGS) -o $@ -c $<

make_mlx:		
				make -C utils/minilibx-linux

$(NAME):		$(OBJ) make_mlx
				$(CC) -o $(NAME) $(SRCS) $(MLX) $(LIB) $(CFLAGS)

san:			$(OBJ) make_mlx
				$(CC) -o $(NAME) $(SRCS) $(MLX) $(LIB) $(CFLAGS) $(SANFLAGS)

clean:
				$(DEL) $(OBJ)
				@make clean -C utils/minilibx-linux

fclean:			clean
				$(DEL) $(NAME)

re:				fclean all

.PHONY: 		all san clean fclean re

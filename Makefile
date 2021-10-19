NAME		=	so_long

SRCS		=	./srcs/check_map.c\
				./srcs/color.c\
				./srcs/free.c\
				./srcs/init.c\
				./srcs/lib.c\
				./srcs/mem.c\
				./srcs/mlx.c\
				./srcs/pre_check.c\
				./srcs/so_long.c\
				./srcs/static.c\
				./utils/get_next_line/get_next_line.c\
				./utils/get_next_line/get_next_line_utils.c

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

$(NAME):		$(OBJ)
				make -C utils/minilibx-linux
				$(CC) -o $(NAME) $(SRCS) $(MLX) $(LIB) $(CFLAGS)

san:			$(OBJ)
				make -C utils/minilibx-linux
				$(CC) -o $(NAME) $(SRCS) $(MLX) $(LIB) $(CFLAGS) $(SANFLAGS)

clean:
				$(DEL) $(OBJ)
				make clean -C utils/minilibx-linux

fclean:			clean
				$(DEL) $(NAME)

re:				fclean all

.PHONY: 		all san clean fclean re

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

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(SRCS) $(MLX) $(LIB) $(CFLAGS)

%.o:%.c
				$(CC) $(CFLAGS) -o $@ -c $<

all:			$(NAME)

san:			$(OBJ)
				$(CC) -o $(NAME) $(SRCS) $(MLX) $(LIB) $(CFLAGS) $(SANFLAGS)

clean:
				$(DEL) $(OBJ)

fclean:			clean
				$(DEL) $(NAME)

re:				fclean all

.PHONY: 		all san clean fclean re

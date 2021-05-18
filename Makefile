# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akant <akant@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/12 15:18:39 by akant         #+#    #+#                  #
#    Updated: 2021/05/18 11:44:59 by akant         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker
SRCS_P =	push_swap.c list_utils1.c list_utils2.c list_utils3.c
SRCS_C =	list_utils1.c list_utils2.c list_utils3.c checker.c get_next_line.c \
			get_next_line_utils.c error.c
OBJ_P = $(SRCS_P:%.c=%.o)
OBJ_C = $(SRCS_C:%.c=%.o)
FLAGS = -Wall -Wextra -Werror
LIBFTLIBRARY = ./libft/libft.a

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(OBJ_P)
	$(MAKE) -C ./libft
	$(CC) $(OBJ_P) $(FLAGS) $(LIBFTLIBRARY) -o $(NAME_PS)

$(NAME_CH): $(OBJ_C)
	$(MAKE) -C ./libft
	$(CC) $(OBJ_C) $(FLAGS) $(LIBFTLIBRARY) -o $(NAME_CH)

%.o: %.c # $(HEADER_FILES)
	$(CC) -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME_PS) $(NAME_CH) $(OBJ_P) $(OBJ_C)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re

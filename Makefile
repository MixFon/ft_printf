NAME = ft_printf

LIB_FILE = libft.a

CFILES = ft_printf.c main.c
OFILES = ft_printf.o main.o
FLAGS = -Wall -Wextra -Werror

HFILE = -I.

all: $(NAME)

$(NAME):
	make re -C ./libft_last_ver
	gcc -g $(FLAGS) $(HFILES) -c $(CFILES) 
	gcc -g $(FLAFS) $(OFILES) -L./libft_last_ver -lft -o $(NAME)
	make fclean -C ./libft_last_ver 

clean: 
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

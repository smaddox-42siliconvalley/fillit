NAME=fillit

all : $(NAME)

o_files:
	gcc -c *.c  -I fillit.h libft/libft.h -Wall -Wextra -Werror

$(NAME) : o_files
	make all -C libft
	gcc -o $(NAME) *.o libft/libft.a

clean :
	rm -rf *.o
	make clean -C libft

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all

NAME=fillit

all : $(NAME)

o_files:
	gcc -c *.c  -I fillit.h libft/libft.h -Wall -Wextra -Werror

$(NAME) : o_files
	gcc -o $(NAME) *.o libft/libft.a

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all


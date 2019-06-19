NAME=fillit

CFLAGS= -Wall -Wextra -Werrors

CFLAGS += -I libft/ fillit.h

SRC = allocs.c				\
	  alt_print.c			\
	  clean.c				\
	  column_creator.c		\
	  covers.c				\
	  ft_math.c				\
	  main.c				\
	  piece_manipulation.c	\
	  read.c				\
	  solve.c				\
	  stack.c				\
	  t_cells.c				\
	  toroid_maker.c		\
	  uncovers.c			

OBJ=$(SRC:%.c=%.o)

all : $(NAME)

$(OBJ):
	gcc -c $(SRC) 

$(NAME) : $(OBJ) 
	gcc -o $(NAME) $(SRC) libft/libft.a

clean :
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(NAME)

re : fclean all



all : 
	gcc  libft.a main.c column_creator.c read.c ft_math.c t_cells.c -I fillit.h libft/libft.h 


debug : 
	gcc -g fillit.h libft.a libft/libft.h main.c read.c ft_math.c column_creator.c t_cells.c

cleand :
	rm -rf a.out*
	rm -rf *.h.*

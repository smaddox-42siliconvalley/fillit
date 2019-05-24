
all : 
	gcc  libft.a main.c read.c ft_math.c -I fillit.h libft/libft.h


debug : 
	gcc -g fillit.h libft.a libft/libft.h main.c read.c ft_math.c 

cleand :
	rm -rf a.out*
	rm -rf *.h.*

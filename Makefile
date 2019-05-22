
all : 
	gcc fillit.h libft.a libft/libft.h main.c read.c ft_math.c


debug : 
	gcc -g fillit.h libft.a libft/libft.h main.c read.c ft_math.c 

cleand :
	rm -rf a.out*
	rm -rf *.h.*

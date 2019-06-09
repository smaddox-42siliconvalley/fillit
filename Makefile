all : 
	gcc *.c libft.a -I fillit.h libft.h

debug :
	gcc -g *.c libft.a -I fillit.h libft.h

cleand :
	rm -rf a.out*
	rm -rf libft.h.*

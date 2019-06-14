o_files:
	gcc -c *.c  -I fillit.h libft.h

all : o_files 
	gcc -o fillit *.o libft.a

debug :
	gcc -g *.c libft.a -I fillit.h libft.h

real :
	gcc -Wall -Wextra -Werror *.c libft.a -I fillit.h libft.h

cleand :
	rm *.o
	rm -rf a.out*
	rm -rf libft.h.*
	rm fillit

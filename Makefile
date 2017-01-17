##
## Makefile for dmfkgjldfkgjf in /home/ratouney/CPool_Day10
## 
## Made by ratouney ratouney
## Login   <ratouney@epitech.net>
## 
## Started on  Fri Oct 14 09:36:54 2016 ratouney ratouney
## Last update Mon Oct 17 11:11:10 2016 ratouney ratouney
##

SRC	=	calib_add.c			\
		calib_copy.c		\
		calib_rem.c			\
		calib_show.c		\
		calib_write.c		\
		charray.c			\
		destroy_charray.c	\
		fillgen.c			\
		newcharray.c		\
		calib_char.c		\
		calib_nbr.c			\
		calib_import.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libratarray.a

HEADER	=	ratstr.h

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	make clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

test:
	gcc -g *.c

re:	fclean all

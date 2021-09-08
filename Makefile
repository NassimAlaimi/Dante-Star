##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

all:
	make -C lib/my
	make -C solver
	make -C generator

clean:
	rm -f lib/my/*.o
	rm -f generator/src/*.o
	rm -f solver/*.o

fclean: clean
	rm -f lib/my/libmy.a
	rm -f solver/*.o
	rm -f solver/solver
	rm -f generator/*.o
	rm -f generator/generator

re:	fclean all

##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for infadd prog
##

SRC		=	src/main.c									\
			src/get_next_line.c							\
			src/initialisation/init_game.c				\
			src/initialisation/init_player.c			\
			src/initialisation/init_fireball.c			\
			src/initialisation/init_enemy.c				\
			src/initialisation/init_obj.c				\
			src/initialisation/init_background.c		\
			src/initialisation/init_xp.c				\
			src/initialisation/init_menu.c				\
			src/core.c									\
			src/core_infinite.c							\
			src/infinite_mode.c							\
			src/errors.c								\
			src/special_case.c							\
			src/player_physic.c							\
			src/paralax.c								\
			src/fireball.c								\
			src/score.c									\
			src/enemies.c								\
			src/collision.c								\
			src/free.c 									\
			src/free_obj.c								\
			src/hp.c									\
			src/xp.c									\
			src/main_menu.c								\
			src/parameters.c							\
			src/main_menu_interaction.c					\
			src/save.c									\
			src/collision_sound.c						\

OBJ	    =	$(SRC:.c=.o)

NAME	=	my_runner

LIB     =	-Llib/my -lmy

CFLAGS	=	-Iinclude

all:	$(NAME) clean

DOLIB:
	$(MAKE) -C ./lib/my

$(NAME): DOLIB $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB) -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -l csfml-graphics -lm -ldl


clean:
	rm -f $(OBJ)
	$(MAKE) clean -C lib/my

debug:	DOLIB
	$(CC) -o my_runner $(SRC) $(CFLAGS) $(LIB) -l csfml-graphics -l csfml-system -l csfml-window -l csfml-graphics -l csfml-audio -lm -ldl -W -Wall -Wextra -g

test: fclean $(LIB) $(OBJ)
	$(CC) -o unit_tests -Iinclude $(SRC) $(LIB) tests/test.c --coverage -lcriterion

fclean:	clean
	rm -f $(NAME) *.gc*
	$(MAKE) fclean -C lib/my

re:	fclean all

%.o:    %.c
		@echo -n "Compiling... : $<"
		@$(CC) $(CFLAGS) -c $< -o $@ && echo " [\033[32mOK\033[0m]" || echo " [\033[31mKO\033[0m]"

.PHONY: all clean fclean re debug test

CC = gcc
FLAGS = -Wall -Werror -Wextra -I /inc/ -fsanitize=leak
#FLAGS = -I /inc/ -fsanitize=leak
CFILES = main.c\
		utilities.c\
		init.c\
		mutex_fn.c\
		philos_fn.c\
		threads_fn.c\
		monitor.c
HEADER = inc/philo.h
NAME = philo
DIRF = src/
SRC_FILES = $(addprefix $(DIRF),$(CFILES))

all : $(NAME)

$(NAME) : $(SRC_FILES) $(HEADER) Makefile
	$(CC) $(FLAGS) $(SRC_FILES) -g -o $(NAME)

library:
	@ make -C libft
	@ make -C printf


clean:


fclean:


re: fclean all


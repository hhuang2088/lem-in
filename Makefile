NAME = lem-in
HEADER = ./inc/
SRCDIR = ./src/
FLAGS = -g -Wall -Wextra -Werror
CC = gcc
FILES = main.c input_get.c handle_error.c input_check_format.c layout_init.c \
				input_check_util.c input_process.c input_process_util.c \
				paths_generate.c ant_util.c path_explore.c room_util.c room_util2.c \
				paths_sort.c ants_crawl.c ants_crawl_util.c is_util.c path_util.c \
				path_util2.c path_explore_preliminary_steps.c
LIBDIR = ./libft/
LIBFT = $(LIBDIR)libft.a
LIBLINK = -L$(LIBDIR) -lft
OPTIONS = -I$(HEADER) $(FLAGS)
PFDIR = ./ft_printf/
PRINTF = $(PFDIR)ft_printf.a
PFLINK = -L$(PFDIR) -lftprintf
SRC = $(addprefix $(SRCDIR), $(FILES))
OBJ = $(FILES:.c=.o)

.PHONY: all clean fclean re

all: libft printf $(NAME)

libft: $(LIBFT)

printf: $(PRINTF)

$(LIBFT):
	make -C $(LIBDIR)

$(PRINTF):
	make -C $(PFDIR)

main.o: $(SRCDIR)main.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)main.c

input_get.o: $(SRCDIR)input_get.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)input_get.c

input_process_util.o: $(SRCDIR)input_process_util.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)input_process_util.c

handle_error.o: $(SRCDIR)handle_error.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)handle_error.c

input_check_format.o: $(SRCDIR)input_check_format.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)input_check_format.c

input_check_util.o: $(SRCDIR)input_check_util.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)input_check_util.c

input_process.o: $(SRCDIR)input_process.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)input_process.c

layout_init.o: $(SRCDIR)layout_init.c $(HEADER)lemin.h
	$(CC) $(OPTIONS) -c $(SRCDIR)layout_init.c

path_explore.o: $(SRCDIR)path_explore.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)path_explore.c

path_util.o: $(SRCDIR)path_util.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)path_util.c

path_util2.o: $(SRCDIR)path_util2.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)path_util2.c

paths_generate.o: $(SRCDIR)paths_generate.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)paths_generate.c

path_explore_preliminary_steps.o: $(SRCDIR)path_explore_preliminary_steps.c \
																	$(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)path_explore_preliminary_steps.c

paths_sort.o: $(SRCDIR)paths_sort.c $(HEADER)lemin.h
	$(CC) $(OPTIONS) -c $(SRCDIR)paths_sort.c

ants_crawl.o: $(SRCDIR)ants_crawl.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)ants_crawl.c

ants_crawl_util.o: $(SRCDIR)ants_crawl_util.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)ants_crawl_util.c

ant_util.o: $(SRCDIR)ant_util.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)ant_util.c

room_util.o: $(SRCDIR)room_util.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)room_util.c

room_util2.o: $(SRCDIR)room_util2.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)room_util2.c

is_util.o: $(SRCDIR)is_util.c $(HEADER)lemin.h
	 $(CC) $(OPTIONS) -c $(SRCDIR)is_util.c

$(NAME): $(OBJ)
	$(CC) $(LIBLINK) $(PFLINK) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

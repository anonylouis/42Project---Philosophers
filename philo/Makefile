CC = gcc

FLAGS = -Wall -Wextra -Werror -g3 #-g3 -fsanitize=address #-g3 -fsanitize=thread
LIB_FLAGS = -lpthread

NAME = philo

SOURCES = forks.c  main.c  philo.c  print.c  routine_even.c  routine_odd.c  threads.c  stop.c  table.c  utils.c
SRCS = $(addprefix ./srcs/, $(SOURCES))

OBJECTS = ${SOURCES:.c=.o}
OBJS = $(addprefix ./objs/, $(OBJECTS))

DEPENDENCIES = ${SOURCES:.c=.d}
DPDC = $(addprefix ./objs/, $(DEPENDENCIES))

HEADER = ./includes
HEADER_FILES=$(HEADER)/philo.h $(HEADER)/table.h 

all : $(NAME)

$(NAME) :	$(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB_FLAGS)

clean : 
		rm -f $(OBJS) $(DPDC)
		rm -rf ./objs/

fclean : clean 
		rm -f $(NAME) 

re :	fclean all

./objs/%.o :	./srcs/%.c $(HEADER_FILES)
		mkdir -p objs
		$(CC) $(FLAGS) -MMD -I $(HEADER) -o $@ -c $< $(LIB_FLAGS)

.PHONY : all re clean fclean bonus

CC = gcc

FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=thread # -g3 -fsanitize=address
LIB_FLAGS = -lpthread

NAME = philo_bonus

SOURCES = forks.c main.c philo.c print.c routine.c start_processes.c table.c utils.c wait_processes.c
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

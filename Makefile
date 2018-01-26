
NAME = abstractvm

FLAGS = -Wfatal-errors -Wall -Wextra -Werror

SRC =  ./src/*.cpp

INC = -I ./src

all:
	@g++ $(FLAGS) -o $(NAME) $(SRC) $(INC)

fclean:
	rm $(NAME)

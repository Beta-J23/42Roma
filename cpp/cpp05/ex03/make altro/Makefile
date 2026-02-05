NAME = 28B

CC = c++

HEADER = includes
CFLAGS = -Wextra -Wall -Werror -std=c++98 -I$(HEADER)

SRC = main.cpp src/Bureaucrat.cpp src/AForm.cpp src/ShrubberyCreationForm.cpp \
	src/PresidentialPardonForm.cpp src/RobotomyRequestForm.cpp
 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
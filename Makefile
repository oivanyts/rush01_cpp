SRC_DIR := ./
OBJ_DIR := ./obj/
SRC :=  CPUModule.cpp \
        DateTimeModule.cpp \
        HostnameModule.cpp \
        NetworkModule.cpp \
        OSInfoModule.cpp \
        RAMModule.cpp \
        main.cpp \

SRC := $(addprefix $(SRC_DIR), $(SRC))
OBJ := $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.cpp=.o))
NAME = ft_gkrellm
CC = c++
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^ -lncurses
	@echo "\033[0;32m$@ was created\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
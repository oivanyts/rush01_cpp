
NAME        = ft_gkrellm
CC          = clang++
CFLAGS      =  -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRCS_DIR    = ./srcs
OBJS_DIR    = ./objs

HEADERS     = CPUModule.hpp DateTimeModule.hpp HostnameModule.hpp
HEADERS    += NetworkModule.hpp OSInfoModule.hpp RAMModule.hpp NcursesOut.hpp
HEADERS    += IMonitorDisplay.hpp IMonitorModule.hpp
HEADERS    := $(addprefix $(SRCS_DIR)/, $(HEADERS))

SRCS        = main.cpp CPUModule.cpp DateTimeModule.cpp HostnameModule.cpp
SRCS       += NetworkModule.cpp OSInfoModule.cpp RAMModule.cpp NcursesOut.cpp
SRCS       += IMonitorDisplay.cpp

OBJS        = $(SRCS:.cpp=.o)

LIBRARIES   = -lncurses

TO_LINKING  = $(addprefix $(OBJS_DIR)/, $(OBJS)) $(LIBRARIES)

VPATH       = $(SRCS_DIR) $(OBJS_DIR)


.SILENT     :
.PHONY		: all build clean fclean re


all         :
	$(MAKE) -j4 build -s

build       : $(NAME)

$(NAME)     : $(OBJS_DIR) $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) -o $(NAME) $(TO_LINKING)
	@printf "\n\e[38;5;46m%-40s created [ ✔ ]\e[0m\n" ./$(NAME)

$(OBJS_DIR) :
	@mkdir $(OBJS_DIR)

$(OBJS)     : %.o : %.cpp
	@$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR)/$@
	@printf "%-40s \e[38;5;49mcompiled\e[0m\n" $<

clean       :
	@rm -rf $(OBJS_DIR)

fclean      : clean
	@rm -f $(NAME)

re          : fclean all
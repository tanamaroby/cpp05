# Compiler and Flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable name
NAME = bureaucrat_forms

# Source files
SRCS = main.cpp Bureaucrat.cpp Form.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files for dependencies
HEADERS = Bureaucrat.hpp Form.hpp

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

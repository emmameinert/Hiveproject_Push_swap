
NAME = push_swap

SRC = pushswap parsing utils sort_little radix memory \
		operations_pa operations_pb parsing2\
		operations_r operations_rr operations_s ft_atol
HEADER = pushswap.h

CC = cc 

FLAGS = -Wall -Wextra -Werror -I $(HEADER)

FILES = $(addsuffix .c, $(SRC))

OBJECTS = $(addsuffix .o, $(SRC))

LIBFT = ./sources/libft 

all: $(NAME)

$(NAME): $(OBJECTS)
				cd $(LIBFT) && $(MAKE)
				$(CC) -C $(FLAGS) $^ -L$(LIBFT) -lft -o $@

clean:
			rm -f $(OBJECTS)
			cd $(LIBFT) && $(MAKE) clean
	
fclean: clean	
			rm -f $(NAME)
			cd $(LIBFT) && $(MAKE) fclean

re: fclean all 

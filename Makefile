
NAME = push_swap

SRC = pushswap ./sources/parsing/parsing ./sources/utils/utils ./sources/sorting/sort_little \
		./sources/sorting/radix ./sources/utils/memory \
		./sources/operations/operations_pa ./sources/operations/operations_pb ./sources/parsing/parsing2 \
		./sources/operations/operations_r ./sources/operations/operations_rr ./sources/operations/operations_s ./sources/utils/ft_atol \

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

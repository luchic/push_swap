# Makefile for the ft_printf project
NAME = push_swap

# folder with src code
SRC = src

## Push_swap  
PSRC = $(SRC)/push_swap
SORT = $(PSRC)/sort
STACK = $(PSRC)/stack
UTILS = $(PSRC)/utils
PARSE = $(PSRC)/parse
NORMALIZE = $(PSRC)/normalize

SRC_FILES = \
$(PSRC)/main.c \
$(PARSE)/ft_parse_input.c \
$(PARSE)/ft_get_array.c \
$(PARSE)/ft_parse_dublicate.c \
$(NORMALIZE)/ft_normalize.c \
$(SORT)/ft_sort.c \
$(SORT)/ft_sort_three.c \
$(SORT)/ft_sort_five.c \
$(SORT)/ft_move.c \
$(SORT)/ft_return.c \
$(SORT)/ft_split.c \
$(STACK)/ft_stack.c \
$(STACK)/ft_base_operation.c \
$(STACK)/ft_free_stack.c \
$(STACK)/ft_stack_abop.c \
$(STACK)/ft_stack_aop.c \
$(STACK)/ft_stack_bop.c \
$(UTILS)/ft_utils.c \
$(UTILS)/ft_utils1.c \
$(UTILS)/ft_get_utils.c \
$(UTILS)/ft_get_utils1.c \
$(UTILS)/ft_position.c \
$(UTILS)/ft_chunks.c

OBJ_FILES = $(SRC_FILES:.c=.o)

# Header
HEADER = includes

# Libft
DLIBFT = libft
LIBFT = $(DLIBFT)/libft.a
FT = ft

# For tests
TOUT = a.out

# Compiler and flags
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
CDEBUG = -g -I$(HEADER) -o	$(TOUT) -fsanitize=address,undefined
CC = cc

all : $(NAME)

$(NAME) : 	$(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) -L$(DLIBFT) -l$(FT)	

debug : $(SRC_FILES) $(LIBFT)
	$(CC) $(CDEBUG) $(SRC_FILES) -L$(DLIBFT) -l$(FT)	

$(LIBFT) :
	make -C $(DLIBFT) all

re : fclean all

fclean : clean
	rm -f $(NAME)
	make -C $(DLIBFT) fclean

clean : 
	rm -f $(OBJ_FILES)
	rm -f $(TOUT)
	make -C $(DLIBFT) fclean

.PHONY: all clean fclean re debug


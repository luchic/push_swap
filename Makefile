# Makefile for the ft_printf project
NAME = push_swap
CHECKER = checker

# folder with src code
SRC = src

## Checker

CSRC = $(SRC)/checker
CORE = $(CSRC)/core
CPARSE = $(CSRC)/parse

CHECKER_FILES = \
	$(CSRC)/main.c \
	$(CORE)/ft_run.c \
	$(CPARSE)/ft_exec_instr.c \
	$(CPARSE)/ft_read_command.c \
	$(CPARSE)/ft_sort_checker.c
	

CHECKER_OBJ = $(CHECKER_FILES:.c=.o)

## Push_swap  
PSRC = $(SRC)/push_swap
SORT = $(PSRC)/sort
UTILS = $(PSRC)/utils

SRC_FILES = \
	$(PSRC)/main.c \
	$(SORT)/ft_sort.c \
	$(SORT)/ft_sort_three.c \
	$(SORT)/ft_sort_five.c \
	$(SORT)/ft_move.c \
	$(SORT)/ft_return.c \
	$(SORT)/ft_split.c \
	$(UTILS)/ft_utils.c \
	$(UTILS)/ft_utils1.c \
	$(UTILS)/ft_get_utils.c \
	$(UTILS)/ft_get_utils1.c \
	$(UTILS)/ft_position.c \
	$(UTILS)/ft_chunks.c

OBJ_FILES = $(SRC_FILES:.c=.o)

## Stack
STACK = $(SRC)/stack

STACK_SRC = \
	$(STACK)/ft_stack.c \
	$(STACK)/ft_base_operation.c \
	$(STACK)/ft_free_stack.c \
	$(STACK)/ft_stack_abop.c \
	$(STACK)/ft_stack_aop.c \
	$(STACK)/ft_stack_bop.c
STACK_OBJ = $(STACK_SRC:.c=.o)

## Common
COMMON = $(SRC)/common
PARSE = $(COMMON)/parse
NORMALIZE = $(COMMON)/normalize

COMMON_SRC = \
	$(COMMON)/ft_error.c \
	$(PARSE)/ft_parse_input.c \
	$(PARSE)/ft_get_array.c \
	$(PARSE)/ft_parse_dublicate.c \
	$(NORMALIZE)/ft_normalize.c
COMMON_OBJ = $(COMMON_SRC:.c=.o)

# Header
HEADER = includes

# Libft
DLIBFT = libft
LIBFT = $(DLIBFT)/libft.a
FT = ft

# For tests
# TOUT = a.out

# Compiler and flags
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
# CDEBUG = -g -I$(HEADER) -o	$(TOUT) -fsanitize=address,undefined
CC = cc

all : $(NAME)

$(NAME) : 	$(OBJ_FILES) $(STACK_OBJ) $(COMMON_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) \
		$(COMMON_OBJ) \
		$(STACK_OBJ) \
		$(OBJ_FILES) \
		-L$(DLIBFT) -l$(FT)

bonus : $(CHECKER)

$(CHECKER) : $(CHECKER_OBJ) $(STACK_OBJ) $(COMMON_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CHECKER) \
		$(STACK_OBJ) \
		$(COMMON_OBJ) \
		$(CHECKER_OBJ) \
		-L$(DLIBFT) -l$(FT)

# debug_bonus : $(CHECKER_FILES) $(STACK_SRC) $(COMMON_SRC) $(LIBFT)
# 	$(CC) $(CDEBUG) -o $(CHECKER) \
# 		$(CHECKER_FILES) \
# 		$(STACK_SRC) \
# 		$(COMMON_SRC) \
# 		-L$(DLIBFT) -l$(FT)	

# debug : $(SRC_FILES) $(STACK_SRC) $(COMMON_SRC) $(LIBFT)
# 	$(CC) $(CDEBUG) -o $(NAME) \
# 		$(SRC_FILES) \
# 		$(STACK_SRC) \
# 		$(COMMON_SRC) \
# 		-L$(DLIBFT) -l$(FT)	

$(LIBFT) :
	make -C $(DLIBFT) all

re : fclean all

fclean : clean
	rm -f $(NAME)
	rm -f $(CHECKER)
	make -C $(DLIBFT) fclean

clean : 
	rm -f $(CHECKER_OBJ)
	rm -f $(STACK_OBJ)
	rm -f $(COMMON_OBJ)
	rm -f $(OBJ_FILES)
	rm -f $(TOUT)
	make -C $(DLIBFT) fclean

.PHONY: all clean fclean re #debug debug_bonus


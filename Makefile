# Makefile for the ft_printf project
NAME = push_swap

# folder with src code
SRC = src

## All Src files
# SRC_FILES = $(wildcard $(SRC)/*.c)
SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(SRC_FILES:.c=.o)

# Libft
DLIBFT = libft
LIBFT = $(DLIBFT)/libft.a
FT = ft

# For tests
TOUT = push_swap

# Header
HEADER = includes

# Compiler and flags
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
CDEBUG = -g -I$(HEADER) -o	$(TOUT) -fsanitize=address,undefined
CC = cc

all : $(NAME)

# bonus : $(NAME)

# debug : $(MAIN) $(SRC_FILES) $(LIBFT)
# 	$(CC) $(CDEBUG) $(MAIN) $(SRC_FILES) -L$(DLIBFT) -l$(FT)

# $(NAME) : 	$(OBJ_FILES) $(LIBFT)
# 	$(CC) $(CDEBUG) $(OBJ_FILES) -L$(DLIBFT) -l$(FT)	

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

.PHONY: all clean fclean re bonus debug
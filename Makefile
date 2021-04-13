# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 13:37:24 by lorenuar          #+#    #+#              #
#    Updated: 2021/04/13 20:34:47 by jsilance         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

# The name of your executable
NAME		= library.a
NAME_CHECK	= checker
NAME_SWAP	= push_swap

# Compiler and compiling flags
CC	= gcc
# CFLAGS	= -Wall -Werror -Wextra
AR = ar
ARFLAGS = -rcs

# Debug, use with`make DEBUG=1`
ifeq ($(DEBUG),1)
CFLAGS	+= -g3 -fsanitize=address
# CFLAGS	+= -g3
endif

# Folder name
SRCDIR	= src/
INCDIR	= includes/
OBJDIR	= bin/

# Add include folder
CFLAGS	+= -I $(INCDIR)

# Linking stage flags
LDFLAGS =

###▼▼▼<src-updater-do-not-edit-or-remove>▼▼▼
# **************************************************************************** #
# **   Generated with https://github.com/lorenuars19/makefile-src-updater   ** #
# **************************************************************************** #

SRCS =\
	./src/io/get_next_line.c\
	./src/utils/utils.c\
	./src/print/ft_putstruct.c\
	./src/list/ft_lstlast.c\
	./src/list/ft_lstadd_front.c\
	./src/list/ft_lstadd_back.c\
	./src/list/ft_lstclear.c\
	./src/list/list_swap.c\
	./src/list/lst_push.c\
	./src/list/ft_lstnew.c\
	./src/list/ft_lstiter.c\
	./src/list/ft_lstdelone.c\
	./src/list/lst_rot.c\
	./src/list/ft_lstsize.c\

HEADERS =\
	./includes/get_next_line.h\
	./includes/list.h\
	./includes/utils.h\
	./includes/debug_utils.h\

###▲▲▲<src-updater-do-not-edit-or-remove>▲▲▲

# String manipulation magic
SRC		:= $(notdir $(SRCS))
OBJ		:= $(SRC:.c=.o)
OBJS	:= $(addprefix $(OBJDIR), $(OBJ))

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

# Implicit rules
VPATH := $(SRCDIR) $(OBJDIR) $(shell find $(SRCDIR) -type d)

# ================================== RULES =================================== #

all : $(NAME)

# Compiling
$(OBJDIR)%.o : %.c
	@mkdir -p $(OBJDIR)
	@printf "$(GR)+$(RC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Linking
$(NAME)	: $(SRCS) $(HEADERS) $(OBJS)
	@printf "\n$(GR)=== Compiled [$(CC) $(CFLAGS)] ===\n--- $(SRC)$(RC)\n"
#	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@printf "$(YE)&&& Linked [$(AR) $(ARFLAGS)] &&&\n--- $(NAME)$(RC)\n"

# Cleaning
clean :
	@echo "$(RE)--- Removing $(OBJDIR)$(RC)"
	@rm -rf $(OBJDIR)

fclean : clean
	@echo "$(RE)--- Removing $(NAME)$(RC)"
	@rm -f $(NAME) $(NAME_EXE)

# Special rule to force to remake everything
re : fclean all

swap: $(NAME)
	$(CC) $(CFLAGS) src/swap/main.c $(NAME) -o $(NAME_SWAP)

checker: $(NAME)
	$(CC) $(CFLAGS) src/checker/main.c $(NAME) -o $(NAME_CHECK)

# This runs the program
run : swap checker
	@echo "$(CY)>>> Running $(NAME)$(RC)"
	./$(NAME_SWAP) $(ARG) | ./$(NAME_CHECK) $(ARG)

# This specifies the rules that does not correspond to any filename
.PHONY	= all run clean fclean re

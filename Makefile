# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 15:04:16 by ldevelle          #+#    #+#              #
#    Updated: 2019/03/11 20:16:26 by ldevelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

EXEC = ft_printf

CC = gcc

CFLAGS = #-Wall -Wextra -Werror

DFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -pedantic\
-O2 -Wchar-subscripts -Wcomment -Wformat=2 -Wimplicit-int\
-Werror-implicit-function-declaration -Wmain -Wparentheses -Wsequence-point\
-Wreturn-type -Wswitch -Wtrigraphs -Wunused -Wuninitialized -Wunknown-pragmas\
-Wfloat-equal -Wundef -Wshadow -Wpointer-arith -Wbad-function-cast\
-Wwrite-strings -Wconversion -Wsign-compare -Waggregate-return\
-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations\
-Wmissing-noreturn -Wformat -Wmissing-format-attribute\
-Wno-deprecated-declarations -Wpacked -Wredundant-decls -Wnested-externs\
-Winline -Wlong-long -Wunreachable-code

#CFLAGS = $(DFLAGS)

##############################################################################
##############################################################################
##																			##
##									----									##
##									IFEQ									##
##									----									##
##																			##
##############################################################################
##############################################################################

SRCS		=	ft_printf\
				ft_printf_options parsing check_arg ajust_flags\
				init output bonus_gestion\
				type_float type_integer type_pointer type_string\
				type_unsigned_integer type_others type_character type_binary\
				get_str_int get_str_str get_str_float get_printf\
				get_str_char\
				ft_memcmp ft_atoi ft_strsplit ft_lstnew ft_strchr ft_get_next_line ft_power ft_strjoin_multi ft_strnlen ft_swap ft_isprint ft_random ft_rgb_color ft_rgb_bcolor ft_place_cursor ft_putchar ft_putendl ft_putstr ft_lst_reach_end ft_lstadd_start ft_lstadd ft_lstadd_here ft_lstfind_th ft_burn_garbage ft_lstadd_end ft_putstr_fd ft_clean_garbage ft_garbage_collector ft_lst_free ft_memdel ft_nalloc ft_bzero ft_char_srch ft_isdigit ft_memalloc ft_memmove ft_memset ft_strdel  ft_strdup ft_strjoin ft_strlen ft_strnew ft_strsub ft_islower ft_toupper

MAIN		= main.c

SRC_PATH	= ./srcs

DIR_OBJ 	= ./objs/

##########################
##						##
##	   ARCHITECTURE		##
##						##
##########################

A_SRC 		= $(patsubst %,$(SRC_PATH)/%.c,$(SRCS))
A_OBJ		= $(patsubst %,$(DIR_OBJ)%.o,$(SRCS))

OBJ 		= $(patsubst %,%.o,$(SRCS))

LIB_DIR		= ./../libft
HEAD		= head.h
HEAD_DIR	= ./includes
HEAD_PATH	= $(HEAD_DIR)/$(HEAD)

LIB			= $(LIB_DIR)/libft.a

##########################
##						##
##		  DEBUG			##
##						##
##########################

VALGRIND = valgrind --track-origins=yes --leak-check=full --show-leak-kinds=definite

##########################
##						##
##		 COLORS			##
##						##
##########################

RED     = \x1b[31m
GREEN   = \x1b[32m
YELLOW  = \x1b[33m
BLUE	= \x1b[34m
MAGENTA	= \x1b[35m
CYAN	= \x1b[36m
END     = \x1b[0m

COM_COLOR   = $(BLUE)
OBJ_COLOR   = $(CYAN)
OK_COLOR    = $(GREEN)
ERROR_COLOR = $(RED)
WARN_COLOR  = $(YELLOW)
NO_COLOR    = $(END)

OK_STRING    = [OK]
ERROR_STRING = [ERROR]
WARN_STRING  = [WARNING]
COM_STRING   = Compiling

MSG ?= Makefile automated push

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

##############################################################################
##############################################################################
##																			##
##									-----									##
##									RULES									##
##									-----									##
##																			##
##############################################################################
##############################################################################

##########################
##						##
##		  BASIC			##
##						##
##########################

all :	$(NAME)

$(NAME): $(A_OBJ) $(HEAD_PATH)
		@$(MAKE) -C $(LIB_DIR)
		@$(call run_and_test, ar -rcs $(NAME) $(A_OBJ))

$(EXEC): $(NAME) $(MAIN)
		@$(call run_and_test, $(CC) $(CFLAGS) -I./$(HEAD_DIR) $(NAME) $(MAIN) -o $(EXEC))


$(DIR_OBJ)%.o:$(SRC_PATH)/%.c
		@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $<)

clean :
		@echo "\$(YELLOW)fill_objs \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"
		@rm -f $(A_OBJ)

fclean : clean
		@echo "\$(YELLOW)$(NAME) \$(END)\\thas been \$(GREEN)\\t\\t\\t  $@\$(END)"
		@rm -rf $(NAME) $(EXEC)

aclean : clean
		@$(MAKE) clean -C $(LIB_DIR)

afclean : aclean fclean
		@$(MAKE) fclean -C $(LIB_DIR)

re :	fclean all

are :	afclean all

ex :	$(EXEC)

git :
		@git add -A
		@git status
		git commit -am "$(MSG)"
		@git push

t	:	$(EXEC)
		./$(EXEC) "$(MSG)" 0
		./$(EXEC) "$(MSG)" 1
		./$(EXEC) "$(MSG)" 2
		./$(EXEC) "$(MSG)" 3
		./$(EXEC) "$(MSG)" 4
		./$(EXEC) "$(MSG)" 5
		./$(EXEC) "$(MSG)" 6
		./$(EXEC) "$(MSG)" 7
		./$(EXEC) "$(MSG)" 8

tv	:	$(EXEC)
		$(VALGRIND) ./$(EXEC) "$(MSG)"

check :
		bash /Users/ldevelle/42/TESTS/42FileChecker/42FileChecker.sh

##########################
##						##
##		 .PHONY			##
##						##
##########################

.PHONY : clean fclean re all git aclean afclean are

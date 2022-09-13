# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:08:09 by cudoh             #+#    #+#              #
#    Updated: 2022/08/19 16:46:35 by cudoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SRCS:= $(shell ls *.c | grep -v lst | xargs)
SRCS_CLIENT:= client.c
SRCS_SERVER:= server.c
SRCS_COMMON:= comm.c queue.c
SRCS_CLIENT_BONUS:= client_bonus.c
SRCS_SERVER_BONUS:= server_bonus.c
SRCS_COMMON_BONUS:= comm_bonus.c queue_bonus.c
#OBJS_BONUS:=$(SRCS_BONUS:.c=.o)
OBJS_CLIENT:= $(SRCS_CLIENT:.c=.o)
OBJS_SERVER:= $(SRCS_SERVER:.c=.o)
OBJS_COMMON:= $(SRCS_COMMON:.c=.o)
OBJS_CLIENT_BONUS:= $(SRCS_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS:= $(SRCS_SERVER_BONUS:.c=.o)
OBJS_COMMON_BONUS:= $(SRCS_COMMON_BONUS:.c=.o)

NAME = client
NAME_2 = server
USR_LIB = libft.a
USR_LIB_PATH = ./libft

CC = cc
CFLAGS = -Werror -Wall -Wextra 
LIBFLAGS_STATIC = -L$(USR_LIB_PATH) -lft 
INCLUDES = -I./ -I$(USR_LIB_PATH)

NAME : all
all : $(NAME)
$(NAME) : $(OBJS_CLIENT) $(OBJS_COMMON) $(USR_LIB)
	make $(NAME_2)
	$(CC) $^ $(CFLAGS) $(INCLUDES) -o $@
	@echo "\033[1;32mCompilation Successful. \033[0m"

$(NAME_2) : $(OBJS_SERVER) $(OBJS_COMMON) $(USR_LIB)
	$(CC) $^ $(CFLAGS) $(INCLUDES) -o $@

	
bonus: $(USR_LIB) $(OBJS_COMMON_BONUS) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	@echo # line spacing
	@echo "\033[1;33mCompiling BONUS - MINITALK \033[0m"
#	rm -rf $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_COMMON) 
	$(CC) $(OBJS_SERVER_BONUS) $(OBJS_COMMON_BONUS) $(USR_LIB) $(CFLAGS) $(INCLUDES) -o $(NAME_2)
	$(CC) $(OBJS_CLIENT_BONUS) $(OBJS_COMMON_BONUS) $(USR_LIB) $(CFLAGS) $(INCLUDES) -o $(NAME)
	@echo "\033[1;32mCompilation Successful. \033[0m"
# obj files output
%.o : %.c
	$(CC) -c $^ $(CFLAGS) $(INCLUDES) -o $@


$(USR_LIB) :
	@echo
#	$(AR) $(LIBFLAGS_STATIC) $@ $^						# create the library file for linking
	@echo "\033[1;33mCompiling LIBFT Library \033[0m"
	cd ./libft; make > /dev/null; cp libft.a ../; cd ..	
	@echo												# print new line on screen
	@echo "\033[1;36mCompiling Executable \033[0m"

	

# remove all object files
fclean:
	rm -rf *.o
	cd ./libft; make fclean; cd ..;

# remove final target files
clean: fclean
	rm -rf $(NAME)
	rm -rf $(NAME_2)
	rm -rf *.a
	cd ./libft; make clean; cd ..;

# recompile everything
re: clean all

.PHONY : all fclean clean re 

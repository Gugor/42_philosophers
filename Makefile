BLACK		:= \033[1;30m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
MAGENTA		:= \033[1;35m
CYAN		:= \033[1;36m
WHITE		:= \033[1;37m
RESET		:= \033[1;0m

# Target
NAME := philo

# Directories
INCS_DIR := incs/
SRCS_DIR := srcs/
OBJS_DIR := .objs

# Dependencies
MF = Makefile

# Compilation Flags
CC := cc  
CFLAGS := -Wall -Wextra -Werror -O3 
IFLAGS := -I$(INCS_DIR) 
DFLAGS := -g #-fsanitize=address

# Files
SRCS := $(SRCS_DIR)philosophers.c \
		$(SRCS_DIR)init.c \
		$(SRCS_DIR)settings.c \
		$(SRCS_DIR)philo.c \
		$(SRCS_DIR)routine.c \
		$(SRCS_DIR)waiter_getters.c \
		$(SRCS_DIR)waiter_setters.c \
		$(SRCS_DIR)philo_getters.c \
		$(SRCS_DIR)philo_setters.c \
		$(SRCS_DIR)philo_states.c \
		$(SRCS_DIR)mutex_handler.c \
		$(SRCS_DIR)philo_wait.c \
		$(SRCS_DIR)utils.c \
		$(SRCS_DIR)dinner_time.c\
		$(SRCS_DIR)error_handler.c\
		$(SRCS_DIR)message.c \
		$(SRCS_DIR)memory_handler.c

INCS := $(INCS_DIR)philosophers.h

OBJS := $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME):: $(OBJS) $(INCS) 
	@printf "\n$(GREEN)=>$(RESET) Compiling $(MAGENTA)$(NAME)$(RESET)\n"
	$(CC) $(DFLAGS) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME)
$(NAME):: $(OBJS)
	@printf "\n$(GREEN)⭐⭐⭐ $(RESET) Compilation $(MAGENTA)$(NAME)$(RESET) completed ‍🖖 $(GREEN)⭐⭐⭐ $(RESET)\n\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)%.c $(MF) $(INCS) 
	@mkdir -p $(OBJS_DIR) 
	@printf "$(GREEN)√ $(RESET)$(WHITE)%s$(RESET)\n  " "$<"
	$(CC) $(DFLAGS) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -vf $(OBJS) 
fclean: clean
	@rm -vf $(NAME)

re: fclean all
	@echo "\n==========================================="
	@echo "|| \033[1;32m√\033[0m Recompiled  \033[1;33m$(NAME)\033[0m"
	@echo "==========================================="
.PHONY: all clean fclean re


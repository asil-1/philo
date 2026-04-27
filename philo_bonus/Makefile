#COMPILE_______________________
CC = cc
CFLAGS = $(ALL_INCLUDES) -Wall -Wextra -Werror -MMD -MP -g
MAKEFLAGS += --no-print-directory

HEADER = philo_bonus.h

NAME = philo_bonus

#INCLUDES______________________
INCLUDE = includes/
CFLAGS += -I$(INCLUDE)

BUILD_DIR = obj/
SRC_DIR = src/

#SRC___________________________

SRC=main_bonus.c \
	parsing_bonus.c \
	utils_bonus.c \
	semaphores.c \
	routine_bonus.c \
	child_management.c \
	time.c \
	print_bonus.c \
	thread_bonus.c \
	data_management.c

#OBJ___________________________

OBJ = $(SRC:%.c=$(BUILD_DIR)%.o)
DEPS = $(SRC:%.c=$(BUILD_DIR)%.d)
OBJ_DIR = $(sort $(shell dirname $(OBJ)))

#_________________________________

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "link philo_bonus"
	@echo "./philo_bonus nb_of_philo time_to_die time_to_eat time_to_sleep nb_of_meal"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

$(OBJ_DIR):
	@mkdir -p $@

bonus: all

clean:
	@rm -rf $(BUILD_DIR)
	@echo "clean bonus/ obj/"

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

-include $(DEPS)
#COMPILE_______________________
CC = cc
CFLAGS = $(ALL_INCLUDES) -Wall -Wextra -Werror -MMD -MP
MAKEFLAGS += --no-print-directory

HEADER = philo_b.h

NAME = philo_bonus

#INCLUDES______________________
INCLUDE = includes/
CFLAGS += -I$(INCLUDE)

BUILD_DIR = obj/
SRC_DIR = src/

#SRC___________________________

SRC=main_b.c \
	time_b.c \
	parcing_b.c \
	utils_b.c \
	sem_thread.c \
	philo_life_b.c \
	print_b.c \
# 	eat.c

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

clean:
	@rm -rf $(BUILD_DIR)
	@echo "clean obj/"

fclean: clean
	rm -rf $(NAME)
	rm -rf philo_bonus/ $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
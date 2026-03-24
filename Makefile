#COMPILE_______________________
CC = cc
CFLAGS = $(ALL_INCLUDES) -Wall -Wextra -Werror -MMD -MP -g
MAKEFLAGS += --no-print-directory

HEADER = philo.h

NAME = philo

#INCLUDES______________________

INCLUDE = include/

BUILD_DIR = obj/
SRC_DIR = src/

#SRC___________________________

SRC=main.c \
	muthread.c \
	philo_life.c \
	print.c \
	utils.c \
	error_mngmt.c \
	time.c

#OBJ___________________________

OBJ = $(SRC:%.c=$(BUILD_DIR)%.o)
DEPS = $(SRC:%.c=$(BUILD_DIR)%.d)
OBJ_DIR = $(sort $(shell dirname $(OBJ)))

#_________________________________

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "link philo"
	@echo "./philo nb_of_philo time_to_die time_to_eat time_to_sleep nb_of_meal"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)
	@echo "clean obj/"

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
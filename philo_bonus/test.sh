#!/bin/bash

PHILO_BIN_HELGRIND="valgrind --tool=helgrind --history-level=approx ./philo_bonus"
PHILO_BIN_VALGRIND="valgrind ./philo_bonus"
PHILO_BIN=./philo_bonus
TIME_OUT=10s
TIME_OUT_ERROR_CODE=124

VALID_COLOR="\x1b[32m"
ERROR_COLOR="\x1b[31m"
NC="\x1b[0m"

run_philo_with_timeout() {
		timeout "$TIME_OUT" "$@"
}

run_philo_classic() {
		run_philo_with_timeout $PHILO_BIN "$@"
}

run_philo_valgrind() {
		run_philo_with_timeout $PHILO_BIN_VALGRIND "$@"
}

run_philo_helgrind() {
		run_philo_with_timeout $PHILO_BIN "$@"
}

should_die_classic() {
		local output
		local status

		output=$(run_philo_classic "$@")
		status=$?
		if printf "$output" | grep -q "died" && [[ "$status" -ne $TIME_OUT_ERROR_CODE ]]; then
				printf "${VALID_COLOR}c\'est la mort qui t\'as assassine Marcia ${NC}\n"
		else
				printf "${ERROR_COLOR}t\'es pas mort {$NC}\n"
				exit 1
		fi
}

valgrind_test() {
		local output

		output=$(run_philo_valgrind "$@" 2>&1)
		if ! printf "$output" | grep -q "LEAK SUMMARY"; then
				printf "${VALID_COLOR}valgrind is Gulli Good\n${NC}"
		else
				printf "${ERROR_COLOR}valgrind is not Gulli Good\n${NC}"
				exit 1
		fi
}

helgrind_test() {
		local ouptut

		output=$(run_philo_helgrind "$@" 2>&1)
		if ! printf "$output" | grep -q "data"; then
				printf "${VALID_COLOR}helgrind is Gulli Good\n${NC}"
		else
				printf "${VALID_COLOR}helgrind is not Gulli Good\n${NC}"
				exit 1
		fi
}

should_die() {
		echo "testing $*"
		should_die_classic "$@"
		valgrind_test "$@"
		helgrind_test "$@"
}

should_not_die() {
		local output
		local status

		echo "testing $*"
		output=$(run_philo_classic "$@")
		status=$?
		if ! printf "$output" | grep -q "died" && [[ "$status" -eq $TIME_OUT_ERROR_CODE ]]; then
				printf "${VALID_COLOR}toujours debout ${NC}\n"
		elif printf "$output" | grep -q "eaten" && [[ "$status" -ne $TIME_OUT_ERROR_CODE ]]; then
				printf "${VALID_COLOR}tout le monde a bien mangé\n${NC}"
		else
				printf "${ERROR_COLOR}t\'es mort ${NC}\n"
				exit 1
		fi
}

should_die 1 800 200 200
should_not_die 5 800 200 200
should_not_die 5 800 200 200 7
should_die 4 310 200 100
should_not_die 4 410 200 200

exit 0

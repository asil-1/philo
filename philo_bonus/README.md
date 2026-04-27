*This project has been created as part of the 42 curriculum by ldepenne*

## Description

You must keep the philosophers alive. They must eat, think and sleep every day. To eat, they have as many forks as there are philosophers, but they cannot eat unless they are holding two forks. They must therefore pick them up and put them down before and after eating.

I use one thread for each processes to check the death.
This time I will use semaphores instead of mutex.

## Instruction

compile with `make`.

The programme requires several arguments:

`./philo_bonus nb_of_philo time_to_die time_to_eat
time_to_sleep nb_of_meal`

◦ nb_of_philo: The number of philosophers and also the number of forks.

◦ time_to_die (in milliseconds): the time a philosopher has between eah meal before to death

◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.

◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ nb_of_meal (optional argument): number of times the philosophers must eat before the simulation stops.
If not specified, the simulation stops when a philosopher dies.

warning: the specific topic that the examiner must not test more than 200 philosophy.

## Ressource

Use of the manuals. And use of AI to supplement the information in the manuals for the sem_open(), sem_close() and sem_unlink() functions, with an example
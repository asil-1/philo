*This project has been created as part of the 42 curriculum by ldepenne*

## Technology

The aim of this project is to learn how to use semaphores and to review the concurrent execution of different processes.

Semaphores are data structures containing an integer that we can manipulate using various functions. They are used to synchronise processes or threads. We can think of them as green or red traffic lights, granting or denying access to data depending on available resources.

## Project Description

We have several philosophers represented by processes (one philosopher = one process). They must eat, sleep and think during the day. The duration of each action (or thinking) must be entered as a parameter when the programme is launched* (see [instructions](#instruction)).

However, to eat, a philosopher needs two forks but only has one.
All forks are placed in the centre of the table and managed by a semaphore.


## Instruction

compile with `make`.

The programme requires several arguments:

```bash
./philo_bonus nb_of_philo time_to_die time_to_eat time_to_sleep nb_of_meal
```

◦ nb_of_philo: The number of philosophers and also the number of forks.

◦ time_to_die (in milliseconds): the time a philosopher has between eah meal before to death

◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.

◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ nb_of_meal (optional argument): number of times the philosophers must eat before the simulation stops.
If not specified, the simulation stops when a philosopher dies.

warning: the specific topic that the examiner must not test more than 200 philosophy.

## Ressource

- [subject](https://cdn.intra.42.fr/pdf/pdf/198989/en.subject.pdf)

Use of the manuals. And use of AI to supplement the information in the manuals for the sem_open(), sem_close() and sem_unlink() functions, with an example
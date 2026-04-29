*This project has been created as part of the 42 curriculum by ldepenne*

## Technology

The aim of this project is to learn how to use threads and mutexes.

Threads exist within a single parent process; they enable programming to be approached not sequentially, but concurrently.

Mutexes are used to ‘control’ these threads using the principle of mutual exclusion. They function like locks that grant access to data only if it is not already in use.

## Project Description

To do this, we have several philosophers represented by threads (one philosopher = one thread). They must eat, sleep and think during the day. The duration of each action (or thinking) must be entered as a parameter when the programme is launched* (see [instructions](#instruction)).

However, to eat, a philosopher needs two forks but only has one. They must share their fork with their neighbour on the right or left. The forks are therefore represented by mutexes.

## Instruction

compile with `make`.

The programme requires several arguments:

```bash
./philo nb_of_philo time_to_die time_to_eat time_to_sleep nb_of_meal
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

- [understanding of the subject](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2)

- [thread and data race](https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/#une-situation-de-comp%C3%A9tition--le-data-race)

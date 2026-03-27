*This project has been created as part of the 42 curriculum by ldepenne*

## Description

Here are the key things you need to know to succeed in this assignment:

• One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.

• The philosophers take turns eating, thinking, and sleeping.
While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.

• There are also forks on the table. There are as many forks as philosophers.

• Since eating spaghetti with just one fork is impractical, a philosopher must pick up both the fork to their right and the fork to their left before eating.

• When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.

• Every philosopher needs to eat and should never starve.

• Philosophers do not communicate with each other.

• Philosophers do not know if another philosopher is about to die.

• Needless to say, philosophers should avoid dying!

## Instruction

compile with `make`.

The programme requires several arguments:

`./philo nb_of_philo time_to_die time_to_eat
time_to_sleep nb_of_meal`

◦ nb_of_philo: The number of philosophers and also the number of forks.

◦ time_to_die (in milliseconds): the time a philosopher has between eah meal before to death

◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.

◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

◦ nb_of_meal (optional argument): number of times the philosophers must eat before the simulation stops.
If not specified, the simulation stops when a philosopher dies.

warning: the specific topic that the examiner must not test more than 200 philosophy.

## Ressource

thread and data race: https://www.codequoi.com/threads-mutex-et-programmation-concurrente-en-c/#une-situation-de-comp%C3%A9tition--le-data-race

understanding of the subject: https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2

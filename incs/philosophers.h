
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
/* Dependencies */
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

/*============================================================================*/
/*===========================|  Structures  |================================ */
/*============================================================================*/
enum dinner_state 
{
    PREPARING,
    DINNING,
    ENDED
};

enum rules 
{
    NUMBER_OF_PHILOS,
    TIME_TO_DIE,
    TIME_TO_EAT,
    TIME_TO_SLEEP,
    MAX_TIMES_TO_EAT
};

typedef struct s_table
{
    enum    dinner_state;
    int     num_of_philos;
    int     rules[5];
    t_philo *philos;
    int     *forks;
}   t_table;

enum philo_state
{
    EATING,
    SLEEPING,
    THINKING,
    DIED
};

typedef struct s_philo
{
    pthread_t *tself;
    enum    philo_state;
    int     indx;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     times_eat;
    int     times_slept;
    int     times_thought;
    int     fork_indx;
}   t_philo;

/*============================================================================*/
/*===========================|   Protoypes  |================================ */
/*============================================================================*/
/*____________________________________________________________________________*/
/*       	...Dinner Init...		                                          */

#endif
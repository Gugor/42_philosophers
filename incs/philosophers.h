
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
/* Dependencies */
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define BLD_BLACK  "\33[1;30m"
# define BLD_RED  "\33[1;31m"
# define BLD_GREEN  "\33[1;32m"
# define BLD_YELLOW  "\33[1;33m"
# define BLD_BLUE  "\33[1;34m"
# define BLD_MAGENTA  "\33[1;35m"
# define BLD_CYAN  "\33[1;36m"
# define BLD_WHITE  "\33[1;37m"
# define RESET  "\33[0m"
/*============================================================================*/
/*===========================|  Structures  |================================ */
/*============================================================================*/
typedef enum e_dinner_state 
{
	PREPARING,
	DINNING,
	ENDED
}   t_dinner_state;

typedef enum e_rules 
{
	NUMBER_OF_PHILOS,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	MAX_TIMES_TO_EAT
}   t_rules;

typedef struct s_settings 
{
	int num_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int max_meals_to_eat;
}   t_settings;

typedef enum philo_state
{
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_philo_state;

typedef struct s_philo
{
	pthread_t 		*tself;
	t_philo_state	state;
	int     		indx;
	int     		time_to_die;
	int     		time_to_eat;
	int     		time_to_sleep;
	int     		times_eat;
	int     		times_slept;
	int     		times_thought;
	int     		fork_indx;
}   t_philo;

typedef struct s_dinner
{
	t_dinner_state  state;
	t_philo         *philos;
	pthread_mutex_t *forks;
	t_settings      *settings;
	int             deads;
	int             meals_served;
	int             times_splept;
	int             times_thought;
	int             dinner_duration;
}   t_dinner;


/*============================================================================*/
/*===========================|   Protoypes  |================================ */
/*============================================================================*/
/*____________________________________________________________________________*/
/*       	...Dinner Init...		                                          */

/*____________________________________________________________________________*/
/*       	...Utils ...    		                                          */
int			ft_isspace(char c);
int			ft_atoi(const char *str);
int			is_valid_digit(char *str);

/*____________________________________________________________________________*/
/*       	...Error Handler ...    		                                  */
void		print_settings_err(int err);
#endif

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
/* Dependencies */
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <errno.h>
# include <sys/time.h>
# include <stdint.h>

# define BLD_BLACK  "\33[1;30m"
# define BLD_RED  "\33[1;31m"
# define RED  "\33[31m"
# define BLD_GREEN  "\33[1;32m"
# define BLD_YELLOW  "\33[1;33m"
# define BLD_BLUE  "\33[1;34m"
# define BLD_MAGENTA  "\33[1;35m"
# define MAGENTA  "\33[35m"
# define BLD_CYAN  "\33[1;36m"
# define BLD_WHITE  "\33[1;37m"
# define WHITE  "\33[37m"
# define RESET  "\33[0m"

# define MS_TIME_DIE_ERR_MSG  " %s - ⚰️  [time_to_die]%s should be %s≥ 60ms%s\
 in order the simulation to work.\n"
# define MS_TIME_EAT_ERR_MSG  " %s- 🍽️  [time_to_eat]%s should be %s≥ 60ms%s\
 in order the simulation to work.\n"
# define MS_TIME_SLEEP_ERR_MSG  " %s - 🛌  [time_to_sleep]%s should be %s≥ 60ms%s\
 in order the simulation to work.\n"

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
	STOPED,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_philo_state;

typedef enum e_leading_hand
{
	LEFT,
	RIGHT
}	t_leading_hand;

typedef struct s_waiter
{
	t_dinner_state	state;
	int				deads;
}	t_waiter;

typedef struct s_philo
{
	int     		indx;
	pthread_t 		pthread;
	pthread_mutex_t *left_hand;
	pthread_mutex_t *right_hand;
	t_philo_state	state;
	t_leading_hand	ld_hand;	
	int64_t 		time_to_die;
	int64_t 		time_to_eat;
	int64_t 		time_last_meal;
	int64_t 		time_to_sleep;
	int64_t			time_alive;
	int64_t			birth;
	t_waiter		*waiter;
	int     		times_eaten;
	int     		times_slept;
	int     		times_thought;
}   t_philo;

typedef struct s_dinner
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	t_settings		*settings;
	int64_t			start_tm;
	int				meals_served;
	int				times_splept;
	int				times_thought;
	int64_t			dinner_duration;
}   t_dinner;


/*============================================================================*/
/*===========================|   Protoypes  |================================ */
/*============================================================================*/
/*____________________________________________________________________________*/
/*       	...Init...  		                                          */
int			init_dinner(int ac, char **av, t_dinner *dinner, t_settings *settings);
int			init_settings(int ac, char **av, t_settings **sts);
int			create_forks(pthread_mutex_t **forks, int amount);

/*____________________________________________________________________________*/
/*       	...Settings...  		                                          */
int			set_sttng_val(int *set, char *val, int err);
int			check_settings(t_settings *sts);
int			check_sttng(int set, int condition, int err);

/*____________________________________________________________________________*/
/*       	...Utils ...    		                                          */
int			ft_isspace(char c);
int			ft_atoi(const char *str);
int			is_valid_digit(char *str);

/*____________________________________________________________________________*/
/*       	...Error Handler ...    		                                  */
void		printf_usage_error();
void		print_settings_err(int err);

/*____________________________________________________________________________*/
/*       	...Memory Handler ...    		                                  */
void		destroy_forks(pthread_mutex_t **data, int amount);
void		destroy_philos(t_philo **philos, int amount);
void		clear_dinner(t_dinner **dinner);

/*____________________________________________________________________________*/
/*       	...Philo ...            		                                  */
int			create_philos(t_dinner *dinner, t_waiter *waiter);
t_philo		*init_philo(int indx, t_philo *philo, t_settings *stts,
			t_waiter *wtr);

/*____________________________________________________________________________*/
/*       	...Dinner Time ...    		                                  */
int64_t	set_dinner_time(t_dinner *dinner);
int64_t	get_elapsed_time(int64_t start, char precision);
int64_t	get_current_time(char precision);
int64_t	update_elapsed_time_to(int64_t*new, int64_t start, char precision);

/*____________________________________________________________________________*/
/*       	...Dinner Time ...    		                                  */
void		*dinning(void *data);
#endif
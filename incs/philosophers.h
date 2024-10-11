/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:31:16 by hmontoya          #+#    #+#             */
/*   Updated: 2024/10/11 15:14:46 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <unistd.h>

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
}	t_dinner_state;

typedef enum e_rules
{
	NUMBER_OF_PHILOS,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	MAX_TIMES_TO_EAT
}	t_rules;

typedef struct s_settings
{
	int	num_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	min_meals_to_eat;
}	t_settings;

typedef enum philo_state
{
	STOPED,
	EATING,
	SLEEPING,
	THINKING,
	FULL,
	FORK_LEFT,
	FORK_RIGHT,
	PUT_LEFT,
	PUT_RIGHT,
	DIED
}	t_philo_state;

typedef enum e_leading_hand
{
	LEFT,
	RIGHT,
}	t_ph_hand;

typedef struct s_waiter
{
	t_dinner_state	state;
	pthread_mutex_t	mt_state;
	pthread_mutex_t	mt_print;
	pthread_mutex_t	mt_whoisdead;
	int				whoisdead;
	int64_t			time_of_death;
	int64_t			dinner_start;
	pthread_mutex_t	mt_start;
	int				philos_full;
	pthread_mutex_t	mt_phfull;
}	t_waiter;

typedef struct s_philo
{
	int				indx;
	pthread_t		pthread;
	pthread_mutex_t	*left_hand;
	pthread_mutex_t	*right_hand;
	pthread_mutex_t	mt_lstml;
	pthread_mutex_t	mt_ttd;
	pthread_mutex_t	mt_tod;
	pthread_mutex_t	mt_state;
	t_philo_state	state;
	t_ph_hand		leader_hand;	
	int64_t			time_to_die;
	int64_t			time_to_eat;
	int64_t			time_last_meal;
	int64_t			time_to_sleep;
	int64_t			time_alive;
	int64_t			time_of_death;
	int64_t			birth;
	t_waiter		*waiter;
	int				times_eaten;
	int				min_meals_to_eat;
	int				times_slept;
	int				times_thought;
}	t_philo;

typedef struct s_dinner
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mt_waiter;
	pthread_t		waiterer;
	t_settings		*settings;
	int64_t			start_tm;
	int				meals_served;
	int				times_splept;
	int				times_thought;
	int64_t			dinner_duration;
}	t_dinner;

/*============================================================================*/
/*===========================|   Protoypes  |================================ */
/*============================================================================*/
/*____________________________________________________________________________*/
/*       	...Init...  		                                          */
int			init_dinner(int ac, char **av, t_dinner *dinner,
				t_settings *settings);
int			init_settings(int ac, char **av, t_settings **sts);
int			create_forks(pthread_mutex_t **forks, int amount);
void		init_waiter(t_waiter *wtr, t_dinner *dinner);
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
void		printf_usage_error(void);
void		print_settings_err(int err);
/*____________________________________________________________________________*/
/*       	...Memory Handler ...    		                                  */
void		destroy_forks(pthread_mutex_t **data, int amount);
void		destroy_philos(t_philo **philos, int amount);
void		clear_dinner(t_dinner *dinner, int freemode);
/*____________________________________________________________________________*/
/*       	...Philo ...            		                                  */
int			register_philos(t_dinner *dinner, t_waiter *waiter);
void		unregister_philos(t_philo *philos, int num);
t_philo		*init_philo(int indx, t_philo *philo, t_dinner *dinner,
				t_waiter *wtr);
/*____________________________________________________________________________*/
/*       	...Dinner Time ...    		                                  */
int64_t		set_dinner_time(t_dinner *dinner);
int64_t		get_elapsed_time(int64_t start, char precision);
int64_t		get_current_time(char precision);
int64_t		update_elapsed_time_to(int64_t*new, int64_t start, char precision);
/*____________________________________________________________________________*/
/*       	...Routine  ...         		                                  */
int			has_eaten_enough(t_philo *this);
int			is_dead(t_philo *this);
void		*dinning(void *data);
/*____________________________________________________________________________*/
/*       	...Philos State ...      		                                  */
int			thinking(t_philo *philo);
int			sleeping(t_philo *philo);
int			eating(t_philo *philo);
/*____________________________________________________________________________*/
/*       	...Mutex Handler ...    		                                  */
int			check_dinner_state(t_philo *philo);
int			get_fork(t_philo *this, t_ph_hand hand);
void		put_fork(t_philo *this, t_ph_hand hand);
/*____________________________________________________________________________*/
/*       	...Message ...          		                                  */
void		print_format_death(t_philo *philo, int64_t tod,
				pthread_mutex_t *mt_print);
void		print(t_philo *philo, t_philo_state state);
/*____________________________________________________________________________*/
/*       	...Philo Wait ...       		                                  */
int			philo_uwait(int64_t mcs);
/*____________________________________________________________________________*/
/*       	...Waiter Setters...       		                                  */
void		set_waiter_pfull(t_waiter *waiter);
void		set_waiter_state(t_waiter *waiter, t_dinner_state newstate);
/*____________________________________________________________________________*/
/*       	...Waiter Getters...       		                                  */
int			get_waiter_pfull(t_waiter *waiter);
int			get_waiter_state(t_waiter *wtr);
int			get_whoisdead(t_waiter *waiter);
int			get_waiter_whoisdead(t_waiter *waiter);
/*____________________________________________________________________________*/
/*       	...Philo Getters...       		                                  */
int64_t		get_philo_lstml(t_philo *this);
int64_t		get_philo_tod(t_philo *this);
int64_t		get_philo_ttd(t_philo *this);
int64_t		get_philo_state(t_philo *this);
/*____________________________________________________________________________*/
/*       	...Philo Setters...       		                                  */
void		set_philo_lstml(t_philo *this);
void		set_philo_state(t_philo *this, t_philo_state state);
#endif
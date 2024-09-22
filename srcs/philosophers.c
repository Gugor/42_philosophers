
#include <pthread.h>
/**
 * @brief It's a program that create multiple threads. This thread are Philosophers 
 * that eat, sleep, think and died. 
 * ============================================
 * Workflow :
 * ============================================
 * init_data() => the data passed from arguments
 * put_table()
 *  |-> create_philosophers(table)
 *  |-> create_forks(table)
 * serve_dinner(table)
 *  |-> check_philosophers_action(philos, forks)
 *  |----> can_eat(philo)
 *  |----> set_new_state(philo)
 *  |----------> eating
 *  |----------> sleeping
 *  |----------> thinking
 *  |----------> died
 *  |----> all_have_eat_enough()
 *  |----> has_died()
 *  |--------> end_dinner()
 * =============================================
 * Dinner Data
 * =============================================
 * typedef struct s_table
 * {
 *      enum dinner_state; (preparing, dinning, ended)
 *      t_philo *philos;
 *      int       *forks;
 * }    t_table;
 * 
 * typedef struct s_philo
 * {
 *      pthread *tself;
 *      enum    philo_state;
 *      int     times_eat;
 *      int     times_slept;
 *      int     times_thought;
 *      int     fork_indx;
 * }    t_philo;
*/
int main(int ac, char **av)
{

    if (ac < 4)
        return (1);
    **av = 0;
    return (0);
}
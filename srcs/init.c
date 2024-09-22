
#include "philosophers.h"

/**
* @brief It initialize the data for philosophers program
* @param table `{t_table *}` a pointer to the t_table structure
* @returns `{void}`
* void 
*/
void init_dinner(t_table *table, char **args)
{
    table->philos = NULL;
    table->forks = NULL;
}
#include "header.h"

int create_thread(int num_tread, int rand_num, t_thread **thread)
{
	int i;
	*thread = malloc(sizeof(t_thread) * num_tread);
	if (*thread == NULL)
		return (0);
	i = 0;
	while(i < num_tread)
	{
		(*thread)[i].id = i + 1;
		(*thread)[i].index = 0;
		(*thread)[i].num = 0;
		(*thread)[i].cant = rand_num;

		if (pthread_create(&(*thread)[i].thread, NULL, ft_rutine, (void *)&(*thread)[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

void ft_free_thread(t_thread **thread)
{
	if (*thread)
		free(*thread);
	*thread = NULL;
}

void	wait_thread(t_thread *thread, int num_thread)
{
	int	i;

	i = 0;
	while (i < num_thread)
	{
		pthread_join(thread[i].thread, NULL);
		i++;
	}
}
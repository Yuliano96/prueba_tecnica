#include "header.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
t_node *list_neg = NULL;
t_node *list_pos = NULL;

void *ft_rutine(void *arg)
{
	t_thread	*thread;

	thread = (t_thread *)arg;
	while (thread->index < thread->cant)
	{
		thread->num = random_int();
		pthread_mutex_lock(&mutex);
		if (thread->num >= 0)
			add_list(&list_pos, thread->num);
		else
			add_list(&list_neg, thread->num);
		pthread_mutex_unlock(&mutex);
		thread->index++;
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	int			num_thread;
	int			rand_num;
	t_thread	*thread;

	thread = NULL;
	if (argc != 3)
	{
		write(2,
			"Uso: ./program <num_hilos> <nums_por_hilo>\n",
			43);
		return (1);
	}
	srand(time(NULL));
	if (!is_positive_number(argv[1]) || !is_positive_number(argv[2]))
	{
		write(2,
			"Error: los argumentos deben ser numeros positivos.\n",
			51);
		return (1);
	}
	num_thread = atoi(argv[1]);
	rand_num = atoi(argv[2]);
	if (num_thread <= 0 || rand_num <= 0)
	{
		write(2,
			"Error: num_hilos y nums_por_hilo deben ser > 0.\n",
			48);
		return (1);
	}
	if (create_thread(num_thread, rand_num, &thread) == 0)
	{
		ft_free_thread(&thread);
		write(2, "error creating threads\n", 23);
		return (1);
	}
	wait_thread(thread, num_thread);
	pthread_mutex_destroy(&mutex);
	buble_sort(list_pos);
	print_list(list_pos);
	buble_sort(list_neg);
	print_list(list_neg);
	ft_free_list(list_pos);
	ft_free_list(list_neg);
	ft_free_thread(&thread);
	return (0);
}

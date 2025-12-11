# ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>

typedef struct s_nodo
{
	int n;
	struct s_nodo *next;
}	t_node;

typedef struct s_thread
{
	pthread_t		thread;
	int				index;
	int				num;
	int				id;
	int				cant;
}	t_thread;


t_node	*create_node(int n);
void add_list(t_node **list, int n);
void ft_free_list(t_node *list);
int random_int();
void ft_free_thread(t_thread **thread);
void *ft_rutine(void *arg);
int create_thread(int num_tread, int rand_num, t_thread **thread);
void	wait_thread(t_thread *thread, int num_thread);
void print_list(t_node *list);
int	is_positive_number(const char *str);
void ft_swap(int *num1, int *num2);
void buble_sort(t_node *list);
#endif
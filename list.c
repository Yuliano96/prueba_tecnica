#include "header.h"

t_node *create_node(int n)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = NULL;
	return (node);
}

void add_list(t_node **list, int n)
{
	t_node	*node;

	node = create_node(n);
	if (!node)
		return ;
	if (*list == NULL)
		*list = node;
	else
	{
		node->next = *list;
		*list = node;
	}
}

void ft_free_list(t_node *list)
{
	t_node *aux;
	t_node *temp;

	if (list == NULL)
		return ;
	aux = list;
	while (aux != NULL)
	{
		temp = aux;
		aux = aux->next;
		free(temp);
	}
}

void print_list(t_node *list)
{
	t_node *aux;

	if (list == NULL)
		return;
	aux = list;
	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
	printf("\n");
}

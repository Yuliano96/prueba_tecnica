#include "header.h"

int random_int()
{
    return rand() - (RAND_MAX / 2);
}



void ft_swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void buble_sort(t_node *list)
{
	int		flag;
	t_node	*temp;
	
	if (list == NULL || list->next == NULL)
		return ;
	flag = 0;
	while (flag == 0)
	{
		flag = 1;
		temp = list;
		while (temp->next != NULL)
		{
			if (temp->n > temp->next->n)
			{
				ft_swap(&temp->n, &temp->next->n);
				flag = 0;
			}
			temp = temp->next;
		}
	}
}
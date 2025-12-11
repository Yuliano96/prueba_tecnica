#include "header.h"

int  g_tests_total = 0;
int  g_tests_failed = 0;

void print_result(const char *name, int ok)
{
    g_tests_total++;
    if (!ok)
    {
        g_tests_failed++;
        printf("[FAIL] %s\n", name);
    }
    else
        printf("[OK]   %s\n", name);
}


void test_is_positive_number(void)
{
    int ok;

    ok = 1;
    if (!is_positive_number("123"))
        ok = 0;
    if (!is_positive_number("0"))
        ok = 0;
    if (is_positive_number(""))
        ok = 0;
    if (is_positive_number("-1"))
        ok = 0;
    if (is_positive_number("12a3"))
        ok = 0;
    if (is_positive_number("   "))
        ok = 0;
    print_result("is_positive_number()", ok);
}

int check_sorted(t_node *list, int *expected, int len)
{
    int     i;
    t_node  *aux;

    i = 0;
    aux = list;
    while (i < len && aux != NULL)
    {
        if (aux->n != expected[i])
            return (0);
        aux = aux->next;
        i++;
    }
    if (i != len || aux != NULL)
        return (0);
    return (1);
}

void test_add_list_and_buble_sort(void)
{
    t_node  *list;
    int     ok;
    int     expected[5];

    list = NULL;
   
    add_list(&list, 3);
    add_list(&list, -1);
    add_list(&list, 5);
    add_list(&list, 0);
    add_list(&list, 2);
    buble_sort(list);
    
    expected[0] = -1;
    expected[1] = 0;
    expected[2] = 2;
    expected[3] = 3;
    expected[4] = 5;
    ok = check_sorted(list, expected, 5);
    print_result("add_list() + buble_sort()", ok);
    ft_free_list(list);
}


int main(void)
{
    printf("Ejecutando tests unitarios...\n\n");
    test_is_positive_number();
    test_add_list_and_buble_sort();

    printf("\nResumen: %d tests, %d fallados.\n",
        g_tests_total, g_tests_failed);
    if (g_tests_failed == 0)
        printf("Todos los tests han pasado correctamente.\n");
    else
        printf("Hay tests fallados. Revisa la implementación.\n");
    return (g_tests_failed != 0);
}

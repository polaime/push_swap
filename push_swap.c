#include "push_swap.h"

int    pushswap(int *stack_a, int limit)
{
    int     *stack_b;
    int     indice_a;
    int     indice_b;

    indice_a = 0;
    indice_b = 0;
    stack_b = malloc(limit * sizeof(int));
    if(!stack_b)
        return (NULL)
    while (stack_a[indice_a] != stack_a[indice_a + 1] || indice_b >= limit)
    {
        if (stack_a[indice_a] < stack_a[indice_a + 1]) 
            indice_a++;
        else
            indice_b = push_b(stack_a, stack_b, indice_a, indice_b);
    }
    return (stack_b);
}
int main(char *argv, int argc)
{
    int     i;
    int     j;
    int     *list;
        
    i = 1;
    list = malloc(argc - 1 * sizeof(int));
    if (!list)
        return (NULL);
    while(argc < i)
    {
        list[j] = ft_atoi(argv[i]);
        i++;
        j++;
    }
    list = push_swap(list, (argc - 1));
    return(list)
}

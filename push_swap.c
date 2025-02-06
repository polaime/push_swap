#include "push_swap.h"
// turc mecanique
int    *pushswap(int *stack_a, int limit)
{
    int     *stack_b;
    int     indice_a;
    int     indice_b;
    int     i;

	i = 1;
    indice_a = 0;
    indice_b = 0;
    stack_b = malloc(limit * sizeof(int));
    if(!stack_b)
        return (NULL);
    while (stack_a[indice_a] != stack_a[i] && indice_b <= limit -1)
	{
		if(stack_a[i] == stack_b[i])
		{
			while(stack_a[indice_a] == stack_b[indice_b])
				indice_a++;
		}
        while (stack_a[indice_a] < stack_a[i] && i <= limit - 1) 
			i++;
        if(stack_a[indice_a] > stack_a[i] && i != limit - 1)
        {
        	indice_a = i;
        	i = 0;
        }
        if (i == limit -1)
        {
            indice_b = push_b(stack_a, stack_b, indice_a, indice_b);
			indice_a = 1;
			pushswap(stack_a, limit);
        }
    }
    return (stack_b);
}
int main(int argc, char **argv)
{
    int     i;
    int     j;
    int     *list;
    
    j = 0;
    i = 1;
    list = malloc((argc - 1) * sizeof(int));
    if (!list)
        return (0);
    while(argc > i)
    {
        list[j] = ft_atoi((char *)argv[i]);
        i++;
        j++;
    }
    list = pushswap(list, (argc));
	i = 0;
	while (i != argc)
	{
		printf("%i", list[i]);
		i++;
	}
    return (0);
}

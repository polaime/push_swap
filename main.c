#include "push_swap.h" 
void utilitaire_du_main(char **argv, int *list, int argc, t_stack **stack_a)
{
    int     i;
    int     j;

    i = 1;
    j = 0;
    while (argc > i)
    {
        list[i] = ft_atoi((char *)argv[i]);
        t_stack *nouveau_noeud = malloc(sizeof(t_stack));
        if (!nouveau_noeud)
        {
            free (list);
            return;
        }
        nouveau_noeud ->value = list[j];
        nouveau_noeud ->next  = *stack_a;
        stack_a = nouveau_noeud;
        i++;
        j++;
    }
}
int main(int argc, char **argv)
{
    int     i;
    int     *list;
    int     *result;
    
    i = 0;
    t_stack stack_a = NULL
    list = malloc((argc - 1) * sizeof(int));
    if (!list)
        return (1);
    utilitaire_du_main(argv, list, &stack_a, argc);
    result = pushswap(stack_a, (argc - 1));
	if(!result)
        return (free (list),1);
	while (i <= argc -1)
	{
		printf("%i", result[i]);
		i++;
	}
    return (0);
}

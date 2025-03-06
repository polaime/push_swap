#include "push_swap.h"

void utilitaire_du_main(char **argv, int *list, int argc, t_stack **stack_a)
{
    int     i;
    int     j;

    i = 1;
    j = 0;
    t_stack *dernier = NULL;
    while (argc > i)
    {
        list[j] = ft_atoi((char *)argv[i]);
        t_stack *nouveau_noeud = malloc(sizeof(t_stack));
        if (!nouveau_noeud)
            return(free (list));
        nouveau_noeud ->value = list[j];
        nouveau_noeud ->next  = NULL;
        if(*stack_a == NULL)
            *stack_a = nouveau_noeud;
        else
            dernier-> next = nouveau_noeud;
        dernier = nouveau_noeud;
        i++;
        j++;
    }
}
void free_stack(t_stack *stack)
{
    t_stack *tmp;
    while (stack != NULL)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}
void print_stack(t_stack *stack)
{
    t_stack *current = stack;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
int main(int argc, char **argv)
{
    int     *list;

    if(argc < 2)
        return (0);
    t_stack *stack_a = NULL;
    list = malloc((argc - 1) * sizeof(int));
    if (!list)
        return (1);
    utilitaire_du_main(argv, list, argc, &stack_a);
    stack_a = push_swap(&stack_a, argc - 1);
	print_stack(stack_a);
    free (list);
    free_stack(stack_a);
    return (0);
}

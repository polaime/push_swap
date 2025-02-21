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
        *stack_a = nouveau_noeud;
        i++;
        j++;
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
    stack_a = push_swap(&stack_a);
	print_stack(stack_a);
    return (0);
}

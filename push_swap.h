#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_stack
{
    int value;
    struct s_stack *previous;
    struct s_stack *next;
}
t_stack;
typedef struct s_data
{
    t_stack stack_a;
}
t_data;

t_stack     *push_swap(t_stack **stack_a, int size);
int         main(int argc, char **argv);
int         push_b(t_stack **stack_a, t_stack **stack_b);
int         push_a(t_stack **stack_a, t_stack **stack_b);
int         swap_a(t_stack **stack_a);
void        swap_b(t_stack **stack_b);
void	    ft_putstr(char *s);
int	        ft_atoi(char *str);
t_stack     *utils_algo(t_stack *stack_a, int i);
int         rotate_a(t_stack **stack_a);
void        print_stack(t_stack *stack);
int         calcul_min(t_stack *stack_a, int i);
int         calcul_max(t_stack *stack_a);
int         push (t_stack **src, t_stack ** dest);
int         rotate_b(t_stack **stack_b);
t_stack     *sort_for_3(t_stack *stack_a, int size);
int         verif_tri(t_stack *stack_a);
int         find_median(t_stack *stack_a, int size);
t_stack     *sort_for_10(t_stack *stack_a, int size);
int         ft_isdigit(char c);
int	        reverse_rotate_a(t_stack **stack_a);

#endif
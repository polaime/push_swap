#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_stack
{
    int value;
    struct s_stack *next;
}
t_stack;
typedef struct s_data
{
    t_stack stack_a;
    t_stack stack_b;
    int size_a;
    int size_b;
}
t_data;

int         *push_swap(t_stack *stack_a, int limit);
int         main(int argc, char **argv);
void        push_b(t_stack **stack_a, t_stack **stack_b);
void        push_a(t_stack **stack_a, t_stack **stack_b);
void        swap_a(t_stack **stack_a);
void        swap_b(t_stack **stack_b);
void	    ft_putstr(char *s);
int	        ft_atoi(char *str);

#endif
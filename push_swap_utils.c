#include "push_swap.h"

int push_b(int *stack_a, int *stack_b, int indice_a, int indice_b)
{
   stack_b[indice_b] = stack_a[indice_a];
   ft_putstr("pb\n");
   return(indice_b + 1); 
}
int push_a(int *stack_a, int *stack_b, int indice_a, int indice_b)
{
   stack_a[indice_a] = stack_b[indice_b];
   ft_putstr("pa");
   return(indice_a); 
}
void swap_a(int *stack_a, int *stack_b, int indice_a, int indice_b)
{
   int tmp;

   tmp = stack_a[1];
   stack_a[1] = stack_a[0];
   stack_a[0] = tmp;
   ft_putstr("sa"); 
}
void swap_b(int *stack_a, int *stack_b, int indice_a, int indice_b)
{
   int tmp;

   tmp = stack_b[1];
   stack_b[1] = stack_b[0];
   stack_b[0] = tmp;
   ft_putstr("sb"); 
}
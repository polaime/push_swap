#include "push_swap.h"

int push_b(int *stack_a, int *stack_b, int indice_a, int indice_b)
{
   stack_b[indice_b] = stack_a[indice_a];
   ft_putstr("pb");
   return(indice_b); 
}
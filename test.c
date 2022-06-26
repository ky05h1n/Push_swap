#include <stdio.h>
#include <stdlib.h>

int    tdm_arr_len(int **arr)
{
    int    a;

    a = 0;
    if (!arr[0])
      return (0);
    while (arr[a] != NULL)
        a++;
    return (a);
}

int **pop_stack(int **stack)
{
  int a;
  int size;
  int **stack_pop;
  int m;
  a = 0;
  m = 1;
  size = tdm_arr_len(stack);
  if (size == 0)
  {
    free(stack);
    stack = malloc(1 * sizeof(int *));
    stack[0] = NULL;
    return (stack);
  }
  stack_pop = malloc(size * sizeof(int *));
  while(a < size)
  {
    stack_pop[a] = stack[m];
    m++;
    a++;
  }
  free(stack);
  stack = stack_pop;
  return(stack);
  
}
int    **take_push(int **stack1, int **stack2)
{
    int    **new_stack;
    int    size;
    int    idx;
    int   ndx = 0;

    idx = 0;
    size = tdm_arr_len(stack1) + 2;
    new_stack = malloc(size * sizeof(int *));
    new_stack[size - 1] = NULL;
    new_stack[idx] = stack2[idx];
    if (tdm_arr_len(stack1) == 0)
    {
      free(stack1);
      stack1 = new_stack;
      return(stack1);
    }
    idx++;
    while (idx < size - 1)
    {
        new_stack[idx] = stack1[ndx];
        ndx++;
        idx++;
    }
    new_stack[idx] = NULL;
    free(stack1);
    stack1 = new_stack;
    return (stack1);
}


int main() {
  
  int **stack_a;
  int **stack_b;
  int n = 0;
  int a = 0;
  
  stack_a = malloc(4 * sizeof(int *));
  stack_b = malloc(1 * sizeof(int *));
  stack_b[0] = NULL;
  
  int ptr[] = {1 , 2, 3};
  
  while (a < 3)
  {
    stack_a[a] = &ptr[a];
    a++;
   }
  stack_a[a] = NULL;
  while (stack_a[n] != NULL)
    {
        stack_b = take_push(stack_b, stack_a);
        stack_a = pop_stack(stack_a);
  }
  n = 0;
    while (stack_b[n] != NULL)
    {
        stack_a = take_push(stack_a, stack_b);
        stack_b = pop_stack(stack_b);
  }
  // while (stack_a[n] != NULL)
  // {
  //   printf("%d ", stack_a[n][0]);
  //   n++;
  // }
  printf("\n");
  n = 0;
  while (stack_a[n] != NULL)
  {
     printf("%d ", stack_a[n][0]);
     n++;
  }
  return 0;
}
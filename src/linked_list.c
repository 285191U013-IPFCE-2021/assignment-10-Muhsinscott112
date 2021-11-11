#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != &SENTINEL_node)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}
.....

/* print list to console */
void print_list (node * p)
{
    // Add your code for exercise 1
    // There is NO testcode for this

if (p->next == 0)
return;
printf("%d", p->value);
print_list(p->next);

}

int sum_squares (node * p)
{
    // Add your code for excercise 2
    // You can find the tests in tests.cpp

int sum = 0;

sum += square(p->value);

if (p->next->next != 0)
  sum += sum_squares(p->next);
return (sum);
}

node *map (node * p, int (*f) (int))
{
    // Add your code for excercise 3

node *new_node = malloc(sizeof(node));

new_node->value = f(p->value);

if (p->next->next != 0)
  new_node->next = map (p->next,f);
else 
  new_node->next = &SENTINEL_node;

    return (new_node);
}


int square (int x)
{
  return x * x;
}

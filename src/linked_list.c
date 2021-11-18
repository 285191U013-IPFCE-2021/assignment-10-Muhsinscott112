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


/* print list to console */
void print_list (node * p)
{
    // Add your code for exercise 1
    // There is NO testcode for this

if (p->next == NULL) // if next node is NULL, funtion is exited
return;
printf("%d\n", p->value); // prints value of node
print_list(p->next); // recursive call

}

int sum_squares (node * p)
{
    // Add your code for excercise 2
    // You can find the tests in tests.cpp

int sum = 0; // initialization of sum

sum += square(p->value); // squared value of node is added to sum

if (p->next->next != 0)
  sum += sum_squares(p->next);
return (sum);
}

node *map (node * p, int (*f) (int))
{
    // Add your code for excercise 3

node *new_node = malloc(sizeof(node)); // memory allocation of new node

new_node->value = f(p->value); // new_node points to same value as p

if (p->next->next != 0) // if 2x next node is nonzero:
  new_node->next = map (p->next,f); // recursive call with next node passed into function, stored into 
  // next node in list that new_node points to
else 
  new_node->next = &SENTINEL_node; // if next node is zero, address of terminal node is stored into it

    return (new_node); 
}

int square (int x)
{
  return x * x;
}

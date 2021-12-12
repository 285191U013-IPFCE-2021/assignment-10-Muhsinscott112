#include "btree.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct tree_node *Insert(int x, struct tree_node *t)
{
  // Insert item x into the tree t

  struct tree_node *root = t;

  if (root == NULL)
  { // when the end of a tree is reached, a new node is inserted
    root = malloc(sizeof(struct tree_node));

    root->item = x;
    root->left = NULL;
    root->right = NULL;
    return root;
  }

  if (x <= root->item) // going through the tree until a pointer that is NULL has been reached with the help of a recursive call
  {
    root->left = Insert(x, root->left);
  }
  if (x > root->item)
  {
    root->right = Insert(x, root->right);
  }

  return root;
}

struct tree_node *Remove(int x, struct tree_node *t)
{
  // Remove one item from the tree t

  struct tree_node *root = t;  // a pointer that goes through the tree
  struct tree_node *store = t; // a pointer that stores our node to "free"

  if (t->item == x) // our tree has to be reorganized if we reach an item that has to be removed
  {
    if (t->right == NULL && t->left == NULL) // if the pointers are equal to NULL, our node is removed
    {
      free(store);
      return NULL;
    }

    // if there is only one branch, then it is moved up our tree
    if (t->right == NULL && t->left != NULL)
    {
      t = t->left;
      free(store);
      return t;
    }
    if (t->right != NULL && t->left == NULL)
    { // same as before but with branch to the left
      t = t->right;
      free(store);
      return t;
    }

    if (t->right != NULL && t->left != NULL)
    {
      root = t->left; /* we want to find the biggest item of the smaller branch, which is to the left. We do this so that
      it does not have a number higher than t->item. */
      if (root->right == NULL)
      {
        t->item = root->item;
        t->left = root->left;
        free(root);
        return t;
      }
      else
      {

        while (root->right->right != NULL)
        {
          root = root->right;
        }

        t->item = root->right->item;
        store = root->right;
        root->right = root->right->left;
        free(store);
        return t;
      }
    }
  }
  // going through the tree until a pointer that is NULL has been reached with the help of a recursive call
  if (root->left != NULL && x <= root->item)
  {
    t->left = Remove(x, root->left);
  }

  if (root->right != NULL && x > root->item)
  {
    t->right = Remove(x, root->right);
  }
  return t;
}

int Contains(int x, struct tree_node *t)
{

  // Return true if the tree t contains item x. Return false otherwise.

  struct tree_node *root = t;
  int result = 0;

  if (Empty(t))
  {
    return result; // if our tree is empty, there is no item x in it
  }
  if (root->item == x)
  {
    return 1;
  }
  // going through the tree until a pointer that is NULL has been reached with the help of a recursive call
  if (root->left != NULL && x <= root->item)
  {
    result = Contains(x, root->left);
  }

  if (root->right != NULL && x > root->item)
  {
    result = Contains(x, root->right);
  }
  return result;
}

struct tree_node *Initialize(struct tree_node *t)
{
  // Create an empty tree
  return NULL;
}

int Empty(struct tree_node *t)
{
  // Test if empty
  if (t == NULL)
  {
    return 1;
  }
  return 0;
}

int Full(struct tree_node *t)
{
  // Test if full
  return 0;
}


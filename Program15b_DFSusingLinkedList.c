#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  struct node *left;
  bool visited;
  int data;
  struct node *right;
}
node;
node *tree;

typedef struct stack
{
  node *data;
  struct stack *next;
}
stack;
stack *Top = NULL, *A;

void create_tree(node *);
node *insertElement(node *, int);
void push(node *);
node *pop();
bool isEmpty();
void DepthFirstTraversal(node *);

void main()
{
  int option, val;
  node *ptr;
  create_tree(tree);
  do
  {
    printf("\n\nPROGRAM TO IMPLEMENT DEPTH FIRST TRAVERSAL ON BINARY SEARCH TREE USING LINKED LIST");
    printf("\n====================================================================================");
    printf("\n1. Insert Element");
    printf("\n2. Depth First Traversal");
    printf("\n3. Exit");
    printf("\n\nEnter your option : ");
    scanf("%d", &option);
    switch(option)
    {
      case 1:
        printf("\nEnter the value of the new node: ");
        scanf("%d", &val);
        tree = insertElement(tree, val);
        break;
      case 2:
        printf("\nThe elements of the tree after applying breadth first traversal are:\n");
        DepthFirstTraversal(tree);
        break;
    }
  }
  while(option != 3);
  getch();
}

void create_tree(node *tree)
{
  tree = NULL;
}

node *insertElement(node *tree, int val)
{
  node *ptr, *nodeptr, *parentptr;
  ptr = (node*)malloc(sizeof(node));
  ptr->data = val;
  ptr->visited = false;
  ptr->left = NULL;
  ptr->right = NULL;
  if(tree == NULL)
  {
    tree = ptr;
    tree->left = NULL;
    tree->right = NULL;
  }
  else
  {
    parentptr = NULL;
    nodeptr = tree;
    while(nodeptr != NULL)
    {
      parentptr = nodeptr;
      if(val < nodeptr->data)
        nodeptr = nodeptr->left;
      else
        nodeptr = nodeptr->right;
    }
    if(val < parentptr->data)
      parentptr->left = ptr;
    else
      parentptr->right = ptr;
  }
  return tree;
}

void DepthFirstTraversal(node *root)
{
  node *current;
  if (root != NULL)
  {
    push(root);
    while (isEmpty() == false)
    {
      current = pop();
      printf("%d\t", current->data);
      current->visited = true;
      if (current->right != NULL)
      {
        push(current->right);
      }
      if (current->left != NULL)
      {
        push(current->left);
      }
    }
  }
}

void push(node *x)
{
    if(isEmpty() == true)
    {
        Top = (stack *)malloc(sizeof(stack));
        Top->data = x;
        Top->next = NULL;
    }
    else
    {
        A = (stack *)malloc(sizeof(stack));
        A->data = x;
        A->next = Top;
        Top = A;
    }
}

node *pop()
{
    node *x;
    if(isEmpty() == true)
    {
        printf("\nThe Binary Tree has been processed completely");
    }
    else
    {
        A = Top;
        x = A->data;
        Top = Top->next;
        free(A);
    }
    return x;
}

bool isEmpty()
{
    if (Top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

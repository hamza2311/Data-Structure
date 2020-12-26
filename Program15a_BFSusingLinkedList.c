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

typedef struct queue
{
  node *data;
  struct queue *next;
}
queue;
queue *Front = NULL, *Rear = NULL, *B;

void create_tree(node *);
node *insertElement(node *, int);
void enqueue(node *);
void dequeue();
bool empty();
void BreadthFirstTraversal(node *);

void main()
{
  int option, val;
  node *ptr;
  create_tree(tree);
  do
  {
    printf("\n\nPROGRAM TO IMPLEMENT BREADTH FIRST TRAVERSAL ON BINARY SEARCH TREE USING LINKED LIST");
    printf("\n====================================================================================");
    printf("\n1. Insert Element");
    printf("\n2. Breadth First Traversal");
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
        BreadthFirstTraversal(tree);
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

void BreadthFirstTraversal(node *root)
{
    node *current;
    if (root != NULL)
    {
        enqueue(root);
        while (empty()==false)
        {
            current = Front->data;
            current->visited = true;
            printf("%d\t", current->data);
            if (current->left != NULL)
            {
                enqueue(current->left);
            }
            if (current->right != NULL)
            {
                enqueue(current->right);
            }
            dequeue();
        } 
    }
}

void enqueue(node *x)
{
    if(empty()==true)
    {
        Front = (queue *)malloc(sizeof(queue));
        Rear = Front;
        Rear->data = x;
        Rear->next = NULL;
    }
    else
    {
        Rear->next = (queue *)malloc(sizeof(queue));
        Rear = Rear->next;
        Rear->data = x;
        Rear->next = NULL;
    }
}

void dequeue()
{
    if(empty()==true)
    {
        printf("\nThe Binary Tree has been processed completely");
    }
    else if(Front==Rear)
    {
        free(Front);
        Front = NULL;
        Rear = NULL;
    }
    else
    {
        B = Front;
        Front = Front->next;
        free(B);
    }
}

bool empty()
{
    if (Front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
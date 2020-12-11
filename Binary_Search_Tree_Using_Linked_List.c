#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
}
node;
node *tree;

void create_tree(node *);
node *insertElement(node *, int);
node *findSmallestElement(node *);
node *findLargestElement(node *);
node *deleteElement(node *, int);
int totalNodes(node *);
int totalExternalNodes(node *);
int totalInternalNodes(node *);
int Height(node *);
node *deleteTree(node *);

void main()
{
  int option, val;
  node *ptr;
  create_tree(tree);
  do
  {
    printf("\n\nPROGRAM TO IMPLEMENT VARIOUS OPERATIONS ON BINARY SEARCH TREE USING LINKED LIST");
    printf("\n===============================================================================");
    printf("\n1.  Insert Element");
    printf("\n2.  Find the smallest element");
    printf("\n3.  Find the largest element");
    printf("\n4.  Delete an element");
    printf("\n5.  Count the total number of nodes");
    printf("\n6.  Count the total number of external nodes");
    printf("\n7.  Count the total number of internal nodes");
    printf("\n8.  Determine the height of the tree");
    printf("\n9.  Delete the tree");
    printf("\n10. Exit");
    printf("\n\nEnter your option : ");
    scanf("%d", &option);
    switch(option)
    {
      case 1:
        printf("\n Enter the value of the new node : ");
        scanf("%d", &val);
        tree = insertElement(tree, val);
        break;
      case 2:
        ptr = findSmallestElement(tree);
        printf("\n Smallest element is :%d", ptr->data);
        break;
      case 3:
        ptr = findLargestElement(tree);
        printf("\n Largest element is : %d", ptr->data);
        break;
      case 4:
        printf("\n Enter the element to be deleted : ");
        scanf("%d", &val);
        tree = deleteElement(tree, val);
        break;
      case 5:
        printf("\n Total no. of nodes = %d", totalNodes(tree));
        break;
      case 6:
        printf("\n Total no. of external nodes = %d",
        totalExternalNodes(tree));
        break;
      case 7:
        printf("\n Total no. of internal nodes = %d",
        totalInternalNodes(tree));
        break;
      case 8:
        printf("\n The height of the tree = %d",Height(tree));
        break;
      case 9:
        tree = deleteTree(tree);
        break;
    }
  }
  while(option != 10);
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

node *findSmallestElement(node *tree)
{
  if( (tree == NULL) || (tree->left == NULL))
    return tree;
  else
    return findSmallestElement(tree->left);
}

node *findLargestElement(node *tree)
{
  if( (tree == NULL) || (tree->right == NULL))
    return tree;
  else
    return findLargestElement(tree->right);
}

node *deleteElement(node *tree, int val)
{
  node *cur, *parent, *suc, *psuc, *ptr;
  if(tree->left == NULL)
  {
    printf("\n The tree is empty ");
    return(tree);
  }
  parent = tree;
  cur = tree->left;
  while((cur != NULL) && (val != cur->data))
  {
    parent = cur;
    cur = (val < cur->data) ? cur->left : cur->right;
  }
  if(cur == NULL)
  {
    printf("\n The value to be deleted is not present in the tree");
    return(tree);
  }
  if(cur->left == NULL)
    ptr = cur->right;
  else if(cur->right == NULL)
    ptr = cur->left;
  else
  {
    // Find the in–order successor and its parent
    psuc = cur;
    cur = cur->left;
    while(suc->left != NULL)
    {
      psuc = suc;
      suc = suc->left;
    }
    if(cur == psuc)
    {
      // Situation 1
      suc->left = cur->right;
    }
    else
    {
      // Situation 2
      suc->left = cur->left;
      psuc->left = suc->right;
      suc->right = cur->right;
    }
    ptr = suc;
  }
  // Attach ptr to the parent node
  if(parent->left == cur)
    parent->left = ptr;
  else
    parent->right = ptr;
  free(cur);
  return tree;
}

int totalNodes(node *tree)
{
  if(tree == NULL)
    return 0;
  else
    return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
}

int totalExternalNodes(node *tree)
{
  if(tree == NULL)
    return 0;
  else if((tree->left == NULL) && (tree->right == NULL))
    return 1;
  else
    return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
}

int totalInternalNodes(node *tree)
{
  if( (tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)) )
    return 0;
  else
    return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
}

int Height(node *tree)
{
  int leftheight, rightheight;
  if(tree == NULL)
    return 0;
  else
  {
    leftheight = Height(tree->left);
    rightheight = Height(tree->right);
    if(leftheight > rightheight)
      return (leftheight + 1);
    else
      return (rightheight + 1);
  }
}

node *deleteTree(node *tree)
{
  if(tree != NULL)
  {
    deleteTree(tree->left);
    deleteTree(tree->right);
    free(tree);
  }
}

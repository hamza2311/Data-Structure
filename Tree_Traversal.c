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
void preorderTraversal(node *);
void inorderTraversal(node *);
void postorderTraversal(node *);

void main()
{
  int option, val;
  node *ptr;
  create_tree(tree);
  do
  {
    printf("\n\nPROGRAM TO IMPLEMENT VARIOUS TRAVERSALS ON BINARY SEARCH TREE USING LINKED LIST");
    printf("\n===============================================================================");
    printf("\n1. Insert Element");
    printf("\n2. Preorder Traversal");
    printf("\n3. Inorder Traversal");
    printf("\n4. Postorder Traversal");
    printf("\n5. Exit");
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
        printf("\nThe elements of the tree after applying preorder traversal are:\n");
        preorderTraversal(tree);
        break;
      case 3:
        printf("\nThe elements of the tree after applying inorder traversal are:\n");
        inorderTraversal(tree);
        break;
      case 4:
        printf("\nThe elements of the tree after applying postorder traversal are:\n");
        postorderTraversal(tree);
        break;
    }
  }
  while(option != 5);
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

void preorderTraversal(node *tree)
{
  if(tree != NULL)
  {
    printf("%d\t", tree->data);
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
  }
}

void inorderTraversal(node *tree)
{
  if(tree != NULL)
  {
    inorderTraversal(tree->left);
    printf("%d\t", tree->data);
    inorderTraversal(tree->right);
  }
}

void postorderTraversal(node *tree)
{
  if(tree != NULL)
  {
    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    printf("%d\t", tree->data);
  }
}

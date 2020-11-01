#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}
node;

void main()
{
  int i, n;
  node *A, *B, *C, *Head = NULL;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  // Logic for creation of Singly Linked List
  for(i=1; i<=n; i++)
  {
    if(Head == NULL)
    {
      A = (node *)malloc(sizeof(node));
      Head = A;
      printf("\nEnter the data for new node: ");
      scanf("%d", &Head->data);
      Head->next = NULL;
    }
    else
    {
      A->next = (node *)malloc(sizeof(node));
      A = A->next;
      printf("\nEnter the data for new node: ");
      scanf("%d", &A->data);
      A->next = NULL;
    }
  }

  // Logic for display of Singly Linked List
  printf("\nElements of Singly Linked LIst are:\n");
  A = Head;
  for(i=1; i<=n; i++)
  {
    printf("%d -> ", A->data);
    A = A->next;
  }
  printf("NULL");

  //Logic for Inversion of Singly Linked List
  A = NULL;
  B = Head;
  C = B->next;
  while(B != NULL)
  {
    B->next = A;
    A = B;
    B = C;
    if(C != NULL)
    {
      C = C->next;
    }
  }
  Head = A;

  //Printing of inverted Linked List
  printf("\n\nElements of inverted Linked List are:\n");
  A = Head;
  while(A != NULL)
  {
    printf("%d -> ", A->data);
    A = A->next;
  }
  printf("NULL");

  getch();
}

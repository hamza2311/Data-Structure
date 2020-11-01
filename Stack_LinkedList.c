#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
}
stack;

void main()
{
  int choice;
  stack *A, *Top = NULL;

  do
  {
      printf("\n\nPROGRAM TO IMPLEMENT STACK USING LINKED LIST\n");
      printf("======================================\n");
      printf("1) push()\n");
      printf("2) pop()\n");
      printf("3) display()\n");
      printf("4) exit()\n");
      printf("\nPlease enter your choice: ");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
      if(Top==NULL)
      {
          Top = (stack *)malloc(sizeof(stack));
          printf("\nEnter element for stack: ");
          scanf("%d", &Top->data);
          printf("\n%d is pushed into the stack.", Top->data);
          Top->next = NULL;
      }
      else
      {
          A = (stack *)malloc(sizeof(stack));
          printf("\nEnter element for stack: ");
          scanf("%d", &A->data);
          A->next = Top;
          Top = A;
          printf("\n%d is pushed into the stack.", Top->data);
      }
      break;

      case 2:
      if(Top==NULL)
      {
          printf("\nUNDERFLOW: There is nothing to delete since the stack is empty.");
      }
      else
      {
          A = Top;
          printf("\n%d is popped out of the stack.", Top->data);
          Top = Top->next;
          free(A);
      }
      break;

      case 3:
      if(Top==NULL)
      {
          printf("\nUNDERFLOW: There is nothing to display since the stack is empty.");
      }
      else
      {
          printf("\nElements of Stack are:\n");
          A = Top;
          while (A != NULL)
          {
              printf("+--+\n");
              printf("|%d|\n", A->data);
              A = A->next;
          }
          printf("+--+");
      }
      break;

      case 4:
      printf("\nExiting...");
      break;
      }
  }while(choice != 4);

  getch();
}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct c_queue
{
  int data;
  struct c_queue *next;
}
c_queue;

void main()
{
  int i, size, choice;
  c_queue *A, *B, *Front = NULL, *Rear = NULL;

  do
  {
    printf("\n\nPROGRAM TO IMPLEMENT VARIOUS OPERATIONS ON CIRCULAR QUEUE USING LINKED LIST\n");
    printf("===========================================================================\n");
    printf("1) enqueue()\n");
    printf("2) dequeue()\n");
    printf("3) display()\n");
    printf("4) exit()\n");
    printf("\nPlease enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
        if(Front == NULL)
        {
          A = (c_queue *)malloc(sizeof(c_queue));
          Front = Rear = A;
          printf("\nEnter the element for circular queue: ");
          scanf("%d", &Rear->data);
          A->next = A;
        }
        else
        {
          A = (c_queue *)malloc(sizeof(c_queue));
          printf("\nEnter the element for circular queue: ");
          scanf("%d", &A->data);
          A->next = Rear->next;
          Rear->next = A;
          Rear = A;
        }
        break;

      case 2:
        if(Front == NULL)
        {
          printf("\nUNDERFLOW: Deletion is not possible since the circular queue is empty.");
        }
        else if(Front == Rear)
        {
          printf("\nThe last element %d of the circular queue is dequeued.", Rear->data);
          free(Rear);
          Front = NULL;
          Rear = NULL;
        }
        else
        {
          printf("\n%d is dequeued.", Front->data);
          A = Front;
          Front = Front->next;
          Rear->next = Front;
          free(A);
        }
        break;

      case 3:
        if(Front == NULL && Rear == NULL)
        {
          printf("\nUNDERFLOW: There is nothing to display in circular queue since the circular queue is empty.");
        }
        else
        {
          printf("\nElements of circular queue are:\n");
          A = Front;
          do
          {
            printf("%d\t", A->data);
            A = A->next;
          }
          while(A != Front);
          break;
        }

        case 4:
          printf("\nExiting the program....");
          break;
    }
  }
  while(choice != 4);

  getch();
}

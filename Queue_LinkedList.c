#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct queue
{
  int data;
  struct queue * next;
}
queue;

void main()
{
  int choice;
  queue *A, *B, *Front = NULL, *Rear = NULL;

  do
  {
    printf("\n\nPROGRAM TO IMPLEMENT VARIOUS OPERATIONS ON QUEUE USING LINKED LIST\n");
    printf("============================================================\n");
    printf("1) enqueue()\n");
    printf("2) dequeue()\n");
    printf("3) display()\n");
    printf("4) exit()\n");
    printf("\nPlease enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
      if(Front==NULL)
      {
          Front = (queue *)malloc(sizeof(queue));
          Rear = Front;
          printf("\nEnter element for queue: ");
          scanf("%d", &Rear->data);
          printf("\n%d is enqueued in the queue.", Rear->data);
          Front->next = NULL;
      }
      else
      {
          Rear->next = (queue *)malloc(sizeof(queue));
          Rear = Rear->next;
          printf("\nEnter element for queue: ");
          scanf("%d", &Rear->data);
          printf("\n%d is enqueued in the queue.", Rear->data);
          Rear->next = NULL;
      }
      break;

      case 2:
      if(Front==NULL)
      {
          printf("\nUNDERFLOW: There is nothing to delete since the queue is empty.");
      }
      else if(Front==Rear)
      {
        printf("\nThe last element %d of the queue is dequeued.", Rear->data);
        free(Rear);
        Front = NULL;
        Rear = NULL;
      }
      else
      {
          B = Front;
          printf("\n%d is dequeued.", Front->data);
          Front = Front->next;
          free(B);
      }
      break;

      case 3:
      if(Front==NULL)
      {
          printf("\nUNDERFLOW: There is nothing to display since the queue is empty.");
      }
      else
      {
          printf("\nElements of queue are:\n");
          A = Front;
          while (A != NULL)
          {
              printf("%d\t", A->data);
              A = A->next;
          }
      }
      break;

      case 4:
      printf("\nExiting the program.....");
      break;
    }
  } while(choice != 4);

  getch();
}

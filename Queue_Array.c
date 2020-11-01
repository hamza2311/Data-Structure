#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

void main()
{
  int size, choice, i;
  int front = -1;
  int rear = -1;
  int queue[MAX];
  printf("Enter the size of the queue array: ");
  scanf("%d", &size);

  do
  {
    printf("\n\nPROGRAM TO IMPLEMENT VARIOUS OPERATIONS ON QUEUE USING ARRAY\n");
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
        if(rear == size-1)
        {
          printf("\nOVERFLOW: Insertion is not possible since the queue is full.");
        }
        else if(front == -1)
        {
          front++;
          rear++;
          printf("\nEnter the first element of queue: ");
          scanf("%d", &queue[front]);
        }
        else
        {
          rear++;
          printf("\nEnter the onward elements of queue: ");
          scanf("%d", &queue[rear]);
        }
        break;
      case 2:
        if(front == -1 && rear == -1)
        {
          printf("\nUNDERFLOW: Deletion is not possible since the queue is empty.");
        }
        else if(front == rear)
        {
          printf("\nThe last element %d of the queue is dequeued.", queue[front]);
          front = -1;
          rear = -1;
        }
        else
        {
          printf("\n%d is dequeued.", queue[front]);
          front++;
        }
        break;
      case 3:
        if(front == -1 && rear == -1)
        {
          printf("\nUNDERFLOW: There is nothing to display in the queue since the queue is empty.");
        }
        else
        {
          printf("\n");
          for(i=front; i<=rear; i++)
          {
            printf("%d\t", queue[i]);
          }
        }
        break;
      case 4:
        printf("\nExiting the program....");
    }
  } while(choice != 4);

  getch();
}

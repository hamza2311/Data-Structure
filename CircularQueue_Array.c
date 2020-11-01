#include<stdio.h>
#include<conio.h>
#define MAX 100

void main()
{
  int i, size, choice;
  int circular_queue[MAX];
  int front = -1, rear = -1;
  printf("Enter the size of circular queue array: ");
  scanf("%d", &size);

  do
  {
    printf("\n\nPROGRAM TO IMPLEMENT VARIOUS OPERATIONS ON CIRCULAR QUEUE USING ARRAY\n");
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
        if((front == 0 && rear == size-1) || (rear == (front - 1) % (size - 1)))
        {
          printf("\nOVERFLOW: Insertion is not possible since the queue is full.");
        }
        else if(front == -1)
        {
          front = 0;
          rear = front;
          printf("\nEnter the first element of  circular queue: ");
          scanf("%d", &circular_queue[rear]);
          printf("\n%d is enqueued in the circular queue.", circular_queue[rear]);
        }
        else
        {
          rear = (rear + 1) % size;
          printf("\nEnter the onward elements of circular queue: ");
          scanf("%d", &circular_queue[rear]);
          printf("\n%d is enqueued in the circular queue.", circular_queue[rear]);
        }
        break;
      case 2:
        if(front == -1 && rear == -1)
        {
          printf("\nUNDERFLOW: Deletion is not possible since the queue is empty.");
        }
        else if(front == rear)
        {
          printf("\nThe last element %d of circular queue is dequeued.", circular_queue[front]);
          front = -1;
          rear = -1;
        }
        else
        {
          printf("\n%d is dequeued.", circular_queue[front]);
          front = (front + 1) % size;
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
          if (rear >= front)
          {
            for (i = front; i <= rear; i++)
              printf("%d ", circular_queue[i]);
          }
          else
          {
            for (i = front; i < size; i++)
              printf("%d ", circular_queue[i]);

            for (i = 0; i <= rear; i++)
              printf("%d ", circular_queue[i]);
          }
        }
        break;
      case 4:
        printf("\nExiting the program....");
        break;
    }
  } while(choice != 4);

  getch();
}

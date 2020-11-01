#include<stdio.h>
#include<conio.h>
#define MAX 100

void main()
{
  int A[MAX], i, size, element, position;
  char choice;
  printf("\nEnter the size of the array: ");
  scanf("%d", &size);
  for(i=0; i<size; i++)
  {
    printf("\nEnter the element for A[%d]: ", i);
    scanf("%d", &A[i]);
  }

  do
  {
    printf("\nEnter the position from which the element has to be deleted: ");
    scanf("%d", &position);
    element = A[position];
    for(i = position; i < size; i++)
    {
      A[i] = A[i+1];
    }
    size = size - 1;
    printf("\nThe array after deletion of %d is: ", element);
    for(i=0; i<size; i++)
    {
      printf("\nA[%d] = %d", i, A[i]);
    }
    printf("\n\nDo you want to continue? (y/n): ");
    scanf("%s", &choice);
  }
  while(choice != 'n');
  printf("\n\nExiting the program....\n");

  getch();
}

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
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &element);
    printf("\nEnter the position at which the number has to be added: ");
    scanf("%d", &position);
    for(i = size-1; i >= position; i--)
    {
      A[i+1] = A[i];
    }
    A[position] = element;
    size = size + 1;
    printf("\nThe array after insertion of %d is: ", element);
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

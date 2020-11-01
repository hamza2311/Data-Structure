#include<stdio.h>
#include<conio.h>
#define MAX 100

void main()
{
  int A[MAX], i, j, temp, size, minimum, position;
  printf("\nEnter the size of the array: ");
  scanf("%d", &size);
  printf("\nEnter the elements of the array:\n");
  for(i=0; i<size; i++)
  {
    printf("Enter A[%d]: ", i);
    scanf("%d", &A[i]);
  }
  printf("\nElements of unsorted array are:\n");
  for(i=0; i<size; i++)
  {
    printf("%d\t", A[i]);
  }

  //Logic for Selection sort
  for(i = 0; i < size-1; i++)
  {
    minimum = A[i];
    position = i;
    for(j = i+1; j < size; j++)
    {
      if(A[j] < minimum)
      {
        minimum = A[i];
        position = j;
      }
    }
    if(position != i)
    {
      temp = A[i];
      A[i] = A[position];
      A[position] =  temp;
    }
  }
  printf("\n\nAfter applying selection sort, the elements of array in ascending order are:\n");
  for(i = 0; i < size; i++)
  {
    printf("%d\t", A[i]);
  }

  getch();
}

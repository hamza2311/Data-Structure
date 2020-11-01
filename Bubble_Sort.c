#include<stdio.h>
#include<conio.h>
#define MAX 100

void main()
{
  int A[MAX], i, j, temp, size;
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

  //Logic for buuble unsorted
  for(i = 0; i < size-1; i++)
  {
    for(j = 0; j < size-i-1; j++)
    {
      if(A[j] < A[j+1])
      {
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  }
  printf("\n\nAfter applying bubble sort, the elements of array in ascending order are:\n");
  for(i = 0; i < size; i++)
  {
    printf("%d\t", A[i]);
  }

  getch();
}

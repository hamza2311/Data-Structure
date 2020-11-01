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

  //Logic for Insertion Sort
  for(i = 1; i < size; i++)
  {
    temp = A[i];
    j = i-1;
    while((temp < A[j]) && (j>=0))
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = temp;
  }
  printf("\n\nAfter applying insertion sort, the elements of array in ascending order are:\n");
  for(i = 0; i < size; i++)
  {
    printf("%d\t", A[i]);
  }

  getch();
}

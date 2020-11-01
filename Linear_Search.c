#include<stdio.h>
#include<conio.h>
#define SIZE 15

void main()
{
  int element[SIZE], num, i;
  char choice;
  for (i = 0; i < SIZE; i++)
  {
    printf("Enter element %d: ", i+1);
    scanf("%d", &element[i]);
  }
  do
  {
    printf("\nEnter the element to be searched: ");
    scanf("%d", &num);
    for (i = 0; i < SIZE; i++)
    {
      if (element[i] == num)
      {
        printf("The element is in %dth position\n", i+1);
        break;
      }
    }
    if (i == SIZE)
    {
      printf("The element not found.\n");
    }
    printf("\nDo you want to continue? (Y/N)");
    scanf("%s", &choice);
  } while (choice != 'N');

  getch();
}

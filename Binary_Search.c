#include<stdio.h>
#include<conio.h>

void main()
{
  int arr[20], i, j, number, swap, key, low, high, mid, flag = 0;
  char choice;
  printf("Enter number of elements: ");
  scanf("%d", &number);
  printf("\nEnter %d elements:\n", number);
  for(i=0; i<number; i++)
  {
    scanf("%d", &arr[i]);
  }
  for(i=0; i<number; i++)
  {
    for(j=0; j<number-i-1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        swap = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = swap;
      }
    }
  }
  printf("\nNow the array in ascending order becomes:\n");
  for(i=0; i<number; i++)
  {
    printf("%d\t", arr[i]);
  }
  do
  {
    printf("\n\nEnter the number you want to search: ");
    scanf("%d", &key);
    low = 0;
    high = number - 1;
    while(low <= high)
    {
      mid = (low + high) / 2;
      if(key == arr[mid])
      {
        flag = 1;
        break;
      }
      else
      {
        if(key < arr[mid])
        {
          high = mid - 1;
        }
        else
        {
          low = mid + 1;
        }
      } 
    }
    if(flag == 1)
    {
      printf("\nThe number is at %dth index.", mid);
    }
    else
    {
      printf("\nNumber not found.");
    }
    printf("\n\nDo you want to continue? (Y/N)\n");
    scanf("%s", &choice);
  } while (choice != 'N');
  printf("\n\nExiting....");
  getch();

}

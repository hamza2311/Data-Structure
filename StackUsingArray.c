#include<stdio.h>
#include<conio.h>
#define max 100

void main()
{
    int i, x, choice, element, top = -1;
    int stack[max];

    do
    {
        printf("\n\nPROGRAM TO IMPLEMENT STACK USING ARRAY\n");
        printf("======================================\n");
        printf("1) push()\n");
        printf("2) pop()\n");
        printf("3) display()\n");
        printf("4) exit()\n");
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (top == max-1)
            {
                printf("\nOVERFLOW: Insertion is not possible since the stack is FULL.");
            }
            else
            {
                top++;
                printf("\nEnter element: ");
                scanf("%d", &element);
                stack[top] = element;
                printf("\n%d is successfully pushed into the stack.", element);
            }
            break;
        
        case 2:
            if (top == -1)
            {
                printf("\nUNDERFLOW: Deletion is not possible since the stack is EMPTY.");
            }
            else
            {
                x = stack[top];
                printf("\n%d is successfully poped out of the stack.", x);
                top--;
            }
            break;
        
        case 3:
            if (top == -1)
            {
                printf("\nUNDERFLOW: There is nothing to display in the stack since the stack is EMPTY.");
            }
            else
            {
                for (i = top; i >= 0; i--)
                {
                    printf("+--+\n");
                    printf("|%d|\n", stack[i]);
                }
                printf("+--+");
                
            }
            break;
        
        case 4:
            printf("\nExiting the program.....");
            break;
        }
    } while (choice != 4);
    
    getch(); 
}

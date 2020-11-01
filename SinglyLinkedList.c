#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}
node;

void main()
{
    int i, n, ch, location, element, flag=0, count=1;
    node *A, *B, *Head=NULL;
    
    do
    {
        printf("\nPROGRAM TO IMPLEMENT VARIOUS OPERATIONS ON A SINGLY LINKED LIST\n");
        printf("===============================================================\n");
        printf("1) Creating/Appending the list\n");
        printf("2) Inserting a node at the beginning of the list\n");
        printf("3) Inserting a node at a given location\n");
        printf("4) Deleting the last node\n");
        printf("5) Deleting the first node\n");
        printf("6) Deleting a node whose data matches with the given data\n");
        printf("7) Display the linked list\n");
        printf("8) Exit the program\n");
        printf("\nPlease enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            if(Head==NULL)
            {
                printf("\nThis is the first node.");
                A = (node *)malloc(sizeof(node));
                Head = A;
                printf("\nEnter the data of new node: ");
                scanf("%d", &Head->data);
                Head->next = NULL;
            }
            else
            {
                count++;
                printf("\nThis is node number %d", count);
                A->next = (node *)malloc(sizeof(node));
                A = A->next;
                printf("\nEnter the data of new node: ");
                scanf("%d", &A->data);
                A->next = NULL;
            }
            break;
        case 2:
            if(Head==NULL)
            {
                printf("\nThis is the first node.");
                A = (node *)malloc(sizeof(node));
                Head = A;
                printf("\nEnter the data of new node: ");
                scanf("%d", &Head->data);
                Head->next = NULL;
            }
            else
            {
                A = (node *)malloc(sizeof(node));
                printf("\nEnter the data of new node: ");
                scanf("%d", &A->data);
                A->next = Head;
                Head = A;
            }
            break;
        case 3:
            printf("\nEnter the location of the node where it is to be inserted: ");
            scanf("%d", &location);
            if(location==1)
            {
                printf("\nYou are inserting a node at the location of Head node.");
                if(Head==NULL)
                {
                    printf("\nThis is the first node.");
                    A = (node *)malloc(sizeof(node));
                    Head = A;
                    printf("\nEnter the data of new node: ");
                    scanf("%d", &Head->data);
                    Head->next = NULL;
                }
                else
                {
                    printf("\nNow this becomes the Head node.");
                    A = (node *)malloc(sizeof(node));
                    printf("\nEnter the data of new node: ");
                    scanf("%d", &A->data);
                    A->next = Head;
                    Head = A;
                }
            }
            else
            {
                A = (node *)malloc(sizeof(node));
                printf("\nEnter the data of new node: ");
                scanf("%d", &A->data);
                B = Head;
                for(i=1; i<=(location-2); i++)
                {
                    B = B->next;
                }
                A->next = B->next;
                B->next = A;
            }
            break;
        case 4:
            if(Head==NULL)
            {
                printf("\nUNDERFLOW: There is nothing to delete since the linked list is empty");
            }
            else
            {
                B = Head;
                while (B->next->next != NULL)
                {
                    B = B->next;
                }
                A = B->next;
                free(A);
                B->next = NULL;
            }
            break;
        case 5:
            if(Head==NULL)
            {
                printf("\nUNDERFLOW: There is nothing to delete since the linked list is empty.");
            }
            else
            {
                B = Head;
                Head = Head->next;
                free(B);
            }
            break;
        case 6:
            if (Head==NULL)
            {
                printf("\nUNDERFLOW: There is nothing to delete since the linked list is empty.");
            }
            else
            {
                printf("\nEnter the data of the node which is to be deleted: ");
                scanf("%d", &element);
                B = Head;
                if(B->data == element)
                {
                    Head = B->next;
                    free(B);
                }
                else
                {
                    while (B != NULL)
                    {
                        if(B->next->data == element)
                        {
                            flag = 1;
                            break;
                        }
                        B = B->next;
                    }
                    if(flag==1)
                    {
                        A = B->next;
                        B->next = A->next;
                        free(A);
                    }
                    else
                    {
                        printf("\nData not found...");
                    } 
                    
                }
                
            }
            break;
        case 7:
            if(Head==NULL)
            {
                printf("\nUNDERFLOW: There is nothing to display since the linked list is empty.");
            }
            else
            {
                printf("\nElements of Singly Linked List are:\n");
                A = Head;
                while (A != NULL)
                {
                    printf("%d -> ", A->data);
                    A = A->next;
                }
                printf("NULL\n");
            }
            break;
        case 8:
            printf("\nExiting the program.....");
            break;
        }
        
    } while (ch != 8);
    
    getch();   
}

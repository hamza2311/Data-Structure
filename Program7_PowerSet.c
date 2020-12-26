#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>
#define MAX 20

void PowerSet(int A[], int);

void main()
{
    int A[MAX];
    int cardinality_A;
    int i;

    printf("\nPROGRAM TO IMPLEMENT POWER SET OF A SET");
    printf("\n=======================================\n");

    // SET A
    printf("\nEnter the cardinality of Set A: ");
    scanf("%d", &cardinality_A);
    printf("Enter %d elements of Set A:\n", cardinality_A);
    for (i = 0; i < cardinality_A; i++)
    {
        scanf("%d", &A[i]);
    }

    //PRINTING OF SET A
    printf("\nSet A = ");
    if (cardinality_A == 0)
    {
        printf("%c", 237);
    }
    else
    {
        printf("{");
        for (i = 0; i < cardinality_A; i++)
        {
            printf(" %d ", A[i]);
        }
        printf("}");
    }

    // POWER SET OF A
    printf("\n\nPower Set of Set A is as follows:");
    PowerSet(A, cardinality_A);

    getch();
}

void PowerSet(int A[], int cardinality_A)
{
    int P;
    int i, j;
    int cardinality_P = pow(2, cardinality_A);

    if (cardinality_A == 0)
    {
        printf("\nP(A) = {%c}", 237); 
    }
    else
    {
        printf("\nP(A) = {");
        for (i = 0; i < cardinality_P; i++)
        {
            printf("  {");
            for (j = 0; j < cardinality_A; j++)
            {
                if (i & (1 <<j ))
                {
                    printf(" %d ", A[j]);
                }
            }
            printf("}  ");
        }
    }
    printf("}");

    printf("\n\n\nPROGRAM EXECUTED\n");
    getch();
}

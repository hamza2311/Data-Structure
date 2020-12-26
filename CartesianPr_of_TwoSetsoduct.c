#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#define MAX 20

void CartesianProduct(int A[], int B[], int, int);

void main()
{
    int A[MAX], B[MAX];
    int cardinality_A, cardinality_B;
    int i;

    printf("\nPROGRAM TO IMPLEMENT CARTESIAN PRODUCT OF TWO SETS");
    printf("\n==================================================\n");

    // FIRST SET
    printf("\nEnter the cardinality of Set A: ");
    scanf("%d", &cardinality_A);
    printf("Enter %d elements of Set A:\n", cardinality_A);
    for (i = 0; i < cardinality_A; i++)
    {
        scanf("%d", &A[i]);
    }

    // SECOND SET
    printf("\nEnter the cardinality of Set B: ");
    scanf("%d", &cardinality_B);
    printf("Enter %d elements of Set A:\n", cardinality_B);
    for (i = 0; i < cardinality_B; i++)
    {
        scanf("%d", &B[i]);
    }

    //PRINTING OF FIRST SET
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

    // PRINTING OF SECOND SET
    printf("\nSet B = ");
    if (cardinality_B == 0)
    {
        printf("%c", 237);
    }
    else
    {
        printf("{");
        for (i = 0; i < cardinality_B; i++)
        {
            printf(" %d ", B[i]);
        }
        printf("}");
    }

    // CARTESIAN PRODUCT OF BOTH SETS
    printf("\n\nCartesian Product of Set A and Set B is as follows:");
    CartesianProduct(A, B, cardinality_A, cardinality_B);

    getch();
}

void CartesianProduct(int A[], int B[], int cardinality_A, int cardinality_B)
{
    int i, j;

    if (cardinality_A == 0 || cardinality_B == 0)
    {
        printf("\nA x B = %c", 237);
        printf("\nB x A = %c", 237);
    }
    else
    {
        printf("\nA x B = {");
        for (i = 0; i < cardinality_A; i++)
        {
            for (j = 0; j < cardinality_B; j++)
            {
                printf(" (%d, %d) ", A[i], B[j]);
            }
        }
        printf("}");

        printf("\nB x A = {");
        for (i = 0; i < cardinality_B; i++)
        {
            for (j = 0; j < cardinality_A; j++)
            {
                printf(" (%d, %d) ", B[i], A[j]);
            }
        }
        printf("}");
    }

    printf("\n\n\nPROGRAM EXECUTED\n");
    getch();
}

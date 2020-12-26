#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#define MAX 20

void Intersection(int A[], int B[], int, int);

void main()
{
    int A[MAX], B[MAX];
    int cardinality_A, cardinality_B;
    int i;

    printf("\nPROGRAM TO IMPLEMENT INTERSECTION OF TWO SETS");
    printf("\n=============================================\n");

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
    printf("Enter %d elements of Set B:\n", cardinality_B);
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

    // INTERSECTION OF BOTH SETS
    printf("\n\nIntersection of Set A and Set B is as follows:\n");
    Intersection(A, B, cardinality_A, cardinality_B);

    getch();
}

// FUNCTION FOR CALCULATING INTERSECTION OF TWO SETS
void Intersection(int A[], int B[], int cardinality_A, int cardinality_B)
{
    int C[MAX];
    int m, n, cardinality_C = 0;
    bool flag;

    if (cardinality_A == 0 || cardinality_B == 0)
    {
        printf("%c", 237);
    }
    else
    {
        // Match each and every element of Set B with each and every element of Set A
        for (m = 0; m < cardinality_B; m++)
        {
            flag = false;
            for (n = 0; n < cardinality_A; n++)
            {
                if (B[m] == A[n])
                {
                    flag = true;
                    break;
                }
            }
            // if element matches with any of the element of Set A, then copy that element in Set C
            if (flag == true)
            {
                C[cardinality_C] = B[m];
                cardinality_C++;
            }
        }

        // PRINTING OF SET C (SET INTERSECTION)
        printf("{");
        for (m = 0; m < cardinality_C; m++)
        {
            printf(" %d ", C[m]);
        }
        printf("}");
    }
    printf("\n\nPROGRAM EXECUTED");
    getch();
}

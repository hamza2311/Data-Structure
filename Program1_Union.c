#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#define MAX 20

void Union(int A[], int B[], int, int);

void main()
{
    int A[MAX], B[MAX];
    int cardinality_A, cardinality_B;
    int i;

    printf("\nPROGRAM TO IMPLEMENT UNION OF TWO SETS");
    printf("\n======================================\n");

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

    // UNION OF BOTH SETS
    printf("\n\nUnion of Set A and Set B is as follows:\n");
    Union(A, B, cardinality_A, cardinality_B);

    getch();
}

// FUNCTION FOR CALCULATING UNION OF TWO SETS
void Union(int A[], int B[], int cardinality_A, int cardinality_B)
{
    int C[MAX];
    int i, m, n;
    bool flag;

    if (cardinality_A == 0 && cardinality_B == 0)
    {
        printf("%c", 237);
    }
    else
    {
        if (cardinality_A == 0)
        {
            for (i = 0; i < cardinality_B; i++)
            {
                C[i] = B[i];
            }
        }
        else if (cardinality_B == 0)
        {
            for (i = 0; i < cardinality_A; i++)
            {
                C[i] = A[i];
            }
        }
        else
        {
            // Copy any one Set (here Set A) in Set C, i.e., Set Union
            for (i = 0; i < cardinality_A; i++)
            {
                C[i] = A[i];
            }

            // Match each and every element of Set B with each and every element of Set A
            for (m = 0; m < cardinality_B; m++)
            {
                flag = false;
                for (n = 0; n < cardinality_A; n++)
                {
                    // if the element matches, then no need to copy that element in Set C
                    if (B[m] == A[n])
                    {
                        flag = true;
                        break;
                    }
                }
                // if element does not match with any of the element of Set A, then copy that element in Set C
                if (flag == false)
                {
                    C[i] = B[m];
                    i++;
                }
            }
        }

        // PRINTING OF SET C (SET UNION)
        printf("{");
        for (m = 0; m < i; m++)
        {
            printf(" %d ", C[m]);
        }
        printf("}");
    }

    printf("\n\nPROGRAM EXECUTED");
    getch();
}

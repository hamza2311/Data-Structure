#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#define MAX 100

void Complement(int A[], int B[], int, int);

void main()
{
    int U[MAX], B[MAX];
    int cardinality_U, cardinality_B;
    int i;

    printf("\nPROGRAM TO IMPLEMENT COMPLEMENT OF A SET");
    printf("\n========================================\n");

    // UNIVERSAL SET
    printf("\nEnter the cardinality of Universal Set: ");
    scanf("%d", &cardinality_U);
    for (i = 0; i < cardinality_U; i++)
    {
        U[i] = i + 1;
    }

    //PRINTING OF UNIVERSAL SET
    printf("Set A = ");
    printf("{");
    for (i = 0; i < cardinality_U; i++)
    {
        printf(" %d ", U[i]);
    }
    printf("}");

    // SECOND SET
    printf("\n\nEnter the cardinality of Set B: ");
    scanf("%d", &cardinality_B);
    printf("Enter %d elements of Set A:\n", cardinality_B);
    for (i = 0; i < cardinality_B; i++)
    {
        scanf("%d", &B[i]);
    }

    // PRINTING OF SECOND SET
    printf("Set B = ");
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

    // COMPLEMENT OF BOTH SETS
    printf("\n\nComplement of Set B is as follows:\n");
    Complement(U, B, cardinality_U, cardinality_B);

    getch();
}

// FUNCTION FOR CALCULATING UNION OF TWO SETS
void Complement(int A[], int B[], int cardinality_A, int cardinality_B)
{
    int C[MAX];
    int i = 0, m, n;
    bool flag;

    if (cardinality_B == 0)
    {
        for (i = 0; i < cardinality_A; i++)
        {
            C[i] = A[i];
        }
    }
    else
    {
        // Match each and every element of Set B with each and every element of Set A
        for (m = 0; m < cardinality_A; m++)
        {
            flag = false;
            for (n = 0; n < cardinality_B; n++)
            {
                // if the element matches, then no need to copy that element in Set C
                if (A[m] == B[n])
                {
                    flag = true;
                    break;
                }
            }
            // if element does not match with any of the element of Set A, then copy that element in Set C
            if (flag == false)
            {
                C[i] = A[m];
                i++;
            }
        }
    }

    // PRINTING OF SET C (SET COMPLEMENT)
    printf("{");
    for (m = 0; m < i; m++)
    {
        printf(" %d ", C[m]);
    }
    printf("}");

    printf("\n\nPROGRAM EXECUTED");
    getch();
}

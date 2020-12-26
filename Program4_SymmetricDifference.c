#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#define MAX 20

int *Union(int [], int [], int, int, int *);
int *Intersection(int [], int [], int, int, int *);
void SymmetricDifference(int *, int *, int, int);

void main()
{
    int A[MAX], B[MAX];
    int *C, *D;
    int cardinality_A, cardinality_B;
    int cardinality_c, cardinality_d;
    int i;

    printf("\nPROGRAM TO IMPLEMENT SYMMETRIC DIFFERENCE OF TWO SETS");
    printf("\n=====================================================\n");

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

    // SYMMETRIC DIFFERENCE OF BOTH SETS (Difference of Union and Intersection)
    printf("\n\nSymmetric Difference of Set A and Set B is as follows:\n");
    // union of both sets
    C = Union(A, B, cardinality_A, cardinality_B, &cardinality_c);
    // intersection of both sets
    D = Intersection(A, B, cardinality_A, cardinality_B, &cardinality_d);

    SymmetricDifference(C, D, cardinality_c, cardinality_d);

    getch();
}

// FUNCTION FOR CALCULATING UNION OF TWO SETS
int *Union(int A[], int B[], int cardinality_A, int cardinality_B, int *c)
{
    static int C[MAX];
    int i, m, n;
    bool flag;

    if (cardinality_A == 0 && cardinality_B == 0)
    {
        i = 0;
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
    }
    *c = i;
    return C;
}

// FUNCTION FOR CALCULATING INTERSECTION OF TWO SETS
int *Intersection(int A[], int B[], int cardinality_A, int cardinality_B, int *d)
{
    static int D[MAX];
    int m, n, cardinality_D = 0;
    bool flag;

    if (cardinality_A == 0 || cardinality_B == 0)
    {
        cardinality_D = 0;
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
                D[cardinality_D] = B[m];
                cardinality_D++;
            }
        }
    }
    *d = cardinality_D;
    return D;
}

// FUNCTION TO CALCULATE SYMMETRIC DIFFERENCE OF BOTH SETS
void SymmetricDifference(int *C, int *D, int cardinality_c, int cardinality_d)
{
    int E[MAX];
    int i, j, k = 0;
    bool flag;
    
    if (cardinality_c == 0)
    {
        printf("%c", 237);
    }
    else
    {
        if (cardinality_d == 0)
        {
            for (k = 0; k < cardinality_c; k++)
            {
                E[k] = C[k];
            }
        }
        else
        {
            for (i = 0; i < cardinality_c; i++)
            {
                flag = false;
                for (j = 0; j < cardinality_d; j++)
                {
                    if (C[i] == D[j])
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag == false)
                {
                    E[k] = C[i];
                    k++;
                }
            }
        }

        // PRINTING OF SYMMETRIC DIFFERENCE
        printf("{");
        for (i = 0; i < k; i++)
        {
            printf(" %d ", E[i]);
        }
        printf("}");
    }
    
    printf("\n\nPROGRAM EXECUTED");
    getch();
}

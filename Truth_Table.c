#include <stdio.h>
#include <conio.h>

void AND(int, int);
void OR(int, int);
void NOT(int);
void XOR(int, int);
void NAND(int, int);
void NOR(int, int);

void main()
{
    int X, Y;
    int count;

    printf("\nPROGRAM TO IMPLEMENT VARIOUS LOGICAL OPERATIONS");
    printf("\n===============================================\n");
    printf("\nEnter 1 FOR TRUE and 0 for FALSE");
    for (count = 1; count <= 4; count++)
    {
        printf("\n\n\nEnter the value for X: ");
        scanf("%d", &X);
        printf("Enter the value for Y: ");
        scanf("%d", &Y);
        AND(X, Y);
        OR(X, Y);
        XOR(X, Y);
        NAND(X, Y);
        NOR(X, Y);
        NOT(X);
        NOT(Y);
    }
    printf("\n");
    getch();
}

void AND(int X, int Y)
{
    int result = X && Y;
    printf("\n%d AND %d  = %d", X, Y, result);

    getch();
}

void OR(int X, int Y)
{
    int result = X || Y;
    printf("\n%d OR %d   = %d", X, Y, result);
    
    getch();
    
}

void NOT(int X)
{
    int result = !X;
    printf("\nNOT %d    = %d", X, result);
    
    getch();
}

void XOR(int X, int Y)
{
    int result = X ^ Y;
    printf("\n%d XOR %d  = %d", X, Y, result);
    
    getch();
}

void NAND(int X, int Y)
{
    int result = !(X && Y);
    printf("\n%d NAND %d = %d", X, Y, result);
    
    getch();
}

void NOR(int X, int Y)
{
    int result = !(X || Y);
    printf("\n%d NOR %d  = %d", X, Y, result);
    
    getch();
}

from numpy import *
from array import *

A = array('i', [])
B = array('i', [])

row_A = int(input('Enter number of rows for Matrix A: '))
column_A = int(input('Enter number of columns for Matrix A: '))
for i in range(0, row_A):
    for j in range(0, column_A):
        element = int(input("Enter the element: "))
        A.append(element)

A = reshape(A, (row_A, column_A))
print(A)

row_B = int(input('Enter number of rows for Matrix B: '))
column_B = int(input('Enter number of columns for Matrix B: '))
for i in range(0, row_B):
    for j in range(0, column_B):
        element = int(input("Enter the element: "))
        B.append(element)

B = reshape(B, (row_B, column_B))
print(B)

C = zeros((row_A, column_B), int)
if column_A != row_B:
    print("Matrix multiplication is not possible.")
else:
    print("Multiplication of matrix A and B is:")
    for i in range(0, row_A):
        for j in range(0, column_B):
            for k in range(0, column_A):
                C[i][j] += A[i][k] * B[k][j]
    print(C)

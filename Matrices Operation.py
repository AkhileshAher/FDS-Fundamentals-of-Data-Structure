/*
Write a python program to compute following computation on matrix:
a) Addition of two matrices
b) Subtraction of two matrices
c) Multiplication of two matrices
d) Transpose of a matrix

*/

#CODE :

a = [[1, 2, 2],
     [3, 4, 4],
     [5, 6, 6]]

b = [[1, 2, 4],
     [3, 4, 7],
     [5, 6, 8]]

result = [[0, 0, 0],
          [0, 0, 0],
          [0, 0, 0]]

print("Matrix Addition:")
for i in range(len(a)):
    for j in range(len(a[0])):
        result[i][j] = a[i][j] + b[i][j]
print(result)

print("\nMatrix Subtraction:")
for i in range(len(a)):
    for j in range(len(a[0])):
        result[i][j] = a[i][j] - b[i][j]
print(result)

print("\nMatrix Transposition (of matrix 'a'):")
transpose = [[a[j][i] for j in range(len(a))] for i in range(len(a[0]))]
print(transpose)

print("\nMatrix Multiplication:")
for i in range(len(a)):
    for j in range(len(b[0])):
        result[i][j] = 0
        for k in range(len(b)):
            result[i][j] += a[i][k] * b[k][j]
print(result)

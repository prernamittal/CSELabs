import numpy as np

matrix = np.array([[1, 2, 3],
                   [4, 5, 6],
                   [7, 8, 9]])

column_sums = np.sum(matrix, axis=0)
print("Column sums:", column_sums)

row_sums = np.sum(matrix, axis=1)
print("Row sums:", row_sums)
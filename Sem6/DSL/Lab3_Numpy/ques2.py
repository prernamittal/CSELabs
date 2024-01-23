import numpy as np

matrix = np.arange(9).reshape((3,3))  

column_sums = np.sum(matrix, axis=0)
print("Column sums:", column_sums)

row_sums = np.sum(matrix, axis=1)
print("Row sums:", row_sums)
import numpy as np

# Create array from list with type float
myList = ['1.3','4.2','2.4','7.5','6.1']
print("Original List: ", myList)
myArray = np.array(myList, dtype=float)
print("Float Array: ", myArray)

# Create array from tuple
myTuple = ([8, 4, 6], [1, 2, 3], [7, 81, 22])
myArray = np.array(myTuple)
print("Array: ", myArray)

# Creating a 3X4 array with all zeros
myArray = np.zeros((3, 4))
print("Zeroes Matrix: ", myArray)

# Create a sequence of integers from 0 to 20 with steps of 5
print("Sequence: ", np.arange(0, 21, 5))

# Reshape 3X4 array to 2X2X3 array
newArray = myArray.reshape(2, 2, 3)
print("Reshaped array: ")
print(newArray)

# Find maximum and minimum element of array, Row wise max and min, column wise max and min and sum of elements
max_element_column = np.max(myTuple, 0)
max_element_row = np.max(myTuple, 1)
min_element_column = np.amin(myTuple, 0)
min_element_row = np.amin(myTuple, 1)

print('maximum elements in the columns of the array is:', max_element_column)
print('maximum elements in the rows of the array is:', max_element_row)
print('minimum elements in the columns of the array is:', min_element_column)
print('minimum elements in the rows of the array is:', min_element_row)

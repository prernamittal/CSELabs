import numpy as np  
X = np.arange(9).reshape((3,3))  
Y = np.arange(9, 18).reshape((3,3)) 
result=np.multiply(X,Y)  
print(X, "\n*\n", Y, "\n=\n", result)
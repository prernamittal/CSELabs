import pandas as pd

data1 = [['Dinesh'],['Nithya'],['Raji'], ['Ram']]
df1 = pd.DataFrame(data1,columns=['Name'])

data2=[[80, 81, 95, 100], [70, 71, 85, 90],[84, 82, 45, 80],[70, 61, 95, 74]]
df2 = pd.DataFrame(data2,columns=['Maths', 'Physics', 'Chemistry', 'Biology'])

# part-1
frames=[df1,df2]
dfNew= pd.concat(frames, axis=1)

# part-2
addCol= df2.sum(axis=1)
dfNew.insert(5, "Total", addCol)
print(dfNew)

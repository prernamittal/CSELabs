import pandas as pd

data1 = [['Dinesh', 80, 81, 95, 100],['Nithya', 70, 71, 85, 90],['Raji', 84, 82, 45, 80], ['Ram', 70, 61, 95, 74]]
df1 = pd.DataFrame(data1,columns=['Name','Quiz_1 /10', 'In-Sem_1 /15', 'Quiz_2 /10', 'In-Sem_2 /15'])

# part-1
addCol= df1.sum(axis=1, numeric_only=True)
df1.insert(5, "Total", addCol)
print(df1)

print("After calculating  mean")

# part-2
mean= df1.mean(axis=0, numeric_only=True)
df1.loc['Mean'] = mean
print(df1)
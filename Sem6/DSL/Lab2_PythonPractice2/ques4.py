import pandas as pd

# dictionary
data  = {'name': ['Anastasia', 'Dima', 'Katherine', 'James'],
        'height': [5, 6, 5.5, 5.9],
        'qualified': ['yes', 'no', 'yes', 'no']}

addCol = ['Noida', 'Manipal', 'Vellore', 'Shimla']
df = pd.DataFrame(data)

df.insert(3, "Address", addCol)
print(df)
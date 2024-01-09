months = ['January', 'February', 'March']
print(len(months))
print(months.count('January'))

print(months.append('April'))

del months[3]
print(months)

print('January' in months)
print('October' in months)

print(months.pop())

print(months.insert(1, "August"))

print(months.reverse())

print(months.clear())
list = [11, -21, 0, 45, 66, -93]
print("list Items = ", list)

for num in list:
    divid = num % 2
    if divid == 0 :
        list.remove(num)
        
print(f"List after removing all even numbers: {list}")
    
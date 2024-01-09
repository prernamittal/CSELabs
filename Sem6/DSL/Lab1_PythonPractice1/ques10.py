li = [11, -21, 0, 45, 66, -93]
print("li Items = ", li)

for num in li:
    divid = num % 2
    if divid == 0 :
        li.remove(num)
        
print(f"List after removing all even numbers: {li}")
    
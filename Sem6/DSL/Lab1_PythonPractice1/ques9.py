list = [11, -21, 0, 45, 66, -93]
print("list Items = ", list)
Ncount, Pcount = 0, 0

for i in range(len(list)):
    if(list[i] < 0):
        Ncount+=1
    if(list[i] > 0):
        Pcount+=1

print(f"\nThe number of Negative Numbers in this list are: {Ncount}")
print(f"\nThe number of Positive Numbers in this list are: {Pcount}")
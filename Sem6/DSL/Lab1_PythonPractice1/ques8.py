list = [11, -21, 0, 45, 66, -93]
print("list Items = ", list)

print("\nThe Negative Numbers in this list are:")
for i in range(len(list)):
    if(list[i] < 0):
        print(list[i], end = "  ")
print()
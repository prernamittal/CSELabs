li = [11, -21, 0, 45, 66, -93]
print("li Items = ", li)

print("\nThe Negative Numbers in this list are:")
for i in range(len(li)):
    if(li[i] < 0):
        print(li[i], end = "  ")
print()
tp = (12, 7, 38, 56, 78)
li = list()
for i in range(len(tp)):
	if(tp[i]%2 == 0):
		li.append(tp[i])

tp2 = tuple(li)
print(tp2)
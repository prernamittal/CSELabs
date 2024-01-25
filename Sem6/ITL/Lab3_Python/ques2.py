f1 = open("file2.txt", "w")

with open("file1.txt", "r") as myfile:
	data = myfile.read()

data1 = data[::-1]
f1.write(data1)
print("reverse text entered in file2")
f1.close()

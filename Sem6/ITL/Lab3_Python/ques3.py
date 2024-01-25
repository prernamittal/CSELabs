def binarySearch(arr, low, high, x):
	if high >= low:
		mid = (high + low) // 2
		if arr[mid] == x:
			return mid
		elif arr[mid] > x:
			return binarySearch(arr, low, mid - 1, x)
		else:
			return binarySearch(arr, mid + 1, high, x)
	else:
		return -1
	
n=int(input("Enter no. of elements: "))
arr=list(map(int,input("Enter elements: ").split()))
# arr=[]
# for i in range(0, n):
#     ele = int(input())
#     arr.append(ele)
x=int(input("Enter number to search: "))

result = binarySearch(arr, 0, len(arr)-1, x)

if result != -1:
	print("Element is present at index", str(result))
else:
	print("Element is not present in array")

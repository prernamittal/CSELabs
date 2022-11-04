import java.util.Scanner;
class prog3{
public static void main (String[] args)
{
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter lenght of array");
	int n = sc.nextInt();
	int arr[] = new int [n];
	int flag=0,i;
	for (i=0;i<n;i++)
	{
		System.out.println("Enter element at position: " + i);
		arr[i]=sc.nextInt();
	}
	System.out.println("Enter element to be found");
	int ele = sc.nextInt();
	for (i=0;i<n;i++)
	{
		if (arr[i]==ele)
		{
			System.out.println("Element" +ele+ "found at position" +i);
			flag=1;
		}
	}
	if (flag==0)
	{
		System.out.println("Element" +i+ "not found!");
	}

}
}
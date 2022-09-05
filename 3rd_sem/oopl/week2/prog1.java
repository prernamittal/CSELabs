import java.util.Scanner;
class prog1
{
	public static void main (String[] args)
	{
		Scanner sc = new Scanner (System.in);
		System.out.println("Enter Length of array");
		int n=sc.nextInt();
		int arr[]= new int[n];
		for (int i=0;i<n;i++)
		{
			System.out.println("Enter element at position: " + i);
			arr[i]=sc.nextInt();
		}
		int temp;
		System.out.println("Entyer 1 for ascending and 2 for descending");
		int choice = sc.nextInt();
		if (choice==1)
		{
			for (int i=0;i<n-1;i++)
			{
				for (int j=i;j<n-i-1;j++)
					{
						if (arr[j]>arr[j+1])
						{
							temp=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=temp;
						}
					}
			}
		}
		else if (choice==2)
		{
			for (int i=0;i<n-1;i++)
			{
				for (int j=i;j<n-i-1;j++)
					{
						if (arr[j]<arr[j+1])
						{
							temp=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=temp;
						}
					}
			}
		}
		else 
			{System.out.println("Error");
		System.exit(0);
			}
		for (int i=0; i<n-1; i++)
		{
			System.out.println(arr[i]+",");
		}
		System.out.println(arr[n-1]+ ",");
	}
}
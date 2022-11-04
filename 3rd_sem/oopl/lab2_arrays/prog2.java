import java.util.Scanner;
class prog2
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter length: ");
		int n = sc.nextInt();
		int arr[]=new int[n+1];
		for(int i=0;i<n;i++)
		{
			System.out.println("Enter element at position" + i);
			arr[i]= sc.nextInt();
		}
		System.out.println("1.Insert\n2.Delete");
		int choice=sc.nextInt();
		if (choice==1)
		{
			System.out.println("Enter element to be added: ");
			int ele = sc.nextInt();
			System.out.println("Enter position: ");
			int pos = sc.nextInt();
			for (int i=n-1;i>=(pos-1);i--)
			{
				arr[i+1]=arr[i];
			}
			arr [pos] = ele;
			System.out.println("The array is: ");
			for (int i=0;i<n;i++)
			{
				System.out.println(arr[i]);
			}
		}
		else if (choice==2)
		{
			System.out.println("Enter position: ");
			int pos = sc.nextInt();
			for (int i=pos;i<n-1;i++)
			{
				arr[i]=arr[i+1];
			}
			System.out.println("The array is: ");
			for (int i=0;i<n-1;i++)
			{
				System.out.println(arr[i]);
			}
		}

	}
}
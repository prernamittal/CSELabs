import  mypackages.p1.*;
import java.util.*;
public class prog2
{
    public static void main(String[] args)
    {
	   Scanner sc = new Scanner(System.in);
	   package2 p = new package2();
	   int choice;
	   do{
		System.out.println("\n\1.) Largest Integer \n\2.) Largest Float \n\3.) Largest in Array \n\4.)Largest in Matrix \n\5.)Quit \n\t Choice : ");
		choice = sc.nextInt();
 
		switch(choice)
		{
			case 1:
			
			System.out.println("Enter 3 numbers : ");
			int aa = sc.nextInt();
			int bb = sc.nextInt();
			int cc = sc.nextInt();
			System.out.println("Largest : " + p.max(aa,bb,cc));
			break;

			case 2:

			System.out.println("Enter 3 numbers : ");
			float a1 = sc.nextInt();
			float b1 = sc.nextInt();
			float c1 = sc.nextInt();
			System.out.println("Largest : " + p.max(a1,b1,c1));
			break;

			case 3:

			System.out.println("Size : ");
			int n1 = sc.nextInt();

			int arr[] = new int[n1];
			System.out.println("Enter Elements : ");

			for(int i=0;i<n1;i++)
			{
				arr[i] = sc.nextInt();
			}

			System.out.println("Largest : " + p.max(arr));
			break;

			case 4:

			System.out.println("Size : ");
			int r = sc.nextInt();
			int c = sc.nextInt();

			int mat[][] = new int[r][c];
			System.out.println("Enter Elements : ");

			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					mat[i][j] = sc.nextInt();
				}
				
			}
			System.out.println("Largest : " + p.max(mat));
			break;
			}
		} while(choice!=5);
	}

}
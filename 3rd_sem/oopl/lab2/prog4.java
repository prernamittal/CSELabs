import java.util.Scanner;
class prog4
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter rows of matrices");
		int r=sc.nextInt();
		System.out.println("Enter columns of matrices");
		int c=sc.nextInt();

		int arr[][] = new int[r][c]; 
		int brr[][] = new int[r][c];
		System.out.println("Enter elements of matrix ");
		for (int i=0;i<r;i++)
		    {
		    	for (int j=0;j<c;j++)
		    		{
		    			arr[i][j]=sc.nextInt();
		    		}
		    }
		System.out.println("Enter elements of matrix ");
		for (int i=0;i<r;i++)
		    {
		    	for (int j=0;j<c;j++)
		    		{
		    			brr[i][j]=sc.nextInt();
		    		}
		    }
		
		int sum[][]= new int[r][c];
        for(int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                sum[i][j] = arr[i][j] + brr[i][j];
            }
        }
        System.out.println("The resultant matrix is: ");
        for(int i=0;i<r;i++)
        {
        	for(int j=0;j<c;j++)
        		{
        			System.out.println(sum[i][j]);
        		}
        }

	}
} 
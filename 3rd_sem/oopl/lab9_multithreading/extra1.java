import java.util.*;
class matrix extends Thread{
    int n[],sum;
    matrix(int x[]) {
        n=x;
        start();
    }
    public void run() {
        sum=0;
        for(int i=0;i<3;i++)
        {
            sum+=n[i];
        }
        System.out.println("sum="+sum);
    }
}
public class extra1 {
    public static void  main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter n: ");
        int n=sc.nextInt();
        matrix ob1 = new matrix(new int[]{1,2,3});
        try{
            System.out.println("Sleeping");
            Thread.sleep(1000);
        }
        catch(InterruptedException e) {
            System.out.println("Exception occured");
        }
        sc.close();
    }
}
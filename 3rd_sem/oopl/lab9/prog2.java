class Matrix implements Runnable
{
    int n[],sum;
    Thread t;
    Matrix(int x[],int p)
    {
        n=x;
        t= new Thread(this);
        t.setPriority(p);
        t.start();
    }
    public void run()
    {
        sum=0;
        for(int i=0;i<3;i++)
        {
            sum+=n[i];
        }
        System.out.println("sum="+sum);
    }
    int Sum()
    {
        return sum;
    }
}
public class prog2
{
    public static void main(String[] args)
    {
        int mat[][]={{1,2,3},{4,5,6},{7,8,9}};
        int sum=0;
        Matrix row[]=new Matrix[3];
        Matrix r1 = new Matrix(mat[0],6);
        Matrix r2 = new Matrix(mat[1],5);
        Matrix r3 = new Matrix(mat[2],9);
        try {
            Thread.sleep(1);
        } catch (InterruptedException e) {
            System.out.println("Interrupted lmao");
        }
        sum=r1.Sum()+r2.Sum()+r3.Sum();
        System.out.println("Total matrix sum: "+sum);
    }
}
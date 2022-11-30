import java.util.*;
class sum
{
    int sum;
    synchronized int sum(int[] num){
        sum=0;
        for(int i=0;i<num.length;i++){
            sum+=num[i];
            //System.out.println("Total of "+Thread.currentThread().getName()+" is "+ sum);
        
            try{
                Thread.sleep(10);
            }
            catch(InterruptedException e){
                System.out.println("Interrupted");
            }
        }
        return sum;
    }
}
class MyThread implements Runnable{
    Thread t;
    sum s = new sum();
    int arr[], res;
    MyThread(String name, int[] num){
        t =new Thread(this, name);
        arr=num;
        t.start();
    }
    public void run(){
        int sum;
        System.out.println(t.getName()+" is starting");
        res=s.sum(arr);
        System.out.println("Sum for "+t.getName()+" is "+res);
        System.out.println(t.getName()+" terminating");
    }
}
public class sumarray{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length: ");
        int len=sc.nextInt();
        System.out.println("Enter ele: ");
        int arr[]=new int[len];
        for(int j=0;j<len;j++){
            for(int i=0;i<len;i++)
            {
                arr[i]=sc.nextInt();
            }
        }
        MyThread m1= new MyThread("thread1",arr);
        //MyThread m2= new MyThread("thread2",arr);
        try{
            m1.t.join();
            // m2.t.join();
        }
        catch(InterruptedException e){
            System.out.println("Interrupted");
        }

    }
}
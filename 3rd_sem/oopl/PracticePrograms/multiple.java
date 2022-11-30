// class morethread implements Runnable{
//     Thread t;
//     morethread(String s){
//         t= new Thread(this, s);
//         t.start();
//     }
//     public void run(){
//         System.out.println(t.getName()+" is starting");
//         try{
//             for(int i=0;i<5;i++){
//                 Thread.sleep(100);
//                 System.out.println("sleeping");
//             }
//         }
//         catch(InterruptedException e)
//         {
//             System.out.println("Interrupted");
//         }
//         System.out.println("ending");
//     }
// }
// public class multiple{
//     public static void main(String[] args){
//         System.out.println("Main thread...");
//         morethread m1= new morethread("Thread1");
//         morethread m2= new morethread("Thread2");
//         morethread m3= new morethread("Thread3");
//         for(int i=0;i<5;i++){
//             System.out.println("...");
//             try{
//                 Thread.sleep(100);
//             }
//             catch(InterruptedException e){
//                 System.out.println("Interrupted");
//             }
//         }
//         System.out.println("main thread ending");
//     }
// }
class morethread extends Thread{
    Thread t;
    morethread(String s){
        super(s);
        start();
    }
    public void run(){
        System.out.println(getName()+" is starting");
        try{
            for(int i=0;i<5;i++){
                Thread.sleep(400);
                System.out.println("sleeping");
            }
        }
        catch(InterruptedException e)
        {
            System.out.println("Interrupted");
        }
        System.out.println("ending");
    }
}
public class multiple{
    public static void main(String[] args){
        System.out.println("Main thread...");
        morethread m1= new morethread("Thread1");
        morethread m2= new morethread("Thread2");
        morethread m3= new morethread("Thread3");
        for(int i=0;i<5;i++){
            System.out.println("...");
            try{
                Thread.sleep(100);
            }
            catch(InterruptedException e){
                System.out.println("Interrupted");
            }
        }
        System.out.println("main thread ending");
    }
}
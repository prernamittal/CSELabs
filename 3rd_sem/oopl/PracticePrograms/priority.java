class Thread1 extends Thread{
    Thread1(String s)
    {
        super(s);
        start();
    }
    public void run()
    {
        for(int i=0;i<5;i++){
            Thread cur = Thread.currentThread();
            cur.setPriority(Thread.MAX_PRIORITY);
            cur.getPriority();
            System.out.println("Thread details: "+Thread.currentThread().getName()+ "    priority is: "+cur);
        }
    }
}
class Thread2 extends Thread{
    Thread2(String s){
        super(s);
        start();
    }
    public void run(){
        for(int i=0;i<5;i++){
            Thread cur = Thread.currentThread();
            cur.setPriority(Thread.MIN_PRIORITY);
            cur.getPriority();
            System.out.println("Thread details: "+Thread.currentThread().getName()+ "   priority is: "+cur);
        }       
    }
}
public class priority{
    public static void main(String[] args){
        Thread1 t1=new Thread1("Prerna");
        Thread t2= new Thread2("Mittal");
        System.out.println(t1+ " is running");
        System.out.println(t2+ " is running");
    }
}
class Shop{
    int n=0;
    boolean value=false;
    synchronized int get(){
        while(!value){
            try{
                wait();
            }
            catch(InterruptedException e){
                System.out.println("Interrupted");
            }}
            System.out.println("Got: "+n);
            value=false;
            notify();
            return n;
    }
    synchronized void put(int n){
        while(value){
            try{
                wait();
            }
            catch(InterruptedException e){
                System.out.println("Interrupted");
            }}
            this.n=n;
            value=true;
            System.out.println("Put: "+n);
            notify();
    }
}
class Producer implements Runnable{
    Shop shop;
    Thread t;
    Producer(Shop shop){
        this.shop=shop;
        t=new Thread (this, "Producer");
    }
    public void run(){
        int i=0;
        while(true){
            shop.put(i++);
        }
    }
}
class Consumer implements Runnable{
    Shop shop;
    Thread t;
    Consumer(Shop shop){
        this.shop=shop;
        t=new Thread(this,"Consumer");
    }
    public void run(){
        while(true){
            shop.get();
        }
    }
}
public class prog3{
    public static void main(String[] args){
        Shop shop=new Shop();
        Producer p= new Producer(shop);
        Consumer c=new Consumer(shop);
        p.t.start();
        c.t.start();
        System.out.println("Press Ctr-C to Stop");
    }
}
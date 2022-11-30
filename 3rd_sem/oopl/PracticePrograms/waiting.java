public class waiting {
    static void threadMessage(String message) {
        String threadName = Thread.currentThread().getName();
        System.out.format("%s: %s%n",threadName, message);
}
    private static class msgloop implements Runnable {
    public void run() {
        String info[] = {"string1","string2","string3","string4"};
        try {
        for (int i = 0; i < info.length; i++) {
            Thread.sleep(100*70);
            threadMessage(info[i]);
        }
        } catch (InterruptedException e) {threadMessage("I wasn't done!");
        }
    }
}
public static void main(String args[])throws InterruptedException {
    long patience = 100*60;
    
    threadMessage("Starting msgloop thread");
        long startTime = System.currentTimeMillis();
        Thread t = new Thread(new msgloop());
        t.start();

        threadMessage("Waiting for msgloop thread to finish");
        while (t.isAlive()) {
            threadMessage("Still waiting...");
            t.join(100*60);
            if (((System.currentTimeMillis() - startTime) > patience)&& t.isAlive()) {
                threadMessage("Tired of waiting!");
                t.interrupt();
                t.join();
            }
        }
        threadMessage("Finally!");
    }
}
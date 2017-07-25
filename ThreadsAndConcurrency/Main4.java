import java.util.Random;
import java.util.concurrent.Semaphore;

public class Main4 {

    private static String[] arr1 = {
        "How", "are", "you?"
    };
    private static String[] arr2 = {
        "What", "is", "your", "name?"
    };
    private static String buffer = "";
    private static Semaphore mutex = new Semaphore(1);

    public static void main(String[] args) {
        new Thread(new Runnable() {

            public void run() {
                for (int i = 0; i < arr1.length; i++) {
                    try {
//Entering the critical section now.
                        mutex.acquire();
                        buffer = arr1[i];
                        Thread.sleep(Math.abs(new Random().nextInt(100)));
                        System.out.println("Task1: [" + arr1[i] + "] is read and the echo is [" + buffer + "]");
                        mutex.release();
//Leaving the critical section now.
                    } catch (InterruptedException ex) {
                    }
                }
            }
        }).start();
        new Thread(new Runnable() {

            public void run() {
                for (int i = 0; i < arr2.length; i++) {
                    try {
//Entering the critical section now.
                        mutex.acquire();
                        buffer = arr2[i];
                        Thread.sleep(Math.abs(new Random().nextInt(100)));
                        System.out.println("Task2: [" + arr2[i] + "] is read and the echo is [" + buffer + "]");
                        mutex.release();
//Leaving the critical section now.
                    } catch (InterruptedException ex) {
                    }
                }
            }
        }).start();
    new java.util.Scanner(System.in).nextLine();
	}
}
public class Main2 {

    public static void main(String[] args) {
        new Thread(new Runnable() {

            public void run() {
                for (int i = 0; i < 10; i++) {
                    try {
                        Thread.sleep(100);
                        System.out.println("Task1: doing useful work.");
                    } catch (InterruptedException ex) {
                    }
                }
            }
        }).start();

        new Thread(new Runnable() {

            public void run() {
                for (int i = 0; i < 10; i++) {
                    try {
                        Thread.sleep(100);
                        System.out.println("Task2: doing useful work.");
                    } catch (InterruptedException ex) {
                    }
                }
            }
        }).start();
    new java.util.Scanner(System.in).nextLine();
	}
}

public class Main {

    public static void main(String[] args) {
        Main myMain = new Main();
        myMain.RunTask1();
        myMain.RunTask2();
	new java.util.Scanner(System.in).nextLine();
    }

    private void RunTask1() {
        for (int i = 0; i < 10; i++) {
            try {
                Thread.sleep(100);
                System.out.println("Task1: doing some useful work.");
            } catch (InterruptedException ex) {
            }
        }
    }

    private void RunTask2() {
        for (int i = 0; i < 10; i++) {
            try {
                Thread.sleep(100);
                System.out.println("Task2: doing some useful work.");
            } catch (InterruptedException ex) {
            }
        }
    }
}

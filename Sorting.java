import java.util.Scanner;

class Sorting {

    public static void main(String anbs[]) {

        Scanner d = new Scanner(System.in);

        System.out.print("How namy elements you wants to enter in array: ");
        int n = d.nextInt();

        int[] a = new int[n];
        System.out.println("Enter Array Elements: ");

        for (int i = 0; i < n; i++) {
            a[i] = d.nextInt();
        }

        for (int i = 0; i < (n - 1); i++) {
            for (int j = (i + 1); j < n; j++) {

                if (a[i] > a[j]) {

                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        System.out.println("sorted array:  ");

        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
import java.util.Scanner;

public class ArrayMinMax {

    public static void getMinMax(long[] a) {
        long maxNo = Long.MIN_VALUE; // Use Long.MIN_VALUE for long data type
        long minNo = Long.MAX_VALUE;

        for (int i = 0; i < a.length; i++) {
            if (a[i] > maxNo) {
                maxNo = a[i];
            }
            if (a[i] < minNo) {
                minNo = a[i];
            }
        }

        System.out.println("min = " + minNo);
        System.out.println("max = " + maxNo);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong(); // Use nextLong() for long data type
        }

        getMinMax(a); // No need to pass array length as parameter

        // Print the fourth element (assuming indexing starts from 0)
        System.out.println(a[3]);
    }
}

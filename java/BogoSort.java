import java.util.Arrays;
import java.util.Random;

public class BogoSort {
    
    // Function to shuffle the array randomly
    public static void shuffle(int[] array) {
        Random rand = new Random();
        for (int i = 0; i < array.length; i++) {
            int randomIndex = rand.nextInt(array.length);
            // Swap elements
            int temp = array[i];
            array[i] = array[randomIndex];
            array[randomIndex] = temp;
        }
    }

    // Function to check if the array is sorted
    public static boolean isSorted(int[] array) {
        for (int i = 1; i < array.length; i++) {
            if (array[i - 1] > array[i]) {
                return false;
            }
        }
        return true;
    }

    // Bogosort implementation
    public static void bogoSort(int[] array) {
        // Keep shuffling until the array is sorted
        while (!isSorted(array)) {
            shuffle(array);
        }
    }

    public static void main(String[] args) {
        // Example array
        int[] array = {3, 2, 5, 1, 4};

        System.out.println("Unsorted array: " + Arrays.toString(array));

        // Apply Bogosort
        bogoSort(array);

        System.out.println("Sorted array: " + Arrays.toString(array));
    }
}

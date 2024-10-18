import java.util.ArrayList;
import java.util.Collections;

public class BucketSort {
    
    // Function to perform bucket sort
    public static void bucketSort(float[] array, int numBuckets) {
        // Create empty buckets
        ArrayList<Float>[] buckets = new ArrayList[numBuckets];
        
        // Initialize each bucket
        for (int i = 0; i < numBuckets; i++) {
            buckets[i] = new ArrayList<>();
        }

        // Put array elements into different buckets based on their value
        for (int i = 0; i < array.length; i++) {
            int bucketIndex = (int) (array[i] * numBuckets); // Bucket index based on value
            buckets[bucketIndex].add(array[i]);
        }

        // Sort individual buckets using Collections.sort
        for (int i = 0; i < numBuckets; i++) {
            Collections.sort(buckets[i]);
        }

        // Concatenate all buckets into the original array
        int index = 0;
        for (int i = 0; i < numBuckets; i++) {
            for (float value : buckets[i]) {
                array[index++] = value;
            }
        }
    }

    // Utility function to print the array
    public static void printArray(float[] array) {
        for (float value : array) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        float[] array = { (float) 0.42, (float) 0.32, (float) 0.33, (float) 0.52, (float) 0.37, (float) 0.47, (float) 0.51 };

        System.out.println("Unsorted array:");
        printArray(array);

        // Perform bucket sort
        bucketSort(array, 5);

        System.out.println("Sorted array:");
        printArray(array);
    }
}

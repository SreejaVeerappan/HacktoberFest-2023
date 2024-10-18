#include <iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int array[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoid overflow with this calculation

        // Check if target is present at mid
        if (array[mid] == target) {
            return mid;  // Target found at index mid
        }

        // If target is greater, ignore the left half
        if (array[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Target not found
    return -1;
}

int main() {
    int array[] = {2, 3, 4, 10, 40};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 10;

    // Perform binary search
    int result = binarySearch(array, size, target);

    // Output the result
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

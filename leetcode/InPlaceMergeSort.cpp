#include <iostream>
using namespace std;

// Utility function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to merge two halves of the array in place
void inPlaceMerge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;

    // Traverse and merge the two halves
    while (i <= mid && j <= right) {
        // If the element at the left half is smaller or equal, no need to swap
        if (arr[i] <= arr[j]) {
            i++;
        } else {
            // If the element at the right half is smaller, we need to shift all elements
            // between arr[i] and arr[j] to the right by one and move arr[j] to arr[i]
            int temp = arr[j];
            for (int k = j; k > i; k--) {
                arr[k] = arr[k - 1];
            }
            arr[i] = temp;

            // Update indices
            i++;
            mid++;
            j++;
        }
    }
}

// Recursive Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the left and right halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the two halves in place
        inPlaceMerge(arr, left, mid, right);
    }
}

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function to test the in-place Merge Sort
int main() {
    int arr[] = {100, 27, 43, 3, 9, 82, -1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array: ";
    printArray(arr, arr_size);

    return 0;
}

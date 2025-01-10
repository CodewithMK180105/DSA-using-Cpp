#include <iostream>
#include <vector>
#include <algorithm> // For swap function
using namespace std;

// Function to sort the first k elements using insertion sort
void partialSort(vector<int>& arr, int k) {
    for (int i = 1; i < k; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to find the k-th smallest element
int findKthSmallest(vector<int>& arr, int k) {
    int n = arr.size();

    // Step 1: Sort the first k elements
    partialSort(arr, k);

    // Step 2: Iterate through the remaining elements
    for (int i = k; i < n; i++) {
        if (arr[i] < arr[k - 1]) {
            // Place the current element in the sorted part
            arr[k - 1] = arr[i];

            // Restore the sorted order of the first k elements
            partialSort(arr, k);
        }
    }

    // Step 3: Return the k-th smallest element
    return arr[k - 1];
}

int main() {
    vector<int> arr = {5,4,7,8,1,2,3,6};
    int k = 3; // Change k to find a different k-th smallest element

    if (k > 0 && k <= arr.size()) {
        int kthSmallest = findKthSmallest(arr, k);
        cout << "The " << k << "-th smallest element is: " << kthSmallest << endl;
    } else {
        cout << "Invalid value of k." << endl;
    }

    return 0;
}

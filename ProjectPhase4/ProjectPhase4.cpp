#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void reverseSortedArray(int *arr, int size) {
    sort(arr, arr + size, greater<int>());
}

void sortedArray(int *arr, int size) {
    sort(arr, arr + size);
}

// Bubble Sort algorithm using std::swap
void bubbleSort(int arr[], int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Use std::swap
            }
        }
    }
}

int partition(int *array, int left, int pivot) {
    int low = left - 1; // We set it low as an invalid index so it doesn't account for index 0 when comparing the value to the pivot
    int high = pivot - 1; // Since the pivot is the last element of the array, the high would be the second to last element in the subarray

    for (int k = left; k <= high; k++) {
        if (array[k] <= array[pivot]) {
            low++; // Iterates
            swap(array[low], array[k]); // Use std::swap
        }
    }
    swap(array[low + 1], array[pivot]); // This will make sure the pivot element is placed in between the two subarrays
    return low + 1;
}

void QuickSort(int *array, int left, int pivot) {
    if (left < pivot) {
        int new_pivot = partition(array, left, pivot);
        QuickSort(array, left, new_pivot - 1); // Recursively sorts through the left subarray
        QuickSort(array, new_pivot + 1, pivot); // Recursively sorts through the right subarray
    }
}

void merge(int* arr, int start, int mid, int end){
    //find our sizes for the left and right array 
    int lsize = mid - start + 1;
    int rsize = end - mid;
    
    //create left and right array
    int* left = new int[lsize];
    int* right = new int[rsize];
    
    //add elements that belong in the left array
    for(int i = 0; i < lsize; i++){
        left[i] = arr[start + i];
    }
    //add elements that belong in the right array
    for(int i = 0; i < rsize; i++){
        right[i] = arr[mid + 1 + i];
    }
    
    //set our indexes of the left and right array
    int indexLeft = 0;
    int indexRight = 0;
    
    //set our i to where the array was split in start depending on where it was called recursively
    int i = start;
    
    //add elemtns to the main array based on smallest to greatest
    while(indexLeft < lsize && indexRight < rsize){
        if(left[indexLeft] < right[indexRight]){
            arr[i++] = left[indexLeft++];
        }
        else{
            arr[i++] = right[indexRight++];
        }
    }
    
    //based on what array was iterated through first in the prev loop some elemtns may have not been added so we have two loops one for left and one
    //for the right to add those elements that were left out.
    while(indexLeft < lsize){
        arr[i++] = left[indexLeft++];
    }
    while(indexRight < rsize){
        arr[i++] = right[indexRight++];
    }

}

void mergeSort(int* arr, int start, int end){
    //If start is greater than end then we have singled out the element
    if(start >= end){
        return;
    }
    //find our middle point in the array to sort left and right
    int mid = (start + end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main() {
    srand(time(NULL));
    // Initializing array with arbitrary large number of elements
    // Due to issues with a normal array having a specific max number of elements, dynamic array will be more viable
    int sizeOfArray;
    cout << "Select the size of the array: ";
    cin >> sizeOfArray;

    // Ensure the array size is positive
    if (sizeOfArray <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    int* Array = new int[sizeOfArray];

    // N holds the range of the number which would be random so it needs to be displayed to the user for later use when searching in the array
    int N = rand() % (sizeOfArray + 1);

    // Iterate through the array so it holds random values within range of N
    for (int i = 0; i < sizeOfArray; i++) {
        Array[i] = rand() % N + 1;
    }

    int sortOption, arrayOption;
    cout << "Choose a sorting algorithm:\n";
    cout << "1. Quick Sort\n";
    cout << "2. Bubble Sort\n";
    cout << "3. Merge Sort\n";
    cin >> sortOption;

    cout << "Choose an array type:\n";
    cout << "1. Sorted Array\n";
    cout << "2. Reverse Sorted Array\n";
    cout << "3. Random Element Array\n";
    cin >> arrayOption;

    switch (arrayOption) {
        case 1:
            cout << "Sorting a Sorted Array\n";
            sortedArray(Array, sizeOfArray);
            break;
        case 2:
            cout << "Sorting a Reverse Sorted Array\n";
            reverseSortedArray(Array, sizeOfArray);
            break;
        case 3:
            cout << "Sorting a Random Element Array\n";
            break;
        default:
            cout << "Invalid array choice\n";
            delete[] Array;
            return 1;
    }

    switch (sortOption) {
        case 1: {
            cout << "Using Quick Sort\n";
            clock_t tStart = clock();
            QuickSort(Array, 0, sizeOfArray - 1);
            clock_t tEnd = clock();
            cout << "Time taken: " << static_cast<double>(tEnd - tStart) / CLOCKS_PER_SEC << " seconds\n";
            break;
        }
        case 2: {
            cout << "Using Bubble Sort\n";
            clock_t tStart = clock();
            bubbleSort(Array, sizeOfArray);
            clock_t tEnd = clock();
            cout << "Time taken: " << static_cast<double>(tEnd - tStart) / CLOCKS_PER_SEC << " seconds\n";
            break;
        }
        case 3: {
            cout << "Using Merge Sort\n";
            clock_t tStart = clock();
            mergeSort(Array, 0, sizeOfArray - 1);
            clock_t tEnd = clock();
            cout << "Time taken: " << static_cast<double>(tEnd - tStart) / CLOCKS_PER_SEC << " seconds\n";
            break;
        }
        default:
            cout << "Invalid sorting algorithm choice\n";
            delete[] Array;
            return 1;
    }

    delete[] Array;
    return 0;
}

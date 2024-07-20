#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;


void reverseSortedArray(int *arr, int size){
    sort(arr, arr + size, greater<int>());
}
void sortedArray(int *arr, int size){
    sort(arr, arr + size);
}


//swap function used for quick sort
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *array, int left, int pivot){
    int low = left - 1; //We set it low as an invalid index so it doesnt account for index 0 when comparing the value to the pivot 

    int high = pivot - 1; //since the pivot is the last element of the array the high would be the second to last element in the sub array

    for (int k = left; k <= high; k++){

        if(array[k] <= array[pivot]){
            low++; //iterates

            swap(&array[low], &array[k]);
        }
    }
    swap(&array[low + 1], &array[pivot]); //this will make sure the pivot element is placed in between the two sub-arrays

    return low + 1;
}

void QuickSort(int *array, int left, int pivot){
    if (left < pivot){
        int new_pivot = partition(array, left, pivot);

        QuickSort(array, left, new_pivot - 1); //recursively sorts through the left sub array 

        QuickSort(array, new_pivot + 1, pivot); //recursively sorts through the right sub array
    }
}


int main(){
    srand(time(NULL));
    //initialzing array with arbitrary large number of elements
    //due to issues with a normal array having a specific max number of elements, dynamic array will be more viable
    int sizeOfArray;
    cout << "Select the size of the array" << endl;
    cin >> sizeOfArray;
    int* Array = new int[sizeOfArray];
    
    
    //N holds the range of the number which would be random so it needs to be displayed to the user for later use when searching in the array
    int N = rand() % (sizeOfArray + 1);

    //Iterated through the array so it holds random values within range of N
    for (int i = 0; i < sizeOfArray; i++){
        Array[i] = rand() % N + 1;
    }

    int option;
    
    cout << "Choose an option" << endl;
    cout << "1. Quick Sort on a Sorted Array \n2. Quick Sort on Reverse Sorted Array \n3. Quick Sort on a Random Element Array"<< endl;
    
    cin >> option;
    clock_t tStart, tEnd;
    switch(option){
        case 1: {
            cout << "Quick Sort on a Sorted Array" << endl;
            sortedArray(Array, sizeOfArray);
            
            clock_t tStart = clock();
            QuickSort(Array, 0, sizeOfArray - 1);
            clock_t tEnd = clock();
            
            cout<<"Time taken:"<<(double)(tEnd - tStart)/ CLOCKS_PER_SEC << endl;
            break;
        }    
        case 2: {
            cout << "Quick Sort on a Reverse Sorted Array" << endl;
            reverseSortedArray(Array, sizeOfArray);

            clock_t tStart = clock();
            QuickSort(Array, 0, sizeOfArray - 1);
            clock_t tEnd = clock();

            cout<<"Time taken:"<<(double)(tEnd - tStart)/ CLOCKS_PER_SEC << endl;
            break;
        }
        case 3: {
            cout << "Quick Sort on a Random Element Array" << endl;
            
            clock_t tStart = clock();
            QuickSort(Array, 0, sizeOfArray - 1);
            clock_t tEnd = clock();

            cout<<"Time taken:"<<(double)(tEnd - tStart)/ CLOCKS_PER_SEC << endl;
            break;
        }
        default:
            cout << "Invalid choice" << endl;
            delete[] Array;
            return 1;
    }

    delete [] Array;
    return 0;
}
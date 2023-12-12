// Name: Shubham Nikumbh
// Roll:22569
#include <iostream>
using namespace std;

template <class T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

template <class T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Example with integers
    int intArray[] = {64, 25, 12, 22, 11};
    int intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    
    cout << "Before sorting (integers): ";
    printArray(intArray, intArraySize);
    
    selectionSort(intArray, intArraySize);

    cout << "After sorting (integers): ";
    printArray(intArray, intArraySize);

    // Example with doubles
    double doubleArray[] = {5.4, 3.2, 9.8, 1.2, 7.6};
    int doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    
    cout << "\nBefore sorting (doubles): ";
    printArray(doubleArray, doubleArraySize);
    
    selectionSort(doubleArray, doubleArraySize);

    cout << "After sorting (doubles): ";
    printArray(doubleArray, doubleArraySize);

    return 0;
}


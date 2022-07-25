#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void getSize(int &size)
{
    cout << " Please Enter The Array Size: ";
    cin >> size;
}

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << " " << arr[i] << endl;
}

void initArray(int arr[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 101;
}

void Swap(int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;
}

int minimum(int arr[], int size, int first)
{
    int Min = first;

    for (int i = (first + 1); i <= size; i++)
        if (arr[i] < arr[Min])
            Min = i;

    return Min;
}

void bubbleSort(int arr[], int size)  // T(n) = O(n^2) -> Time Comlexity
{
    // The Bubble Sort Algorithm
    for (int i = 1; i < size; i++){

        for (int j = 0; j < (size - i); j++){

            if (arr[j] > arr[j + 1]){
                Swap(arr[j], arr[j + 1]);
            }

        }
    }
}

void selectionSort(int arr[], int size)  // T(n) = O(n^2) -> Time Comlexity
{
    // The Selection Sort Algorithm
    for (int i = 0; i < (size - 1); i++){

        int minIndex = minimum(arr, size - 1, i);

        if (i != minIndex)
            Swap(arr[minIndex], arr[i]);
    }
}

// The main
int main()
{
    int *array1 = NULL;
    int *array2 = NULL;

    int size1 = 1;
    int size2 = 1;

    getSize(size1);
    array1 = new int[size1];
    initArray(array1, size1);

    cout << " The Array Is Not Sorted:" << endl;
    displayArray(array1, size1);  // The array is not sorted yet

    bubbleSort(array1, size1);    // Call The Bubble Sort Algorithm

    cout << " The Array Is Sorted Using The Bubble Sort Algorithm:" << endl;
    displayArray(array1, size1);  // The array is sorted

    getSize(size2);
    array2 = new int[size2];
    initArray(array2, size2);

    cout << " The Array Is Not Sorted:" << endl;
    displayArray(array2, size2);  // The array is not sorted yet

    selectionSort(array2, size2);    // Call The Selection Sort Algorithm

    cout << " The Array Is Sorted Using The Selection Sort Algorithm:" << endl;
    displayArray(array2, size2);  // The array is sorted

    delete [] array1;
    delete [] array2;
    array1 = NULL;
    array2 = NULL;

    return 0;
}

#include <iostream>
using namespace std;
class heap
{
public:
    int *arr;
    int capacity;
    int size;
    heap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        // size=current number of elemnts in heap
        this->size = 0;
    }
    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "heap Overflow" << endl;
        }
        size++;
        int index = size;
        arr[index] = val;

        // take the value to its correct position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[parentIndex] < arr[index])
            {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    int deleteH()
    {
        int answer = arr[1];
        arr[1] = arr[size];
        size--;
        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int largestIndex = index;

            if (largestIndex <= size && arr[largestIndex] < arr[leftIndex])
            {
                largestIndex = leftIndex;
            }
            if (largestIndex <= size && arr[largestIndex] < arr[rightIndex])
            {
                largestIndex = rightIndex;
            }
            if (index == largestIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
        }
        return answer;
    }
    void printHeap()
    {
        for (int i = 0; i <= 9; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void heapify(int arr[], int n, int index)
    {
        int leftIndex = 2 * index;
        int rightIndex = 2 * index + 1;
        int largestIndex = index;

        // teno me se max lao
        if (leftIndex <= n && arr[largestIndex] < arr[leftIndex])
        {
            largestIndex = leftIndex;
        }
        if (rightIndex <= n && arr[largestIndex] < arr[rightIndex])
        {
            largestIndex = rightIndex;
        }
        if (index != largestIndex)
        {
            swap(arr[index], arr[largestIndex]);
            index = largestIndex;
            heapify(arr, n, index);
        }
    }
    void buildHeap(int arr[], int n)
    {
        for (int index = n / 2; index > 0; index--)
        {
            heapify(arr, n, index);
        }
    }
    void heapSort(int arr[], int n)
    {
        while (n > 1)
        {
            // 1 -based indexing
            swap(arr[1], arr[n]);
            n--;
            // root ko heapify karenge
            heapify(arr, n, 1);
        }
    }
};
void printHeap(int arr[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}
void heapify(int arr[], int n, int index)
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestIndex = index;

    // teno me se max lao
    if (leftIndex <= n && arr[largestIndex] < arr[leftIndex])
    {
        largestIndex = leftIndex;
    }
    if (rightIndex <= n && arr[largestIndex] < arr[rightIndex])
    {
        largestIndex = rightIndex;
    }
    if (index != largestIndex)
    {
        swap(arr[index], arr[largestIndex]);
        index = largestIndex;
        heapify(arr, n, index);
    }
}
void buildHeap(int arr[], int n)
{
    for (int index = n / 2; index > 0; index--)
    {
        heapify(arr, n, index);
    }
}
void heapSort(int arr[], int n)
{
    while (n > 1)
    {
        // 1 -based indexing
        swap(arr[1], arr[n]);
        n--;
        // root ko heapify karenge
        heapify(arr, n, 1);
    }
}
int main()
{

    int arr[] = {5, 10, 15, 20, 25, 12};
    int n = 6;
    buildHeap(arr, 6);
    cout << "printing the elements of heap: " << endl;
    for (int i = 0; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    heapSort(arr, n);
    cout << "printing the elements of heap: " << endl;
    for (int i = 0; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // heap h(20);
    // h.insert(100);
    // h.insert(50);
    // h.insert(60);
    // h.insert(40);
    // h.insert(30);
    // h.insert(20);
    // h.insert(10);
    // h.insert(31);
    // h.insert(42);
    // cout << "printing the elements of heap: " << endl;
    // h.printHeap();
    // int answer = h.deleteH();
    // cout << "ans:" << answer;
    // h.printHeap();
    return 0;
}
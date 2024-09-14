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
        // size =current number of elements in heap
        this->capacity = capacity;
        this->size = 0;
    }
    void insert(int val)
    {
        if (capacity == size)
        {
            cout << "heap Overflow" << endl;
            return;
        }
        // size increase kar jaega
        size++;
        int index = size;
        arr[index] = val;

        // take the value to its correct position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void printHeap()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    int deleteFromheap()
    {
        int answer = arr[1];
        // replacement
        arr[1] = arr[size];
        // last element ko delete uski original position se
        size--;

        // heapification
        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            // find out kaarna hai , sabse bada kaun hai
            int largestKaindex = index;
            // check left child
            if (leftIndex <= size && arr[largestKaindex] < arr[leftIndex])
            {
                largestKaindex = leftIndex;
            }
            if (rightIndex <= size && arr[largestKaindex] < arr[rightIndex])
            {
                largestKaindex = rightIndex;
            }
            // no change
            if (index == largestKaindex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestKaindex]);
                index = largestKaindex;
            }
        }
        return answer;
    }
};
// v.v.v.important
void heapify(int *arr, int n, int index)
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestKaindex = index;

    // teno me se max lao
    if (leftIndex <= n && arr[leftIndex] > arr[largestKaindex])
    {
        largestKaindex = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] > arr[largestKaindex])
    {
        largestKaindex = rightIndex;
    }
    // after these 2 conditions largestkaindex will be pointing to the largest element among 3
    if (index != largestKaindex)
    {
        swap(arr[index], arr[largestKaindex]);
        // ab recursion sambhal lega
        index = largestKaindex;
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
    while (n != 1)
    {
        // yahan par 1 based indexing hogi ,
        // isiliye arr[1] arr[n] ke saath swap karega
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}
int main()
{
    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    int n = 6;
    buildHeap(arr, 6);
    cout << "printing heap:" << endl;
    for (int i = 1; i <=6; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
    cout << endl;
    heapSort(arr, n);
    cout << "printing heap:" << endl;
    for (int i = 1; i <= 6; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
    cout << endl;
    //     heap h(20);
    //     // inertion
    //     h.insert(10);
    //     h.insert(20);
    //     h.insert(5);
    //     h.insert(11);
    //     h.insert(6);

    //     cout << "Printing the content of heap" << endl;
    //     h.printHeap();
    //     cout << endl;
    //     int ans = h.deleteFromheap();
    //     cout << "answer: " << ans << endl;
    //     h.printHeap();

    //     return 0;
}
//output
// printing heap:
// 25 20 12 15 5 10
// printing heap:
// 5 10 12 15 20 25
//correction in above code


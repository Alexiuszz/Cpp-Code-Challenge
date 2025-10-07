#include <iostream>
#include <vector>
#include <algorithm>

// The HEAPSORT procedure, which runs in O.n lg n/ time, sorts an array in place.
//  The MAX-HEAP-INSERT, HEAP-EXTRACT-MAX, HEAP-INCREASE-KEY,
//  and HEAP-MAXIMUM procedures, which run in O.lg n/ time, allow the heap
//  data structure to implement a priority queue.
class Heap
{
private:
    int GetLeft(int i);
    int GetRight(int i);

public:
    void MaxHeapifyRec(std::vector<int> &a, int i, int heapSize);
    void MaxHeapify(std::vector<int> &a, int i, int heapSize);
    void MinHeapify(std::vector<int> &a, int i, int heapSize);
    void BuildHeap(std::vector<int> &a);

    void HeapSort(std::vector<int> &a);
};

int Heap::GetLeft(int i)
{
    return 2 * i + 1;
}
int Heap::GetRight(int i)
{
    return 2 * i + 2;
}

void Heap::HeapSort(std::vector<int> &a)
{
    if (a.size() <= 1)
        return;

    BuildHeap(a);
    int n = static_cast<int>(a.size());
    int heapSize = n;
    for (int i = n - 1; i > 0; --i)
    {
        std::swap(a[0], a[i]);
        heapSize = heapSize - 1;
        MaxHeapify(a, 0, heapSize);
    }
}

void Heap::MinHeapify(std::vector<int> &a, int i, int heapSize){
    while(true){
        int smallest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if(l<heapSize && a[l] < a[smallest]) smallest = l;
        if(r<heapSize && a[r] < a[smallest]) smallest = r;
        if(smallest == i) return;
        std::swap(a[i], a[smallest]);
        i = smallest;
    }
}
void Heap::MaxHeapify(std::vector<int> &a, int i, int heapSize)
{
    while (true)
    {
        int largest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < heapSize && a[l] > a[largest])
            largest = l;
        if (r < heapSize && a[r] > a[largest])
            largest = r;
        if (largest == i)
            return;
        std::swap(a[largest], a[i]);
        i = largest;
    }
}

void Heap::MaxHeapifyRec(std::vector<int> &a, int i, int heapSize)
{
    int l = 2 * i + 1, r = 2 * i + 2;
    int largest = i;
    if (l < heapSize && a[l] > a[largest])
        largest = l;
    if (r < heapSize && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        std::swap(a[i], a[largest]);
        MaxHeapifyRec(a, largest, heapSize);
    }
}

void Heap::BuildHeap(std::vector<int> &a)
{
    int heapSize = static_cast<int>(a.size());
    for (int i = heapSize / 2 - 1; i >= 0; --i)
    {
        MinHeapify(a, i, heapSize);
    }
}

int main()
{
    std::vector<int> arr = {2, 1, 4, 5};
    Heap h;
    h.BuildHeap(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
}
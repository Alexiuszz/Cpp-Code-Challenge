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
    std::vector<int> h;
    void MaxHeapifyRec(std::vector<int> &a, int i, int heapSize);
    void MaxHeapify(std::vector<int> &a, int i, int heapSize);
    void BuildHeap(std::vector<int> &a);

public:
    Heap();
    Heap(std::vector<int> &h);

    int GetLeft(int i);
    int GetRight(int i);
};

Heap::Heap(std::vector<int> &h)
{
    BuildHeap(h);
}

int Heap::GetLeft(int i)
{
    return 2 * i + 1;
}
int Heap::GetRight(int i)
{
    return 2 * i + 2;
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
        MaxHeapify(a, i, heapSize);
    }
}

int main()
{
    std::vector<int> arr = {2, 1, 4, 5};
    Heap h(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
}
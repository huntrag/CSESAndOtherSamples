#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

class MaxHeap
{
    int *arr;
    int size;
    int capacity;

public:
    MaxHeap(int *a, int s, int c);
    MaxHeap(int c);
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }
    void MaxHeapify(int i);
    void insert(int val);
    int getTop();
    int extractTop();
    void replaceTop(int val);
    void heapBana();
    void HeapSort();
};

MaxHeap::MaxHeap(int *a, int s, int c)
{
    capacity = c;
    arr = new int[c];
    size = s;
    for (int i = 0; i < s; i++)
    {
        arr[i] = a[i];
    }
    heapBana();
}

MaxHeap::MaxHeap(int c)
{
    capacity = c;
    size = 0;
    arr = new int[c];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    MaxHeap heap(10);

    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    heap.insert(2);
    heap.HeapSort();
    cout << heap.getTop();
    heap.extractTop();
    cout << heap.getTop();

    return 0;
}

void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int mx = i;

    if (l < size && arr[mx] < arr[l])
        mx = l;
    if (r < size && arr[mx] < arr[r])
        mx = r;
    if (mx != i)
    {
        swap(arr[i], arr[mx]);
        MaxHeapify(mx);
    }
}

int MaxHeap::getTop()
{
    if (size > 0)
    {
        return arr[0];
    }
    return INT_MAX;
}

int MaxHeap::extractTop()
{
    if (size <= 0)
    {
        return INT_MAX;
    }
    int ret = arr[0];

    if (size > 1)
    {
        arr[0] = arr[size - 1];
        MaxHeapify(0);
    }
    size--;

    return ret;
}

void MaxHeap::heapBana()
{
    int iter = parent(size);
    while (iter >= 0)
    {
        MaxHeapify(iter);
        iter--;
    }
}

void MaxHeap::replaceTop(int val)
{
    if (size <= 0)
    {
        return;
    }
    else
    {
        arr[0] = val;
        MaxHeapify(0);
    }
}

void MaxHeap::insert(int val)
{
    if (size == capacity)
    {
        cout << "Heap is full\n";
        return;
    }
    size++;
    arr[size - 1] = val;
    heapBana();
}

void MaxHeap::HeapSort()
{
    int cur_size = size;
    int *prev_arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        prev_arr[i] = arr[i];
    }
    while (size >= 0)
    {
        int last = arr[size - 1];
        arr[size - 1] = getTop();
        size--;
        replaceTop(last);
    }
    for (int i = 0; i < cur_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < cur_size; i++)
    {
        arr[i] = prev_arr[i];
    }
    size = cur_size;
}
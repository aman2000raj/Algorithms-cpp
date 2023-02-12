#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr, int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\n";
}

void heapify(vector<int> &arr, int &n, int idx)
{
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != idx)
    {
        swap(arr[idx], arr[largest]);

        heapify(arr, n, largest);
    }
}

void build_heap(vector<int> &arr, int &n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapsort(vector<int> &arr, int &n)
{
    build_heap(arr, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
int main()
{
    int n = 15;
    vector<int> arr = {16, 14, 18, 10, 5, 9, 11, 3, 25, 1, 13, 7, 2, 19, 4};
    print(arr, n);
    heapsort(arr, n);
    print(arr, n);
    return 0;
}
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

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int pIdx = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr[i], arr[pIdx]);
            pIdx++;
        }
    }
    swap(arr[pIdx], arr[end]);
    return pIdx;
}

int randomPartition(vector<int> &arr, int start, int end)
{
    int pIdx = rand() % (end - start + 1) + start;
    swap(arr[pIdx], arr[end]);
    return partition(arr, start, end);
}

void quickSort(vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return;
    }
    int pIdx = randomPartition(arr, start, end);
    quickSort(arr, start, pIdx - 1);
    quickSort(arr, pIdx + 1, end);
}

int main()
{
    int n = 15;
    vector<int> arr = {16, 14, 18, 10, 5, 9, 11, 3, 25, 1, 13, 7, 2, 19, 4};
    cout << "Before Sort: ";
    print(arr, n);
    quickSort(arr, 0, n);
    cout << "After Sort:  ";
    print(arr, n);
    return 0;
}
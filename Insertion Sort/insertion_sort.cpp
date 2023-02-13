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
void fsort(vector<int> &arr, int &n)
{
    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int hole = i;
        while (hole > 0 && arr[hole - 1] > value)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
}
int main()
{
    int n = 15;
    vector<int> arr = {16, 14, 18, 10, 5, 9, 11, 3, 25, 1, 13, 7, 2, 19, 4};
    print(arr, n);
    fsort(arr, n);
    print(arr, n);
    return 0;
}
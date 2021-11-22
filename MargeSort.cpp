#include <bits/stdc++.h>
using namespace std;
int temp[100000];

void merging(int arr[],int l, int mid, int r)
{
    int low,up,k;
    low = l;
    up = mid + 1;

    for(k = low; low<=mid && up<=r; k++)
    {
        if(arr[low] < arr[up])
            temp[k] = arr[low++];
        else
            temp[k] = arr[up++];
    }
    while(low <= mid)
        temp[k++] = arr[up++];

    while(up <= r)
        temp[k++] = arr[up++];

    for(k = l; k<=r; k++)
        arr[k] = temp[k];

}
void MergeSort(int a[], int low, int up)
{
    if (up > low)
    {
        int mid = low + (up - low) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, up);
        merging(a, low, mid, up);
    }
}
void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int array[n+2];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    MergeSort(array, 0, n - 1);
    PrintArray(array, n);
}

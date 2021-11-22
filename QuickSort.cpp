#include <bits/stdc++.h>
using namespace std; 

int partition (int arr[], int low, int high) 
{ 
    int pivot= arr[low];
    int  start= low;
    int end=high;

    while (end>start)
    {
        while(pivot>=arr[start]){
            start++;
        }
        while (pivot<arr[end])
        {
            end--;
        }
        if(start<end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[low],arr[end]);
    return end;
    
    
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main(){
    int n;
    cout<<"Enter the number of element\n";
    cin>>n;
    cout<<"Enter array element\n";
    int  a[n+2];
    for (int  i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    quickSort(a,0,n-1);
    
    printArray(a,n);
}
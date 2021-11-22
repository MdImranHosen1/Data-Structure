#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    inputArray(a,n);
    insertionSort(a,n);
    printArray(a,n);
      
}
void inputArray(int a[],int n){
    if(n==1){cout<<a[0];}
    else{
         for(int i=0;i<n;i++){
             cin>>a[i];
         }
    }

}

void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int key= a[i],index=i-1;
        while (index>=0 && a[index]>key)
        {
            /* code */
            a[index+1]=a[index];
            index=index-1;
        }
        a[index+1]=key;
        
        
    }

}
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
         cout<<a[i]<<" ";
    }
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //swap every lower element to higher element
    for(int j=n-1;j>=0;j--){
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                int swap;
                swap=a[i];
                a[i]=a[i+1];
                a[i+1]=swap;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}

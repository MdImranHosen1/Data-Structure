#include<bits/stdc++.h>
using namespace std;
int main(){
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++){
        cin>>a[i];
     }
      // set lower one in the first index
    for(int j=0;j<n-1;j++){
        int x= a[j],y=j;
        for(int i=j+1;i<n;i++){
            if(x>a[i]){
                 x=a[i];
                 y=i;
            }
            if(i==n-1){
                 int swap;
                 swap=a[j];
                 a[j]=x;
                 a[y]=swap;
            }
        }
    }
    for(int i=0;i<n;i++){
         cout<<a[i]<<" ";
     }
}


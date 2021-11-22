#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter number"<<endl;
    int x,m=0,result=0;
    cin>>x;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            m=1,result=i+1;
            break;
        }
    }
    if(m==0){
        cout << "Element is not present in array";
    }
    else if(m==1){
        cout << "Element is present at index " << result;
    }
}
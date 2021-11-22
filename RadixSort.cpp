#include<bits/stdc++.h>
using namespace std;


void RadixSort(int a[],int n,int max)
{
    
    for (int i = 1; max/i>0 ; i*=10)
    {
        int output[n];
        int count[10]={0};
        for (int j = 0; j < n; j++)
        {
            count[(a[j]/i)%10]++;
        }
        for(int j=1;j<10;j++)
        {
            count[j]=count[j]+count[j-1];
        }
        for (int j = n-1; j>=0; j--)
        {
            output[count[(a[j]/i)%10]-1]=a[j];
            count[(a[j]/i)%10]--;
        }
        for(int j=0;j<n;j++){
            a[j]=output[j];
        }
        
        
        
    }
    
}
void print(int a[],int n ){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}
int main()
{
    int n;
    cin>>n;
    int a[n],max=0;
    //input system
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];    
        if(max<a[i]){
            max=a[i];
        }
    }
    RadixSort(a,n,max);
    print(a,n );
}
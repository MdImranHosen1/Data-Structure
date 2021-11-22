#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],b[n],max=0;
    //input system
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>a[i];    
        if(max<a[i]){
            max=a[i];
        }
    }
     //counting sort start 
    int count[max];
    for (int  i = 0; i <= max; i++)
    {
        count[i]=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for (int  i = 1; i <= max; i++)
    {
        count[i]+=count[i-1];
    }

    for (int  i = n-1; i>=0; i--)
    {
        b[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }
    //counting sort stop
    //printing
    for (int  i = 0; i < n; i++)
    {
        a[i]=b[i];
    }
    for (int  i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    
}
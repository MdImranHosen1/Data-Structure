#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)

const int Inf           = (int)2e9 + 5;
const ll  Lnf           = (ll)2e18 + 5;
const int N             = 5e5 + 5;
const int NN            = 1e6 + 5;
int segment[10000];

int preprocess(int input[], int n) {
	int segment_size = sqrt(n);

	for (int i = 0; i < n; i++) {
		segment[i/segment_size] += input[i];
	}
	return segment_size;
}
int query(int input[],int sz,int l,int r)
{
	int sum=0;
	for(int i=l;i<=r;)
	{
		if(i%sz==0 && i+sz-1<=r)
		{
			sum+=segment[i/sz];
			i+=sz;
		}
		else
		{
			sum+=input[i];
			i++;
		}
	}
	cout<<sum<<endl;
	
}
int solve()
{
	int n;
	cin >> n;
	int a[n+1];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int sz=preprocess(a,n);
	for (int i = 0; i <=sz; ++i)
	{
		cout <<segment[i] <<" ";
	}
	int l,r;
	cin>>l>>r;
	l--,r--;
	query(a,sz,l,r);

	return 0;
}

int main() {
	ll i, test = 1;
// cin>>test;
	for (i = 0; i < test; ++i)
	{
		solve();
	}
	return 0;
}



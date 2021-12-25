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
int n;
std::vector<int>a(N);
std::vector<int>bit(N);
int constractbit(int i)
{
	for (int bi = i;bi<=n ;bi+=(-bi&bi))
	{
		bit[bi]+=a[i];
	}
}
int sumbit(int i)
{
	int sum=0;
	for(int bi=i;bi>0;bi-=(bi&-bi))
	{
		sum+=bit[bi];
	}
	return sum;
}
int main(){
  cin>> n;
  for (int i = 1; i <= n; ++i)
  {
  	cin>>a[i];
  }
 
  for (int i = 1; i <= n; ++i)
  {
  	constractbit(i);
  }
  for (int i = 1; i < n+1; ++i)
  {
  	cout<<bit[i]<<" ";
  }
  int query;
  cout<<"Enter query number"<<endl;
  cin>>query;
  for (int i = 0; i < query; ++i)
  {
  	int r;
  	cin>>r;
  	int sum=sumbit(r);
  	cout<<sum<<endl;
  }
  return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define     Yes   printf("Yes\n")
#define     No    printf("No\n")
#define     YES   printf("YES\n")
#define     NO    printf("NO\n")
#define     Noo    printf("-1\n")
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)

#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s, char c) {vector<string>v; stringstream ss(s); string x; while (getline(ss, x, c))v.emplace_back(x); return move(v);} void err(vector<string>::iterator it) {}
template<typename T, typename... Args>void err(vector<string>::iterator it, T a, Args...args) {cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " "; err(++it, args...);}

const int lim = 1048576;
const int Inf           = (int)2e9 + 5;
const ll  Lnf           = (ll)2e18 + 5;
const int N             = 5e5 + 5;
const int NN            = 1e6 + 5;



int Set[N];
int size[N];


void make(int v)
{
	Set[v] = v;
	size[v] = 1;
}

int find(int v)
{
	if (Set[v] == v)
		return v;
	return Set[v] = find(Set[v]);
}
void Union(int l, int r)
{
	int u = find(l);
	int v = find(r);
	if (u != v)
	{
		if (size[v] >= size[u])
		{
			Set[v] = u;
			size[v] += size[u];
		}
		else
		{
			size[u] = v;
			size[u] += size[v];
		}
	}
}
int main()
{
	cout<<"Enter number of Set you want to make?\n";
	int sn;
	cin>>sn;
	cout<<"Enter single Set :\n";
	for (int i = 0; i < sn; ++i)
	{
		int v;
		cin>>v;
		make(v);

	}
	cout<<"How much time you want to Union:\n";
	int u;
	cin>>u;
	cout<<"Enter two defarent Set for union\n";
	for (int i = 0; i < u; ++i)
	{
		int x,y;
		cin>>x>>y;
		Union(x,y);
	}

}

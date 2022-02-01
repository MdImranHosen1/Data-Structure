#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define     YES   printf("YES\n")
#define     NO    printf("NO\n")
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

std::vector<int> parent;

int find(int en)
{
    if (parent[en] == -1)
    {
        return en;
    }
    else
    {
        return find(parent[en]);
    }
}

void unionBoth(int f,int t)
{
    int ff=find(f);
    int tt=find(t);

    parent[ff]=tt;

}
bool isCycle(std::vector<pair<int, int>>& edgelist)
{
    for (auto p : edgelist) 
    {
        int from = find(p.first);
        int to = find(p.second);

        if (from == to)
        {
            return true;
        }
        else
        {
            unionBoth(from,to);
        }
    }
}
int main()
{
    cout << "Enter vertex and edge number\n";
    int vertex, edge;
    cin >> vertex >> edge;

    parent.resize(vertex, -1);
    std::vector < pair<int, int>>edgelist;

    for (int i = 0; i < edge; ++i)
    {
        int from, to;
        cin >> from >> to;
        edgelist.push_back({from, to});
    }
    if (isCycle(edgelist))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}



//DFS
#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
vector<int> vv[N];
int visit[1000];
void dfs(int a)
{
    visit[a]=1;
    for(int i=0;i<vv[a].size();i++){
        if(!visit[vv[a][i]]){
            cout<<vv[a][i]<<" "; 
            dfs(vv[a][i]);
        }
    }
}

int main()
{
    int v, e;
    cout << "Enter vertex and edge number\n";
    cin >> v >> e;
    cout << "Enter the edge\n";
    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        vv[a].push_back(b);
        vv[b].push_back(a);
    }
    cout<<1<<" ";
    dfs(1);
}
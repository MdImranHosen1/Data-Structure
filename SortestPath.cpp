//Sortest Path
#include <bits/stdc++.h>
using namespace std;
bool visit[1000];
int level[1000];
int main()
{
    int n, i, j, k, m, u, v, x;
    memset(level, -1, sizeof(level));
    cout << "Enter number of node and edge: \n";
    cin >> n >> m;
    vector<int> g[n + 2];
    cout << "Enter the edges : \n";
    for (i = 0; i < m; i++)
    {
        
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    level[1] = 0;
    while (q.size())
    {
        u = q.front();
        q.pop();
        visit[u] = true;
        for (j = 0; j < g[u].size(); j++)
        {
            v = g[u][j];
            if (level[v] == -1)
            {
                level[v] = level[u] + 1;
            }
            if (!visit[v])
            {
                q.push(v);
                visit[v] = true;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        cout << "1 node from " << i << " node of shortest path :" << level[i] << endl;
    }
}
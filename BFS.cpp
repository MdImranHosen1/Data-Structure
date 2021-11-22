//bfs
#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5;
vector<int> g[N];
bool visit[N];
int main()
{
    int e, v;
    cout << "Enter the number of vertex and edge" << endl;
    cin >> v >> e;
    cout << "Enter the edge" << endl;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int p = q.front();
        if (!visit[p])
            cout << p << " ";
        q.pop();
        visit[p] = true;
        for (int i = 0; i < g[p].size(); i++)
        {
            int v = g[p][i];
            if (!visit[v])
            {
                q.push(v);
            }
        }
    }
    cout << endl;
    return 0;
}
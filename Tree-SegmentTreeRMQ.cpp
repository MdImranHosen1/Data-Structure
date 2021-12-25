#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define FOR(i, a, b) for (i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof a)
#define memn(a) memset(a, -1, sizeof a)

const int Inf = (int)2e9 + 5;
const ll Lnf = (ll)2e18 + 5;
const int N = 5e5 + 5;
const int NN = 1e6 + 5;

int tree[N];
vector<int> ar;
int mrq(int qstart, int qstop, int low, int high, int pos)
{
    if (qstart <= low && qstop >= high)
    {
        return tree[pos];
    }
    if (qstart > high || qstop < low || low > high)
    {
        return N;
    }
    int mid = (low + high) / 2;
    return min(mrq(qstart, qstop, low, mid, pos * 2 + 1), mrq(qstart, qstop, mid + 1, high, pos * 2 + 2));
}
int mrq(int n, int p, int q)
{
    return mrq(p, q, 0, n - 1, 0);
}
void showSegTree(int n)
{
    int h = (int)(ceil(log2(n)));
    int size = 2 * (int)pow(2, h) - 1;
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j < pow(2, i); j++)
        {
            cout << tree[int(pow(2, i) - 1 + j)] << " ";
        }
        cout << endl;
    }
}

int constSegTree(int low, int high, int pos)
{
    if (low == high)
    {
        return tree[pos] = ar[low];
    }
    int mid = (low + high) / 2;
    return tree[pos] = min(constSegTree(low, mid, pos * 2 + 1),
                           constSegTree(mid + 1, high, pos * 2 + 2));
}

void constSegTree(int n)
{
    constSegTree(0, n - 1, 0);
}

int main()
{
    int n;
    cin >> n;
    // 18 17 1 19 15 11 20
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        ar.pb(p);
    }
    constSegTree(n);
    showSegTree(n);
    int xx;
    cin >> xx;
    for (int i = 0; i < xx; i++)
    {

        cout << "Enter minimam range qurue p and q" << endl;
        int qstart, qstop;
        cin >> qstart >> qstop;
        cout << mrq(n, qstart-1, qstop-1);
    }

    return 0;
}


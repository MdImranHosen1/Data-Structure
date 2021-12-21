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
#define For(i, n) for (i = 0; i < n; i++)
#define mem(a) memset(a, 0, sizeof a)
#define memn(a) memset(a, -1, sizeof a)

const int Inf = (int)2e9 + 5;
const ll Lnf = (ll)2e18 + 5;
const int N = 5e5 + 5;
const int NN = 1e6 + 5;

vector<int> v;
int tree[N];
int lazy[N];
// update segment tree in range using lazy propagation
void updateSegmentTreeRangeLazy(int sr, int er, int dalta, int l, int h, int p)
{
    if (l > h)
        return;
    if (lazy[p] != 0)
    {
        tree[p] += lazy[p];
        if (l != h)
        {
            lazy[p * 2 + 1] = lazy[p];
            lazy[p * 2 + 2] = lazy[p];
        }
        lazy[p] = 0;
    }
    if (sr > h || er < l)
        return;

    if(sr<=l && er>=h)
    {
        tree[p]+=dalta;
        if(l!=h)
        { 
            lazy[2*p+1]=dalta;
            lazy[2*p+2]=dalta;
        }
        return;
    }
    int m = (l + h) / 2;

    updateSegmentTreeRangeLazy(sr, er, dalta, l, m, p * 2 + 1);
    updateSegmentTreeRangeLazy(sr, er, dalta, m + 1, h, p * 2 + 2);
    tree[p] = min(tree[2 * p + 1], tree[2 * p + 2]);
}
int rangeinMinimumQueryLazy(int ql, int qh, int l, int h, int p)
{
    if (l > h)
        return N;

    if (lazy[p] != 0)
    {
        tree[p] += lazy[p];
        if (l != h)
        {
            lazy[p * 2 + 1] = lazy[p];
            lazy[p * 2 + 2] = lazy[p];
        }
        lazy[p] = 0;
    }
    if(ql>h || qh<l)
    {
        return N;
    }
    if (ql <= l && qh >= h)
    {
        return tree[p];
    }
    int m = (l + h) / 2;
    return tree[p] = min(rangeinMinimumQueryLazy(ql, qh, l, m, p * 2 + 1),
                         rangeinMinimumQueryLazy(ql, qh, m + 1, h, p * 2 + 2));
}

int minimumRangeQ(int ql, int qh, int l, int h, int p)
{
    if (ql <= l && qh >= h)
    {
        return tree[p];
    }
    if (ql > h || qh < l || l > h)
    {
        return N;
    }
    int m = (l + h) / 2;
    return tree[p] = min(minimumRangeQ(ql, qh, l, m, p * 2 + 1), minimumRangeQ(ql, qh, m + 1, h, p * 2 + 2));
}

int segmentTree(int l, int h, int p)
{
    if (l == h)
    {
        return tree[p] = v[l];
    }
    int m = (l + h) / 2;
    return tree[p] = min(segmentTree(l, m, p * 2 + 1), segmentTree(m + 1, h, p * 2 + 2));
}
int main()
{
    int test = 1;
    ll i, j, n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    For(i, n)
    {
        int p;
        cin >> p;
        v.push_back(p);
    }
    segmentTree(0, n - 1, 0);

    cout << "enter the qurue range" << endl;
    cout << endl;
    int qf, ql;
    cin >> qf >> ql;
    cout << minimumRangeQ(qf - 1, ql - 1, 0, n - 1, 0)<<endl;;
    cout << "Enter range and value for update the array using lazy propagation" << endl;
    int p, q, v;
    cin >> p >> q >> v;
    updateSegmentTreeRangeLazy(p, q, v, 0, n - 1, 0);
    cout << "Enter range  qurue after propagation" << endl;
    cin>>p>>q;
    cout<<rangeinMinimumQueryLazy(p-1,q-1,0,n-1,0)<<endl;

    return 0;
}

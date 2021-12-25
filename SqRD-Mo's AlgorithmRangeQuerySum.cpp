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

int rootN;

struct Q
{
    int idx, l, r;
};

Q q[N];

bool campare(Q q1, Q q2)
{
    if (q1.l / rootN == q2.l / rootN)
    {
        return q1.r > q2.r;
    }
    return q1.l / rootN < q2.l / rootN;
}

int main()
{
    int n;
    cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    rootN = sqrtl(n);
    int queries;
    cin >> queries;

    for (int i = 0; i < queries; ++i)
    {
        int l, r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    sort(q, queries + q, campare);

    std::vector<int> ans(queries);
    int curr_l = 0, curr_r = -1, l, r;
    int curr_ans = 0;
    for (int i = 0; i < queries; ++i)
    {
        l = q[i].l;
        r = q[i].r;
        l--, r--;

        while (curr_r < r)
        {
            curr_r++;
            curr_ans += a[curr_r];
        }
        while (curr_l > l)
        {
            curr_l--;
            curr_ans += a[curr_l];
        }
        while (curr_l < l)
        {
            curr_ans -= a[curr_l];
            curr_l++;
        }
        while (curr_r > r)
        {
            curr_ans -= a[curr_r];
            curr_r--;
        }
        ans[q[i].idx] = curr_ans;
    }
    for (int i = 0; i < queries; ++i)
    {
        cout << ans[i] << endl;
    }
}




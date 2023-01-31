#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<ll> vl;
typedef     pair<int, int>pi;
typedef     pair<ll, ll>pl;
typedef     priority_queue<int> pqi;
typedef     priority_queue<ll> pql;
typedef     vector<pair<int, int> > vpi;
typedef     vector<pair<ll, ll> > vpl;
typedef     map<ll, ll> mpl;
typedef     multiset<ll>msl;
typedef     multiset<ll>msi;

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

//Int Input Fast Start
template <typename T> inline void in(T &n) {
      n = 0; int f = 1; register int ch = getchar();
      for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
      for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
      n = n * f;
}
template <typename T, typename TT> inline void in(T &n, TT &m) { in(n); in(m); }
template <typename T, typename TT, typename TTT> inline void in(T &n, TT &m, TTT &l) { in(n, m); in(l); }
//Int Input Fast End

#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s, char c) {vector<string>v; stringstream ss(s); string x; while (getline(ss, x, c))v.emplace_back(x); return move(v);} void err(vector<string>::iterator it) {}
template<typename T, typename... Args>void err(vector<string>::iterator it, T a, Args...args) {cout << it->substr((*it)[0] == ' ', it->length()) << " = " << a << " "; err(++it, args...);}

#define     int  long long int
#define     Yes   printf("Yes\n")
#define     No    printf("No\n")
#define     YES   printf("YES\n")
#define     NO    printf("NO\n")
#define     Noo    printf("-1\n")
#define     fo(i,p,n) for (ll i = p; i < n; i++)
#define     pt(x)    cout<<x<<" ";
#define     ptt(x,y)  cout<<x<<" "<<y<<endl;
#define     ptv(x)fo(i,0,x.size()) pt(x[i]);
#define     reads(s)  string s;cin>>s;
#define     readv(x, n) vl x(n); fo(i,0,n) in(x[i]);
#define     readv1(x, n) vl x(n+1); fo(i,1,n+1) in(x[i]);
#define     ff   first
#define     ss   second
#define     el   printf("\n");
#define     pb  push_back
#define     all(x)      x.begin() , x.end()
#define     srt(x)     sort(x.begin() , x.end())
#define     rsrt(x)     sort(x.rbegin() , x.rend())
#define     bitcount(x)  (int)__builtin_popcount(x)
#define     fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     sz(x)  (int)x.size()
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)

const int   lim = 1048576;
const int   Inf           = (int)2e9 + 5;
const ll    Lnf           = (ll)2e18 + 5;
const int   N             = 2e5 + 20;
const int   NN            = 1e6 + 5;
ll mod = 1e9 + 7;

ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
//****************************Template Ends*******************************//
int n, m, k;

int getMin(vector<vector<int>>&sparse, int i, int j)
{
      if (i == j)
      {
            return sparse[i][0];
      }
      ll dif = j - i + 1;
      ll mn = log(dif) + 1;
      return min(sparse[i][mn], getMin(sparse, i + mn, j));

}



void solve()
{
      ll x = 0, y = 0, z = 0, i, j, sum = 0;
      cin >> n;
      readv(v, n);

      vector<vector<int>>sparse(n + 2, vector<int>(log(n) + 2, 0));
      for (i = 0; i < n; i++)
      {
            sparse[i][0] = v[i];
      }
      for (i = 1; pow(2, i) <= n; i++)
      {
            for (j = 0; j + pow(2, i) - 1 < n; j++)
            {

                  sparse[j][i] = min(sparse[j][i - 1], sparse[j + (1ll << (i - 1))][i - 1]);
            }
      }
      for (i = 0; i < n; i++)
      {
            for (auto j : sparse[i])
            {
                  cout << j << " ";
            }
            el;
      }
      while (1)
      {
            in(x, y);
            cout << getMin(sparse, x-1, y-1) << endl;
      }


      return;
}

int32_t main() {

      int i, test = 1;
      //in(test);
      for (i = 1; i <= test; ++i)
      {
            //error(i);
            //printf("Case %d: ",i);
            solve();
      }
      return 0;
}

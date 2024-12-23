 // Obliviate, Mischief Managed!
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define int long long
#define ar array
#define ll long long
#define FOR(n) for (int i = 0; i < n; ++i)
#define FOR1(n) for (int ii = 0; ii < n; ++ii)
#define pb(n) push_back(n)
#define rep(i,a,b) for(int i = a;i<b;++i)
#define all(x) x.begin(), x.end()
#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));
 
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#ifndef ONLINE_JUDGE
#define debug(x) cout<<#x<<" is "<<x<<endl;
#define debugv(v) cout<<#v<< " is :-"<<endl;for(auto it: (v))cout<<it<<" ";cout<<endl;
#define debug2d(v) cout<<#v<< " is :-"<<endl;cn=0;for(auto it: (v)) {cout<<cn<<" => ";cn++; for(auto j:it) cout<<j<<" ";cout<<endl;}
#define pline(x) cout<<x<<" line is reached"<<endl;
#define debugvp(v) cout<<#v<<" is :-"<<endl;for(auto i: v){cout<<"("<<i.ff<<","<<i.ss<<")"<<" ";}cout<<endl;
#define prline cout<<endl;
#define debugpair(p) cout<<#p<<" is ("<<p.ff<<","<<p.ss<<")"<<endl;
#define print(s) cout<<s<<endl;
#else
#define debug(x)
#define debugv(v)
#define debug2d(v)
#define pline(x)
#define debugvp(v)
#define prline
#define debugpair(p)
#define print(s) 
#endif

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}
int fastpow(int a, int b)
{
    int res = 1;
    while(b > 0)
    {
        if((b&1))
            res *= a;
        a *= a;
        b = b >> 1;
    }
    return res;
}
int grdways(int n, int m)
{
    if(n == 1 || m == 1)
        return 1;
    return grdways(n-1,m) + grdways(n, m-1);
}
//Operator Overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v)
{
  for (auto &it : v)
    cin >> it;
  return istream;
} 

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }

template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }

// For Kickstart : cout << "Case #" << tt <<": " << ans << "\n";

void init()
{
  #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
  #endif
}
ll nCr(int n, int r){
    ll p = 1, k = 1;
    if (n - r < r) r = n - r;
    if(r == 0) return 1;
    while (r) {
        p *= n; k *= r;
        ll m = __gcd(p, k);
        p /= m; k /= m;
        n--; r--;
    }
    return p;
}
int powr(int a, int b)
{
    int res = 1;
    while(b)
    {
        if((b&1))
            res = res * a;
        a = a * a;
        b = b >> 1;
    }
    return res;
}
int mult(int a, int b, int c)
{
    int res = 0;
    while(b)
    {
        if(b&1)
            res = res + a;
        res = res % MOD;
        a = 2 * a;
        a %= MOD;
        b = b >> 1;
    }
    return res;
}
int help_find_sequence(vector<string>& str, string xmas)
{
    int m = str[0].size(), n = str.size(), ans = 0;
    // vertical
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n - 3; j++)
        {
            if(str[j][i] == xmas[0] && str[j + 1][i] == xmas[1] && str[j + 2][i] == xmas[2] && str[j + 3][i] == xmas[3])
                ans++;
            if(str[j][i] == xmas[3] && str[j + 1][i] == xmas[2] && str[j + 2][i] == xmas[1] && str[j + 3][i] == xmas[0])
                ans++;
        }
    }
    // horizontal
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m - 3; j++)
        {
            if(str[i][j] == xmas[0] && str[i][j + 1] == xmas[1] && str[i][j + 2] == xmas[2] && str[i][j + 3] == xmas[3])
                ans++;
            if(str[i][j] == xmas[3] && str[i][j + 1] == xmas[2] && str[i][j + 2] == xmas[1] && str[i][j + 3] == xmas[0])
                ans++;
        }
    }
    // primary diagonal
    for(int i = 0; i < n; i++)
    {
        int ii = 0, jj = i;
        while((ii + 3) < n && (jj + 3) < m)
        {
            if(str[ii][jj] == xmas[0] && str[ii + 1][jj + 1] == xmas[1] && str[ii + 2][jj + 2] == xmas[2] && str[ii + 3][jj + 3] == xmas[3])
                ans++;
            if(str[ii][jj] == xmas[3] && str[ii + 1][jj + 1] == xmas[2] && str[ii + 2][jj + 2] == xmas[1] && str[ii + 3][jj + 3] == xmas[0])
                ans++;
            ii++, jj++;
        }
        if(i != 0)
        {
            ii = i, jj = 0;
            while((ii + 3) < n && (jj + 3) < m)
            {
                if(str[ii][jj] == xmas[0] && str[ii + 1][jj + 1] == xmas[1] && str[ii + 2][jj + 2] == xmas[2] && str[ii + 3][jj + 3] == xmas[3])
                    ans++;
                if(str[ii][jj] == xmas[3] && str[ii + 1][jj + 1] == xmas[2] && str[ii + 2][jj + 2] == xmas[1] && str[ii + 3][jj + 3] == xmas[0])
                    ans++;
                ii++, jj++;
            }
        }
    }
    // secondary diagonal
    for(int i = n - 1; ~i; i--)
    {
        int ii = 0, jj = i;
        while((ii + 3) < n && (jj - 3) >= 0)
        {
            if(str[ii][jj] == xmas[0] && str[ii + 1][jj - 1] == xmas[1] && str[ii + 2][jj - 2] == xmas[2] && str[ii + 3][jj - 3] == xmas[3])
                ans++;
            if(str[ii][jj] == xmas[3] && str[ii + 1][jj - 1] == xmas[2] && str[ii + 2][jj - 2] == xmas[1] && str[ii + 3][jj - 3] == xmas[0])
                ans++;
            ii++, jj--;
        }
        if(i != n - 1)
        {
            ii = (n - 1 - i), jj = (n - 1);
            while((ii + 3) < n && (jj - 3) >= 0)
            {
                if(str[ii][jj] == xmas[0] && str[ii + 1][jj - 1] == xmas[1] && str[ii + 2][jj - 2] == xmas[2] && str[ii + 3][jj - 3] == xmas[3])
                    ans++;
                if(str[ii][jj] == xmas[3] && str[ii + 1][jj - 1] == xmas[2] && str[ii + 2][jj - 2] == xmas[1] && str[ii + 3][jj - 3] == xmas[0])
                    ans++;
                ii++, jj--;
            }
        }
    }
    return ans;
}
void solve()
{  
    int n = 140;
    vector<string> str;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        string res = "";
        cin >> res;
        str.push_back(res);
    }
    ans += help_find_sequence(str, "XMAS");
    cout << ans;
}
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   init();
   clock_t tt = clock();
   int t=1;
    // cin>>t;
//   int i = 1;
   while(t--)
   {
      solve();
   }
   cerr << "RunTime: " << ((double)(clock() - tt) / CLOCKS_PER_SEC);
   return 0;
}

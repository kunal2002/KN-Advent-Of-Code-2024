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
int evaluateLeftToRight(vector<long long>& numbers, vector<char>& operators) 
{
    long long result = numbers[1];
    for (size_t i = 0; i < operators.size(); i++) 
    {
        if (operators[i] == '+')
            result += numbers[i + 2];
        else if (operators[i] == '*')
            result *= numbers[i + 2];
        else if (operators[i] == '|')
        {
            string temp = to_string(result);
            temp += to_string(numbers[i + 2]);
            result = stoll(temp);
        }
    }
    return result;
}

// Function to recursively try all operator combinations
bool solveEquation(long long target, vector<long long>& numbers, vector<char>& operators, size_t pos) 
{
    if (pos == numbers.size() - 1) 
        return evaluateLeftToRight(numbers, operators) == target;

    operators[pos - 1] = '+';
    if (solveEquation(target, numbers, operators, pos + 1))
        return true;

    operators[pos - 1] = '*';
    if (solveEquation(target, numbers, operators, pos + 1))
        return true;

    operators[pos - 1] = '|';
    if (solveEquation(target, numbers, operators, pos + 1))
        return true;

    return false;
}

bool rec(long long target, vector<long long>& numbers) 
{
    if (numbers.size() == 1) 
        return false;
    vector<char> operators(numbers.size() - 2);
    return solveEquation(target, numbers, operators, 1);
}
void solve()
{  
    int n = 850;
    vector<vector<long long>> eq(n);
    rep(i, 0, n)
    {
        string str = "";
        getline(cin, str);
        str.push_back(' ');
        int j = 0;
        string t = "";
        while(str[j] != ':')
            t += str[j++];
        j += 2;
        eq[i].push_back(stoll(t));
        while(j < str.size())
        {
            t = "";
            while(str[j] != ' ')
                t += str[j++];
            j++;
            eq[i].push_back(stoll(t));
        }
    }
    long long sum = 0;
    for(auto line : eq)
    {
        if(rec(line[0], line))
            sum += line[0];
    }
    cout << sum;
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

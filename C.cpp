//* Jai shree Ram
#include <bits/stdc++.h>  

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lld                                 long double
#define ll                                  long long
#define FOR(i,a,b)                          for(int i=(a);i<(b);i++)
#define vi                                  vector<int>
#define vll                                 vector<ll>
#define all(a)                              (a).begin(),(a).end()
#define sz(a)                               (int)a.size()
#define pb                                  push_back
#define ppb                                 pop_back
#define pf                                  push_front
#define fr                                  first
#define sc                                  second
#define uniq(v)                             (v).erase(unique(all(v)),(v).end())
using namespace std;
// using namespace __gnu_pbds;

// template<typename T>
// using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// //member functions :
// //1. order_of_key(k) : number of elements strictly lesser than k
// //2. find_by_order(k) : k-th element in the set

// void _print(int x) {cerr << x;}void __print(long x) {cerr << x;}void __print(long long x) {cerr << x;}void __print(unsigned x) {cerr << x;}void __print(unsigned long x) {cerr << x;}void __print(unsigned long long x) {cerr << x;}void __print(float x) {cerr << x;}void __print(double x) {cerr << x;}void __print(long double x) {cerr << x;}void __print(char x) {cerr << '\'' << x << '\'';}void __print(const char *x) {cerr << '\"' << x << '\"';}void __print(const string &x) {cerr << '\"' << x << '\"';}void __print(bool x) {cerr << (x ? "true" : "false");}template<typename T, typename V>void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}void _print() {cerr << "]\n";}template <typename T, typename... V>void _print(T t, V... v) {_print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
// #ifndef ONLINE_JUDGE
// #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
// #else
// #define debug(x...)
// #endif

// template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
// template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
// // __builtin_popcountll(x);
// // __builtin_clz(x) // Count Leading zeros
// // __builtin_ctz(x) // Trailing zeros
// const int MM = 998244353;
// const int mod = 1e9 + 7;
// const int INF = 1e9 + 5;
// const int N = 1e5 + 5;

/* Common Mistakes By Me
  * make sure to read the bottom part of question
  * special cases (n=1?)
  * In Game Theory Check your solution and consider all the solutions
  * Always initialise value to the declare array in local scope
  * don't use debugs in interactive problems
  * Always Reset vis,adj array upto n+1 otherwise can cause TLE
*/

void solve() 
{
    int n,k;
    srand(time(0));
    k = 1 + (rand())%(int)3e5;
    n = k + (rand())%(int)3e5;
    #include <iostream>

    cout << n << " " << k << endl;
    vll a(n);
    FOR(i,0,n) {
        a[i] = 1 + (rand()) % (int)1e9;
        cout << a[i] << " ";
    }
    cout << endl;
    map<ll,ll> mpp;
    int i = 0,j = 0;
    while(j < k) {
        mpp[a[j]]++;
        j++;
    }
    int ans = sz(mpp);
    while(j < n) {
        mpp[a[i]]--;
        if(mpp[a[i]] == 0) {
            mpp.erase(a[i]);
        }
        mpp[a[j]]++;
        i++,j++;
        ans = max(ans,sz(mpp));
    }
    cout << ans << '\n';
}

signed main()
{
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
}
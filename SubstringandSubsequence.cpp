

/*------------------Instant success builds ego, long term success builds character.---------------*/

#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define maxi 1e7 + 10;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

/*void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}*/
// C++ function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x % m + m) % m;
}

// Function to compute a/b under modulo m
void modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1)
        cout << "Division not defined";
    else
        cout << "Result of division is " << (inv * a) % m;
}

// C function for extended Euclidean Algorithm (used to
// find modular inverse.
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// to find (a ^ b) with modulo m
int power(int a, int b, int m)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ((a % m) * (ans % m)) % m;
            b--;
        }
        else
        {
            a = ((a % m) * (a % m)) % m;
            b >>= 1;
        }
    }
    return ans;
}

// to hash a string
int h(string &s)
{
    int val = 0;

    for (int i = 0; i < s.length(); i++)
    {
        val = (val * 31 + (s[i] - 'a' + 1)) % MOD;
    }

    return val;
}
// int f(string &first, int i, string &second, int j, vector<vector<int>> &dp){
//     if(i>=first.length() || j >= second.length()) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
    
//     if(first[i] == second[j]) return dp[i][j] = max(1 + f(first, i+1, second, j+1, dp), max(f(first, i+1, second, j, dp), f(first, i, second, j+1, dp)));
//     return dp[i][j] = max(f(first, i+1, second, j, dp), f(first, i, second, j+1, dp));
// }

int f(int i, int lastIndex, map<char, set<int>> &ind, string &b){
    if(i>=b.length()) return 0;
    
    auto ptr = ind[b[i]].upper_bound(lastIndex), lastPtr = ind[b[i]].end();
    
    if(ptr != lastPtr) return 1 + f(i+1, *ptr, ind, b);
    
    return 0;
}
int32_t main()
{
    fastio();
#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    cin >> t;

    while (t--)
    {
        string a, b;
        cin >> a >> b;
        
        map<char, set<int>> ind;
        int alen = a.length(), blen = b.length();
        for(int i = 0;i<alen;i++){
            ind[a[i]].insert(i);
        }
        int maxC = 0;
        for(int i = 0;i<blen;i++){
            maxC = max(f(i, -1, ind,b), maxC);
        }
        
        cout << alen + blen - maxC << endl;
    }
}
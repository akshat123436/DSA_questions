#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
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
#define maxi (int)(1e7 + 10)
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

// void _print(ll t) {cerr << t;}
////void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//---------------------------------------------------------------------------------------------------------------------------------------

bool cmp(int a, int b)
{
    return a < b;
}
bool accumulator(int a, int b)
{
    return a + b;
}
// Function to find the value of
// P * Q^-1 mod 998244353
long long calculate(long long p, long long q)
{
    long long mod = 998244353, expo;
    expo = mod - 2;
    // Loop to find the value
    // until the expo is not zero
    while (expo)
    {
        // Multiply p with q
        // if expo is odd
        if (expo & 1)
        {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
        // Reduce the value of
        // expo by 2
        expo >>= 1;
    }
    return p;
}

void dfs(vector<int> tree[], int node, int &ans, bool isVisited[], int val[], int n)
{
    if (!isVisited[node])
    {
        isVisited[node] = true;
        bool adder = false;
        if (tree[node].size())
        {
            val[node] = 1;
            if (tree[node].size() > 1)
            {
                adder = true;
            }
        }
        for (auto a : tree[node])
        {
            if(!adder){
                
            }
            dfs(tree, a, ans, isVisited, val, n);
            if (adder)
            {
                val[node] += val[a];
            }
            else
            {
                if (val[a])
                {
                    val[node] += val[a] - 1;
                }
            }
        }
        if (val[node] > ans)
            ans = val[node];
    }
}

int32_t main()
{

    fastio();

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    // cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> tree[n + 1];
        bool isVisited[n + 1];

        for (int i = 0; i <= n; i++)
        {
            isVisited[i] = false;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int e1, e2;
            cin >> e1 >> e2;
            tree[e1].push_back(e2);
            // tree[e2].push_back(e1);
        }

        int ans = INT_MIN;

        int val[n + 1];

        for (int i = 0; i <= n; i++)
        {
            val[i] = 0;
        }

        dfs(tree, 1, ans, isVisited, val, n);

        cout << ans << endl;
    }
}
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
// #define int long long

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

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

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

long long int minimumCost(int N, int r[], int g[], int b[], int index, vector<vector<int>> &dp, string leftColour)
{
    debug(index);
    debug(dp);
    debug(leftColour);
    if (leftColour == "green")
    {
        if (dp[1][index] != -1)
            return dp[1][index];
    }
    else if (leftColour == "blue")
    {

        if (dp[2][index] != -1)
            return dp[2][index];
    }
    else if (leftColour == "red")
    {
        if (dp[0][index] != -1)
            return dp[0][index];
    }
    if (index == N - 1)
    {
        if (leftColour == "green")
        {
            return dp[1][index] = min(r[index], b[index]);
        }
        else if (leftColour == "blue")
        {

            return dp[2][index] = min(r[index], g[index]);
        }
        else if (leftColour == "red")
        {
            return dp[0][index] = (g[index], b[index]);
        }
        else
            return dp[0][index] = min(g[index], min(b[index], r[index]));
    }
    cout << leftColour << endl;
    if (leftColour == "unColoured")
    {
        long long int rr = minimumCost(N, r, g, b, index + 1, dp, "red") + r[index];
        long long int bb = minimumCost(N, r, g, b, index + 1, dp, "blue") + b[index];
        long long int gg = minimumCost(N, r, g, b, index + 1, dp, "green") + g[index];
        return dp[0][index] = min(rr, min(bb, gg));
    }

    if (leftColour == "green")
    {
        return dp[1][index] = min(minimumCost(N, r, g, b, index + 1, dp, "red") + r[index], minimumCost(N, r, g, b, index + 1, dp, "blue") + b[index]);
    }
    else if (leftColour == "blue")
    {

        return dp[2][index] = min(minimumCost(N, r, g, b, index + 1, dp, "red") + r[index], minimumCost(N, r, g, b, index + 1, dp, "green") + g[index]);
    }
    else
    {
        return dp[0][index] = min(minimumCost(N, r, g, b, index + 1, dp, "green") + g[index], minimumCost(N, r, g, b, index + 1, dp, "blue") + b[index]);
    }
}

long long int distinctColoring(int N, int r[], int g[], int b[])
{
    vector<vector<int>> dp(3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i].push_back(-1);
        }
    }
    int index = 0;
    return minimumCost(N, r, g, b, index, dp, "unColoured");
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
        int N = 3;
        int r[3] = {2, 1, 3};
        int g[3] = {3, 2, 1};
        int b[3] = {1, 3, 2};

        cout << distinctColoring(N, r, g, b) << endl;
    }
}
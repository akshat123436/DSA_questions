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

bool recursor(int index, vector<int> &arr, vector<vector<int>> &dp, int sum, int t, int f)
{
    // cout << index << " "
    //      << " " << sum << " " << t << " " << f << endl;
    if (sum < 0)
        return f;
    if (index < 0)
    {
        if (sum == 0)
            return t;
        else
            return f;
    }
    if (dp[index][sum] == t || dp[index][sum] == f)
        return dp[index][sum];
    int pick = -1;
    if (arr[index] <= sum)
        pick = recursor(index - 1, arr, dp, sum - arr[index], t, f);
    int notPick = recursor(index - 1, arr, dp, sum, t, f);
    if (pick == t || notPick == t)
        return dp[index][sum] = t;
    else
        return dp[index][sum] = f;
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
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        int maxxx = INT_MIN;
        int oneCount = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxxx = max(arr[i], maxxx);
            if (arr[i] == 1)
                oneCount++;
        }
        sort(arr.begin(), arr.end());
        vector<vector<int>> dp(n, vector<int>(maxxx + 1, -1));
        bool possible = true;
        if (n == 1 && arr[0] != 1)
            possible = false;
        if (n >= 2 && oneCount < 2)
            possible = false;
        int t = 200002, f = 200003;
        for (int i = n - 2; i > 0; i--)
        {
            // cout << recursor(i, arr, dp, arr[i + 1], t, f) << endl;
            if (recursor(i, arr, dp, arr[i + 1], t, f) != t)
            {
                possible = false;
                break;
            }
            t += 2;
            f += 2;
            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j <= maxxx; j++)
            //     {
            //         cout << dp[i][j] << " ";
            //     }
            //     cout << endl;
            // }
        }

        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
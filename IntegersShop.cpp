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

void _print(ll t)
{
    cerr << t;
}
//void _print(int t) {cerr << t;}
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

        vector<int> left(n), right(n), cost(n);

        for (int i = 0; i < n; i++)
        {
            cin >> left[i] >> right[i] >> cost[i];
        }

        int leftt = INT_MAX, rightt = INT_MIN, righti, lefti, total = INT_MAX, left_cost = INT_MAX, right_cost = INT_MAX;
        int min_left = INT_MAX, min_right = INT_MAX;
        int left_min, right_min;
        for (int i = 0; i < n; i++)
        {
            debug(n);
            bool isLeft = false, isRight = false;
            if (left[i] < leftt)
            {
                leftt = left[i];
                left_cost = cost[i];
                isLeft = true;
                lefti = i;
                min_left = cost[i];
                left_min = i;
            }
            else if (left[i] == leftt)
            {
                isLeft = true;
                if (cost[i] < min_left)
                {
                    min_left = cost[i];
                    left_min = i;
                }
            }

            if (right[i] > rightt)
            {
                rightt = right[i];
                right_cost = cost[i];
                isRight = true;
                righti = i;
                min_right = cost[i];
                right_min = i;
            }
            else if (right[i] == rightt)
            {
                isRight = true;
                if (cost[i] < min_right)
                {
                    min_right = cost[i];
                    right_min = i;
                }
            }
            if (lefti != righti)
                total = left_cost + right_cost;
            else
                total = left_cost;
            if (isLeft && isRight)
            {
                int vall = cost[i];
                if (vall <= total)
                {
                    leftt = left[i];
                    rightt = right[i];
                    lefti = i;
                    righti = i;
                    total = vall;
                    left_cost = cost[i];
                    right_cost = cost[i];
                }
            }
            else if (isLeft || isRight)
            {
                if (isLeft)
                {
                    int val = cost[i] + min_right;
                    debug(val);
                    debug(total);
                    if (val < total)
                    {
                        leftt = left[i];
                        lefti = i;
                        left_cost = cost[i];
                        total = val;
                        right_cost = min_right;
                        righti = right_min;
                    }
                }
                else
                {
                    int val = cost[i] + min_left;
                    if (val < total)
                    {
                        rightt = right[i];
                        righti = i;
                        right_cost = cost[i];
                        total = val;
                        left_cost = min_left;
                        lefti = left_min;
                    }
                }
            }
            cout << total << endl;
            int l = isLeft;
            int r = isRight;
            debug(lefti);
            debug(righti);
            debug(l);
            debug(r);
            debug(leftt);
            debug(rightt);
            debug(left_cost);
            debug(right_cost);
            debug(total);
        }
    }
}
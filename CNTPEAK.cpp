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
        int arr[n];
        int ans = 0;
        int prevz = 0;
        int prevzp = 0;
        int prevzn = 0;
        for (int i = 0; i < 3; i++)
        {
            if (n >= 1)
                arr[0] = i;
            else
                i = 2;
            for (int j = 0; j < 3; j++)
            {
                if (n >= 2)
                    arr[1] = j;
                else
                    j = 2;
                for (int k = 0; k < 3; k++)
                {

                    if (n >= 3)
                        arr[2] = k;
                    else
                        k = 2;
                    // for (int t = 0; t < 3; ++t)
                    // {
                    //     debug(t);
                    //     debug(arr[t]);
                    // }
                    for (int l = 0; l < 3; l++)
                    {
                        if (n >= 4)
                            arr[3] = l;
                        else
                            l = 2;
                        for (int s = 0; s < 3; s++)
                        {
                            if (n >= 5)
                                arr[4] = s;
                            else
                                s = 2;
                            for (int m = 0; m < 3; m++)
                            {
                                if (n >= 6)
                                    arr[5] = m;
                                else
                                    m = 2;
                                for (int b = 0; b < 3; b++)
                                {
                                    if (n >= 7)
                                        arr[6] = b;
                                    else
                                        b = 2;
                                    for (int o = 0; o < 3; o++)
                                    {
                                        if (n >= 8)
                                            arr[7] = o;
                                        else
                                            o = 2;
                                        for (int p = 0; p < 3; p++)
                                        {
                                            if (n >= 9)
                                                arr[8] = p;
                                            else
                                                p = 2;
                                            for (int q = 0; q < 3; q++)
                                            {

                                                if (n >= 10)
                                                    arr[9] = q;
                                                // cout << "q" << n;
                                                else
                                                    q = 2;
                                                for (int z = 1; z < n - 1; z++)
                                                {
                                                    // cout << "askhat" << endl;

                                                    // if (ans == 0)
                                                    // {

                                                        if ((arr[z] > arr[z + 1] && arr[z] > arr[z - 1]) || (arr[z] < arr[z + 1] && arr[z] < arr[z - 1]))
                                                        {
                                                            // cout << arr[z] << " " << arr[z + 1] << " " << arr[z - 1] << endl;
                                                            // cout << "true" << endl;
                                                            ans++;
                                                        }
                                                    // }
                                                    // else if (!(prevz == arr[z] && prevzp == arr[z + 1] && prevzn == arr[z - 1]))
                                                    // {
                                                    //     if ((arr[z] > arr[z + 1] && arr[z] > arr[z - 1]) || (arr[z] < arr[z + 1] && arr[z] < arr[z - 1]))
                                                    //     {
                                                    //         cout << arr[z] << " " << arr[z + 1] << " " << arr[z - 1] << endl;
                                                    //         cout << "true" << endl;
                                                    //         ans++;
                                                    //     }
                                                    // }
                                                    // prevz = arr[z];
                                                    // prevzp = arr[z + 1];
                                                    // prevzn = arr[z - 1];
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
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

int min_(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}

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

bool checker(int arr[], int num, int size)
{
    int aux[size];

    for (int i = 0; i < size; i++)
    {
        aux[i] = arr[i];
    }
    int min = INT_MAX;
    for (int i = size - 1; i > 1; i--)
    {
        if (aux[i] - num >= 3)
        {
            int val = aux[i] - num;
            int usable = min_(arr[i], val);
            val = usable;
            int d = val / 3;

            aux[i] -= 3 * d;
            aux[i - 1] += d;
            aux[i - 2] += 2 * d;
        }

        // if(aux[i] < min) min = aux[i];
    }
    for (int i = 0; i < size; i++)
    {
        // cout << aux[i] << " " ;
        if (aux[i] < min)
            min = aux[i];
    }
    // cout << endl;
    if (min < num)
        return false;
    return true;
}

int searcher(int arr[], int min, int max, int size)
{
    // cout << "akshat" << endl;
    int mid = (max + min) / 2;
    // cout << "mid " << mid << endl;
    while (max - min > 2)
    {
        mid = (min + max) / 2;
        // cout << "mid " << mid << endl;
        if (checker(arr, mid, size))
        {
            min = mid;
            // cout << " yeahhh " << mid << endl;
        }
        else
            max = mid - 1;
    }
    if (checker(arr, max, size))
        return max;
    return min;
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
        int min = INT_MAX;
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] < min)
            {
                min = arr[i];
            }
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        int ans = searcher(arr, min, max, n);
        if(checker(arr, ans+1, n)) ans+=1;
        cout << ans << endl;
    }
}

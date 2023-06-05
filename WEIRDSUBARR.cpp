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
// void _print(int t) {cerr << t;}
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

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;

        vector<int> indices;

        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                indices.push_back(i);
            }
        }
        // ans -= indices.size();
        vector<int> distances;
        int t = -1;
        for (auto a : indices)
        {
            if (t == -1)
                t = a;
            else{
                distances.push_back(a - t);
                t=a;
            }
            
        }
        // distances.push_back(n - indices[indices.size() - 1] - 1);
        int p = indices.size();
        debug(indices);
        debug(ans);
        debug(distances);
        sort(distances.begin(), distances.end());
        // for (int i = 4; i <= n; i++)
        // {
        //     int lessthan = 0;

        //     if (distances.size())
        //     {

        //             auto check = lower_bound(distances.begin(), distances.end(), i - 1);

        //             if (check != distances.end())
        //             {
        //                 // debug(i);

        //                 int t = distances.size() - (check - distances.begin());

        //                 // lessthan += t;
        //                 for(int j = (check - distances.begin());j<distances.size();j++){
        //                     lessthan += distances[j]-i+1;
        //                 }
        //             }

        //             ans += lessthan;

        //     }
        //     if (indices.size())
        //     {
        //         if (indices[0] >= i - 1)
        //             ans++;
        //         if (n - indices[indices.size() - 1] >= i)
        //             ans++;
        //     }
        //     else{
        //         ans += n-i+1;
        //     }
        //     debug(i);
        //     debug(lessthan);
        //     debug(ans);
        // }
        int k = 0;
        for (auto a : distances)
        {
            a++;
            ans += (a * (a + 1)) / 2;
            if(k) ans--;
            k++;
        }
        if(indices.size()==1){
            ans += ((indices[0]+1) * (indices[0] + 2)) / 2;
            ans += ((n - indices[indices.size() - 1]) * (n - indices[indices.size() - 1] + 1)) / 2;
            ans--;
        }
        else if (indices.size())
        {
            ans += ((indices[0]+1) * (indices[0] + 2)) / 2;
            ans += ((n - indices[indices.size() - 1]) * (n - indices[indices.size() - 1] + 1)) / 2;
            ans-=2;
        }
        else
        {
            ans += (n * (n + 1)) / 2;
        }
        cout << ans << endl;
    }
}
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

bool Primes[200002];
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "Primes[0..n]" and mark all entries as true, meaning all the numbers are initially considered Primess.

    memset(Primes, true, sizeof(Primes));

    // Start looking with the smallest Primes number, i.e., 2.

    for (int p = 2; p * p <= n; p++)
    {

        // If it is the next Primes, mark all its multiples as false, as they are composite and not Primes.
        if (Primes[p] == true)
        {

            for (int i = p * p; i <= n; i += p)
                Primes[i] = false;
        }
    }
}

int32_t main()
{

    fastio();

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    cin >> t;
    SieveOfEratosthenes(200001);
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> ans(n);

        ans[n / 2] = 1;

        int end = n - 1, start = 0;

        int num = 0;
        bool endd = true;
        for (int i = 2; i <= n; i++)
        {
            // cout << i << " " << Primes[i] << " " << end << " " << start << endd << endl;
            if (Primes[i])
            {
                if (endd)
                {
                    endd = false;
                    if (end != n / 2)
                    {
                        ans[end] = i;
                        end--;
                    }
                    else
                        i--;
                }
                else
                {
                    endd = true;
                    if (start != n / 2)
                    {
                        ans[start] = i;
                        start++;
                    }
                    else
                        i--;
                }
            }
        }
        for (int i = 2; i <= n; i++)
        {
            if (!Primes[i])
            {
                if (endd)
                {
                    endd = false;
                    if (end != n / 2)
                    {
                        ans[end] = i;
                        end--;
                    }
                    else
                        i--;
                }
                else
                {
                    endd = true;
                    if (start != n / 2)
                    {
                        ans[start] = i;
                        start++;
                    }
                    else
                        i--;
                }
            }
        }
        for (auto a : ans)
            cout << a << " ";
        cout << endl;
    }
}